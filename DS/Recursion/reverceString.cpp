#include <iostream>
#include <string>
using namespace std;

void reverce(string word) {
  if (word.length() == 0) {
    return;
  }
  string rest = word.substr(1);
  reverce(rest);
  cout << word[0];
}

int main() {
  string word = "nandu";

  reverce(word);
  return 0;
}
