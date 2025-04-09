#include <ftxui/screen/screen.hpp>
#include <iostream>

int main(void) {
  using namespace ftxui;
  Element document = vbox({text("The window") | bold | color(Color::Blue),
                           gauge(0.5) text("The footer")});
  document = border(document);
  document = document | border.document |= border
}
