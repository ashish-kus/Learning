#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace ftxui;

class FilteredMenu {
public:
  std::vector<std::string> all_entries;
  std::vector<std::string> filtered_entries;
  std::string filter;
  int selected = 0;

  // Create components
  Component input = Input(&filter, "Filter");
  Component menu = Menu(&filtered_entries, &selected);

  FilteredMenu(const std::vector<std::string> &entries) : all_entries(entries) {
    UpdateFilter();

    // Update filtered list when input changes
    input |= CatchEvent([this](Event) {
      UpdateFilter();
      return false;
    });
  }

  void UpdateFilter() {
    filtered_entries.clear();
    std::copy_if(all_entries.begin(), all_entries.end(),
                 std::back_inserter(filtered_entries),
                 [this](const std::string &entry) {
                   // Case-insensitive search
                   std::string lower_entry = entry;
                   std::string lower_filter = filter;
                   std::transform(lower_entry.begin(), lower_entry.end(),
                                  lower_entry.begin(), ::tolower);
                   std::transform(lower_filter.begin(), lower_filter.end(),
                                  lower_filter.begin(), ::tolower);
                   return lower_entry.find(lower_filter) != std::string::npos;
                 });
    if (selected >= filtered_entries.size()) {
      selected = std::max(0, (int)filtered_entries.size() - 1);
    }
  }

  Component Render() { return Container::Vertical({input, menu}); }
};

int main() {
  std::vector<std::string> entries = {
      "Apple", "Banana",   "Cherry",          "Date",     "Elderberry", "Fig",
      "Grape", "Honeydew", "Iceberg Lettuce", "Jackfruit"};

  // Create filtered menu
  auto filtered_menu = std::make_shared<FilteredMenu>(entries);

  // Main renderer
  auto renderer = Renderer(filtered_menu->Render(), [&] {
    return vbox(
               {text("Searchable Menu") | bold | center, separator(),
                filtered_menu->input->Render(), separator(),
                filtered_menu->menu->Render() | frame | vscroll_indicator |
                    flex,
                separator(),
                text(
                    "Selected: " +
                    (filtered_menu->filtered_entries.empty()
                         ? "None"
                         : filtered_menu
                               ->filtered_entries[filtered_menu->selected]))}) |
           border;
  });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
