#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::TerminalOutput();
  std::vector<std::vector<std::string>> table = {
      {"ID", "Name", "Role"},    {"1", "Alice", "Engineer"},
      {"2", "Bob", "Designer"},  {"3", "Charlie", "Manager"},
      {"4", "Diana", "Analyst"},
  };
  int selected = 1; // Skip header
                    //
  Component ui = Renderer([&] {
                   Elements rows;
                   for (size_t i = 0; i < table.size(); ++i) {
                     auto row =
                         hbox({text(table[i][0]) | size(WIDTH, EQUAL, 8),
                               text(table[i][1]) | size(WIDTH, EQUAL, 12),
                               text(table[i][2]) | size(WIDTH, EQUAL, 12)});

                     if (i == 0)
                       row = row | bold; // Header
                     else if (i == selected)
                       row = row | inverted; // Selected row
                     rows.push_back(row | border);
                   }
                   return vbox(rows);
                 }) |
                 CatchEvent([&](Event e) {
                   if (e == Event::ArrowUp && selected > 1)
                     selected--;
                   if (e == Event::ArrowDown && selected + 1 < table.size())
                     selected++;
                   if (e == Event::Return)
                     std::cout << "Selected: " << table[selected][1] << " - "
                               << table[selected][2] << std::endl;
                   return false;
                 });
  screen.Loop(ui);
}
