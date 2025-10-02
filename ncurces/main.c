#include <ncurses.h>

int main(void) {
  initscr(); // Start curses mode
  printw(
      "Hello from ncurses on Arch Linux! Press any key to exit..."); // Print a
                                                                     // message
  refresh(); // Update the screen
  getch();   // Wait for user input
  endwin();  // End curses mode
  return 0;
}
