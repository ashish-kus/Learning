#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();
  auto element = text("Hello, FTXUI!") | bold | border;
  screen.Loop(Renderer([&] { return element; }));
}
