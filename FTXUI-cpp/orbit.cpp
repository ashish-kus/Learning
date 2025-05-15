#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace ftxui;

// ---------------------------------------------
// UNIT CLASS
// ---------------------------------------------

class Unit {
public:
  std::string name;
  std::string load;
  std::string active;
  std::string sub;
  std::string type;
  std::string description;

  Unit(std::string name, std::string load, std::string active, std::string sub,
       std::string desc)
      : name(name), load(load), active(active), sub(sub), description(desc) {
    size_t dot_pos = name.rfind('.');
    type =
        (dot_pos != std::string::npos) ? name.substr(dot_pos + 1) : "unknown";
  }
};

// ---------------------------------------------
// SYSTEMD HELPERS
// ---------------------------------------------

std::vector<std::string> GetRawUnitLines() {
  std::vector<std::string> lines;
  FILE *pipe = popen("systemctl list-units --all --no-pager --no-legend", "r");
  if (!pipe)
    return lines;
  char buffer[512];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    lines.push_back(std::string(buffer));
  }
  pclose(pipe);
  return lines;
}

std::vector<Unit> ParseUnits(const std::vector<std::string> &lines) {
  std::vector<Unit> units;
  for (const auto &line : lines) {
    std::istringstream iss(line);
    std::string name, load, active, sub, description;
    if (!(iss >> name >> load >> active >> sub))
      continue;
    std::getline(iss, description);
    description.erase(0, description.find_first_not_of(" \t"));
    units.emplace_back(name, load, active, sub, description);
  }
  return units;
}

std::map<std::string, std::string>
GetUnitDetails(const std::string &unit_name) {
  std::map<std::string, std::string> details;
  std::string cmd = "systemctl show " + unit_name;
  FILE *pipe = popen(cmd.c_str(), "r");
  if (!pipe)
    return details;

  char buffer[512];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    std::string line(buffer);
    size_t eq_pos = line.find('=');
    if (eq_pos != std::string::npos) {
      std::string key = line.substr(0, eq_pos);
      std::string value = line.substr(eq_pos + 1);
      value.erase(value.find_last_not_of("\n\r") + 1);
      details[key] = value;
    }
  }
  pclose(pipe);
  return details;
}

Component
CreateDetailsComponent(const std::map<std::string, std::string> &details) {
  std::vector<Element> lines;
  for (const auto &[key, value] : details) {
    lines.push_back(hbox({text(key + ": ") | bold, text(value)}));
  }
  return Renderer(
      [=] { return vbox(lines) | border | size(HEIGHT, LESS_THAN, 10); });
}

// ---------------------------------------------
// LOGS COMPONENT
// ---------------------------------------------

Component CreateLogsComponent(const std::vector<std::string> &logs) {
  return Renderer([=] {
    std::vector<Element> log_lines;
    for (const auto &log : logs) {
      log_lines.push_back(text(log));
    }
    return window(text("Logs"), vbox(log_lines) | frame | vscroll_indicator |
                                    size(HEIGHT, LESS_THAN, 10));
  });
}

std::vector<std::string> GetUnitLogs(const std::string &unit_name,
                                     int count = 10) {
  std::vector<std::string> logs;
  std::string cmd = "journalctl -u " + unit_name + " -n " +
                    std::to_string(count) + " --no-pager";
  FILE *pipe = popen(cmd.c_str(), "r");
  if (!pipe)
    return logs;

  char buffer[512];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
    logs.emplace_back(buffer);
  }
  pclose(pipe);
  return logs;
}

// ---------------------------------------------
// FORMATTING
// ---------------------------------------------

std::vector<std::string> formatEntries(const std::vector<Unit> &units) {
  std::vector<std::string> entries;

  int total_width = Terminal::Size().dimx;
  int name_w = total_width * 28 / 100;
  int type_w = total_width * 10 / 100;
  int load_w = total_width * 10 / 100;
  int active_w = total_width * 10 / 100;
  int sub_w = total_width * 10 / 100;
  int desc_w = total_width - (name_w + type_w + load_w + active_w + sub_w);

  auto truncate = [](const std::string &s, int width) {
    if ((int)s.length() <= width)
      return s + std::string(width - s.length(), ' ');
    return s.substr(0, width - 1) + "…";
  };

  auto padded_name = [&](const std::string &s) {
    return "   " + truncate(s, name_w - 3);
  };

  auto no_padding = [&](const std::string &s, int width) {
    return truncate(s, width);
  };

  entries.push_back(padded_name("NAME") + no_padding("TYPE", type_w) +
                    no_padding("LOAD", load_w) +
                    no_padding("ACTIVE", active_w) + no_padding("SUB", sub_w) +
                    truncate("DESCRIPTION", desc_w));

  for (const auto &u : units) {
    if (u.type == "service") {
      std::string entry =
          padded_name(u.name) + no_padding(u.type, type_w) +
          no_padding(u.load, load_w) + no_padding(u.active, active_w) +
          no_padding(u.sub, sub_w) + truncate(u.description, desc_w);
      entries.push_back(entry);
    }
  }

  return entries;
}

// ---------------------------------------------
// FILTERED MENU CLASS
// ---------------------------------------------

class FilteredMenu {
public:
  std::vector<std::string> all_entries;
  std::vector<std::string> filtered_entries;
  std::vector<Unit> units;
  std::string filter;
  int selected = 0;

  Component input = Input(&filter, "Filter");
  Component menu = Menu(&filtered_entries, &selected);
  Component details_box;
  Component logs_box;

  FilteredMenu(const std::vector<std::string> &entries,
               const std::vector<Unit> &units)
      : all_entries(entries), units(units) {
    UpdateFilter();

    input |= CatchEvent([this](Event) {
      UpdateFilter();
      return false;
    });

    menu |= CatchEvent([this](Event) {
      UpdateDetailsAndLogs();
      return false;
    });

    UpdateDetailsAndLogs();
  }

  void UpdateFilter() {
    filtered_entries.clear();
    std::copy_if(all_entries.begin(), all_entries.end(),
                 std::back_inserter(filtered_entries),
                 [this](const std::string &entry) {
                   std::string lower_entry = entry;
                   std::string lower_filter = filter;
                   std::transform(lower_entry.begin(), lower_entry.end(),
                                  lower_entry.begin(), ::tolower);
                   std::transform(lower_filter.begin(), lower_filter.end(),
                                  lower_filter.begin(), ::tolower);
                   return lower_entry.find(lower_filter) != std::string::npos;
                 });
    if (selected >= (int)filtered_entries.size()) {
      selected = std::max(0, (int)filtered_entries.size() - 1);
    }
    UpdateDetailsAndLogs();
  }

  void UpdateDetailsAndLogs() {
    if (selected > 0 && selected - 1 < (int)units.size()) {
      auto unit = units[selected - 1];
      auto details = GetUnitDetails(unit.name);
      details_box = CreateDetailsComponent(details);

      auto logs = GetUnitLogs(unit.name);
      logs_box = CreateLogsComponent(logs);
    } else {
      details_box = Renderer([] { return text("No unit selected") | center; });
      logs_box = Renderer([] { return text("No logs available") | center; });
    }
  }

  Component Render() {
    return Container::Vertical({input, menu, details_box, logs_box});
  }
};

// ---------------------------------------------
// MAIN
// ---------------------------------------------

int main() {
  auto units = ParseUnits(GetRawUnitLines());
  auto entries = formatEntries(units);

  auto filtered_menu = std::make_shared<FilteredMenu>(entries, units);

  auto renderer = Renderer(filtered_menu->Render(), [&] {
    return vbox({text("Systemd Units Viewer") | bold | center, separator(),
                 filtered_menu->input->Render(), separator(),
                 filtered_menu->menu->Render() | frame | vscroll_indicator |
                     size(HEIGHT, LESS_THAN, 12) | border,
                 separator(), filtered_menu->details_box->Render(),
                 filtered_menu->logs_box->Render()}) |
           border;
  });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
