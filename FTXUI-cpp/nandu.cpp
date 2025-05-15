// file_browser.cpp - List all files and folders in the home directory using
// FTXUI

#include <algorithm>
#include <dirent.h>
#include <filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

using namespace ftxui;
namespace fs = std::filesystem;

std::vector<std::string> ListHomeDirectory() {
  std::vector<std::string> files;
  const char *home = getenv("HOME");
  if (!home)
    return files;

  for (const auto &entry : fs::directory_iterator(home)) {
    files.push_back(entry.path().filename().string());
  }
  std::sort(files.begin(), files.end());
  return files;
}

int selected_index = 0;

int main() {
  std::vector<std::string> files = ListHomeDirectory();

  auto screen = ScreenInteractive::Fullscreen();

  auto renderer = Renderer([&] {
    Elements rows;
    for (int i = 0; i < files.size(); ++i) {
      Element row = text(files[i]);
      if (i == selected_index)
        row = row | bgcolor(Color::Blue) | color(Color::White);
      rows.push_back(row);
    }

    return vbox({text("Files and Folders in $HOME") | bold | center,
                 separator(),
                 vbox(rows) | frame | size(HEIGHT, LESS_THAN, 30)}) |
           border;
  });

  auto app = CatchEvent(renderer, [&](Event e) {
    if (e == Event::ArrowDown && selected_index < (int)files.size() - 1) {
      selected_index++;
      return true;
    }
    if (e == Event::ArrowUp && selected_index > 0) {
      selected_index--;
      return true;
    }
    return false;
  });

  screen.Loop(app);
  return 0;
}
