#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include <algorithm>
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
RenderDetailsComponent(const std::map<std::string, std::string> &details) {
  std::vector<Element> lines;
  for (const auto &[key, value] : details) {
    lines.push_back(hbox({text(key + ": ") | bold, text(value)}));
  }
  return Renderer(
      [=] { return vbox(lines) | border | size(HEIGHT, LESS_THAN, 10); });
}

// ---------------------------------------------
// SERVICE MANAGEMENT
// ---------------------------------------------

bool ExecuteServiceAction(const std::string &unit_name,
                          const std::string &action) {
  std::string cmd = "systemctl " + action + " " + unit_name;
  int result = system(cmd.c_str());
  return result == 0;
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
  while (fgets(buffer, sizeof(buffer), pipe)) {
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
// CONFIRMATION DIALOG
// ---------------------------------------------

class ConfirmationDialog {
public:
  bool show = false;
  bool confirmed = false;
  std::string message;
  std::string unit_name;
  std::string action;
  std::function<void()> on_confirm;
  std::function<void()> on_cancel;

  Component Render() {
    auto button_yes = Button("Yes", [&] {
      confirmed = true;
      show = false;
      if (on_confirm)
        on_confirm();
    });

    auto button_no = Button("No", [&] {
      confirmed = false;
      show = false;
      if (on_cancel)
        on_cancel();
    });

    auto buttons = Container::Horizontal({button_yes, button_no});

    return Renderer(buttons, [&, buttons] {
      if (!show)
        return text("") | nothing;

      return vbox({
                 text(message) | bold | center,
                 separator(),
                 hbox({text("Are you sure? "), buttons->Render()}),
             }) |
             border | center;
    });
  }

  void Show(const std::string &unit, const std::string &act,
            std::function<void()> confirm_cb,
            std::function<void()> cancel_cb = nullptr) {
    unit_name = unit;
    action = act;
    message = "Action: " + action + " " + unit_name;
    on_confirm = confirm_cb;
    on_cancel = cancel_cb;
    show = true;
  }
};

// ---------------------------------------------
// STATUS MESSAGE
// ---------------------------------------------

class StatusMessage {
public:
  bool show = false;
  std::string message;
  bool success = false;
  int countdown = 50; // Frames to display

  Component Render() {
    return Renderer([&] {
      if (!show || countdown <= 0)
        return text("") | nothing;

      countdown--;
      if (countdown <= 0)
        show = false;

      return text(message) | border |
             bgcolor(success ? Color::Green : Color::Red) |
             color(Color::White) | center;
    });
  }

  void Show(const std::string &msg, bool is_success) {
    message = msg;
    success = is_success;
    countdown = 50;
    show = true;
  }
};

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
  bool show_logs = false;
  std::vector<std::string> current_logs;

  Component input = Input(&filter, "Filter");
  Component menu = Menu(&filtered_entries, &selected);
  Component details_box;
  Component logs_box;

  std::shared_ptr<ConfirmationDialog> confirmation_dialog =
      std::make_shared<ConfirmationDialog>();
  std::shared_ptr<StatusMessage> status_message =
      std::make_shared<StatusMessage>();

  std::shared_ptr<ScreenInteractive> screen;

  FilteredMenu(const std::vector<std::string> &entries,
               const std::vector<Unit> &units)
      : all_entries(entries), units(units) {
    UpdateFilter();

    input |= CatchEvent([this](Event) {
      UpdateFilter();
      return false;
    });

    menu |= CatchEvent([this](Event event) {
      if (event.is_mouse())
        return false;

      // Get current selected unit
      Unit *current_unit = GetSelectedUnit();
      if (!current_unit)
        return false;

      // Handle service action hotkeys
      if (event == Event::Character('s') || event == Event::Character('S')) {
        ShowConfirmation(current_unit->name, "start");
        return true;
      } else if (event == Event::Character('t') ||
                 event == Event::Character('T')) {
        ShowConfirmation(current_unit->name, "stop");
        return true;
      } else if (event == Event::Character('r') ||
                 event == Event::Character('R')) {
        ShowConfirmation(current_unit->name, "restart");
        return true;
      } else if (event == Event::Character('e') ||
                 event == Event::Character('E')) {
        ShowConfirmation(current_unit->name, "enable");
        return true;
      } else if (event == Event::Character('d') ||
                 event == Event::Character('D')) {
        ShowConfirmation(current_unit->name, "disable");
        return true;
      } else if (event == Event::Character('l') ||
                 event == Event::Character('L')) {
        ToggleLogs();
        return true;
      }

      UpdateDetails();
      return false;
    });

    UpdateDetails();
    UpdateLogs();
  }

  void SetScreen(std::shared_ptr<ScreenInteractive> s) { screen = s; }

  void RefreshData() {
    auto raw_lines = GetRawUnitLines();
    units = ParseUnits(raw_lines);
    all_entries = formatEntries(units);
    UpdateFilter();
    UpdateDetails();
  }

  void ShowConfirmation(const std::string &unit_name,
                        const std::string &action) {
    confirmation_dialog->Show(unit_name, action, [this, unit_name, action]() {
      ExecuteAction(unit_name, action);
    });
  }

  void ExecuteAction(const std::string &unit_name, const std::string &action) {
    bool success = ExecuteServiceAction(unit_name, action);
    std::string message =
        action + " " + unit_name + ": " + (success ? "Success" : "Failed");
    status_message->Show(message, success);

    // Refresh data after action
    if (success) {
      RefreshData();
    }
  }

  void ToggleLogs() {
    show_logs = !show_logs;
    if (show_logs) {
      UpdateLogs();
    }
  }

  void UpdateLogs() {
    Unit *unit = GetSelectedUnit();
    if (unit) {
      current_logs = GetUnitLogs(unit->name, 10);

      logs_box = Renderer([this] {
        std::vector<Element> log_elements;
        for (const auto &log : current_logs) {
          log_elements.push_back(text(log));
        }

        if (log_elements.empty()) {
          log_elements.push_back(text("No logs available") | dim);
        }

        return vbox(log_elements);
      });
    } else {
      logs_box = Renderer([] { return text("No unit selected") | center; });
    }
  }

  Unit *GetSelectedUnit() {
    // Return nullptr for header or invalid selection
    if (selected <= 0 || selected - 1 >= (int)units.size()) {
      return nullptr;
    }
    return &units[selected - 1];
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
    UpdateDetails();
  }

  void UpdateDetails() {
    if (selected > 0 && selected - 1 < (int)units.size()) {
      auto unit = units[selected - 1];
      auto details = GetUnitDetails(unit.name);
      details_box = RenderDetailsComponent(details);
      UpdateLogs();
    } else {
      details_box = Renderer([] { return text("No unit selected") | center; });
    }
  }

  Component Render() {
    auto main_component =
        Container::Vertical({input, menu, details_box, Renderer([this] {
                               if (!show_logs)
                                 return text("") | nothing;

                               return vbox({text("Logs:") | bold,
                                            logs_box->Render() | yframe |
                                                size(HEIGHT, LESS_THAN, 10)}) |
                                      border;
                             })});

    // Use Layer instead of Tab since we don't need a selector
    return Container::Vertical({
        main_component,
        confirmation_dialog->Render(),
        status_message->Render(),
    });
  }

  Element RenderHelp() {
    return vbox({
               text("Keyboard Shortcuts:") | bold,
               text("s - Start service"),
               text("t - Stop service"),
               text("r - Restart service"),
               text("e - Enable service"),
               text("d - Disable service"),
               text("l - Toggle logs view"),
           }) |
           border;
  }
};

// ---------------------------------------------
// MAIN
// ---------------------------------------------

int main() {
  auto screen =
      std::make_shared<ScreenInteractive>(ScreenInteractive::TerminalOutput());
  auto units = ParseUnits(GetRawUnitLines());
  auto entries = formatEntries(units);

  auto filtered_menu = std::make_shared<FilteredMenu>(entries, units);
  filtered_menu->SetScreen(screen);

  auto renderer = Renderer(filtered_menu->Render(), [&] {
    return vbox({text("Systemd Units Manager") | bold | center, separator(),
                 filtered_menu->input->Render(), separator(),
                 hbox({
                     vbox({
                         filtered_menu->menu->Render() | frame |
                             vscroll_indicator | size(HEIGHT, LESS_THAN, 12) |
                             flex,
                     }) | flex,
                     filtered_menu->RenderHelp() | size(WIDTH, LESS_THAN, 30),
                 }),
                 filtered_menu->details_box->Render()}) |
           border;
  });

  screen->Loop(renderer);
}
