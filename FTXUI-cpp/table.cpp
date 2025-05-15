#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

// Define a structure for each row in the table
struct Unit {
  std::string pid;
  std::string name;
  std::string state;
  std::string enabled;
  std::string type;
  std::string target;
  std::string description;
};

int main() {
  // Table data
  std::vector<Unit> units = {
      {"1523", "sshd.service", "active", "enabled", "service", "System",
       "OpenSSH Daemon"},
      {"1352", "docker.service", "active", "enabled", "service", "System",
       "Docker Manager"},
      {"—", "apache2.service", "inactive", "disabled", "service", "System",
       "Apache HTTP Server"},
      {"2105", "bluetooth.service", "active", "disabled", "service", "System",
       "Bluetooth Stack"},
      {"—", "cups.service", "inactive", "disabled", "service", "System",
       "Printing Service"},
  };

  int selected = 0;
  Component input = CatchEvent( // handle key navigation
      Renderer([&] {
        std::vector<Element> rows;

        // Table Header
        rows.push_back(hbox({
                           text(" PID") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 6),
                           text(" NAME") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 18),
                           text(" STATE") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 8),
                           text(" ENABLED") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 9),
                           text(" TYPE") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 10),
                           text(" TARGET") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 9),
                           text(" DESCRIPTION") | bold |
                               size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
                       }) |
                       bgcolor(Color::GrayDark));

        // Table Rows
        for (size_t i = 0; i < units.size(); ++i) {
          auto &u = units[i];
          auto row = hbox({
              text(" " + u.pid) | size(ftxui::WIDTH, ftxui::GREATER_THAN, 6),
              text(" " + u.name) | size(ftxui::WIDTH, ftxui::GREATER_THAN, 18),
              text(" " + u.state) | size(ftxui::WIDTH, ftxui::GREATER_THAN, 8),
              text(" " + u.enabled) |
                  size(ftxui::WIDTH, ftxui::GREATER_THAN, 9),
              text(" " + u.type) | size(ftxui::WIDTH, ftxui::GREATER_THAN, 10),
              text(" " + u.target) | size(ftxui::WIDTH, ftxui::GREATER_THAN, 9),
              text(" " + u.description) |
                  size(ftxui::WIDTH, ftxui::GREATER_THAN, 20),
          });

          if (i == selected)
            row = row | inverted;

          rows.push_back(row);
        }

        return vbox({text("🚀 Systemd Units Table") | bold | center,
                     separator(), vbox(rows) | border | xflex, separator(),
                     text("Use ↑ ↓ to navigate. Selected: " +
                          units[selected].name) |
                         center}) |
               border | xflex;
      }),
      [&](Event event) {
        if (event == Event::ArrowDown)
          selected = (selected + 1) % units.size();
        else if (event == Event::ArrowUp)
          selected = (selected - 1 + units.size()) % units.size();
        else
          return false;
        return true;
      });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(input);
}
