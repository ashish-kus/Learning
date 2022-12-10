/* Here we will be provided with intigers from 0 to 9 as we have in out
 * traditional keypad mobile phones, now we have to generate all possible
 * strings that can be possible when one charecter is chosen for each set
 * associated to that number in given order */

#include <iostream>
#include <string>
using namespace std;

void numToWord(int num) {
  string words[10] = {"",    "./",  "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
}

int main() {
  int num = 3;
  string words[10] = {"",    "./",  "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
  numToWord(num);
  return 0;
}
