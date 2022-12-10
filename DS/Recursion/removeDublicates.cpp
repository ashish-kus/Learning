#include <iostream>
#include <string>
using namespace std;
void remove(string str) {
  if (str.length() == 0) {
    return;
  }
  if (str[0] != str[1]) {
    cout << str[0];
    remove(str.substr(1));
  } else {
    remove(str.substr(1));
  }
}
int main() {
  string str = "aaaabbbbcccccdddddeee";

  remove(str);

  return 0;
}
