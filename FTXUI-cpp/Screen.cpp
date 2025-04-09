#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main(void) {
  using namespace ftxui;

  // Define the document
  Element ui = hbox({
      text("left") | border | flex,
      text("middle") | border | flex,
      text("right") | border | flex,
  });

  auto screen = Screen::Create(Dimension::Full(), // Width
                               Dimension::Fit(ui) // Height
  );
  Render(screen, ui);
  screen.Print();

  return EXIT_SUCCESS;
}
