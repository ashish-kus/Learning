#include <iostream>
using namespace std;
void moveall(string str) {
  if (str.length() == 0) {
    return;
  }
  if (str[0] == 'x') {
    moveall(str.substr(1));
    cout << 'x';
  } else {
    cout << str[0];
    moveall(str.substr(1));
  }
}
int main() {
  string str = "xxasxhxxisxxh";
  moveall(str);
  return 0;
}
