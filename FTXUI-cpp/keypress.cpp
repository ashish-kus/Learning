#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::TerminalOutput();

  std::string log = "Press 'q' to quit, 'h' to say Hello.";

  auto component = CatchEvent(Renderer([&] {
                                return vbox({
                                    text(log),
                                });
                              }),
                              [&](Event event) {
                                if (event == Event::Character('h')) {
                                  log = "Hello from FTXUI!";
                                  return true;
                                }
                                if (event == Event::Character('q')) {
                                  screen.Exit();
                                  return true;
                                }
                                return false;
                              });

  screen.Loop(component);
  return 0;
}
