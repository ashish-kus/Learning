#include <iostream>
#include <stack>
using namespace std;

int main() {
  string sentenc = " HELLO this is ashihs! haha.";

  stack<string> st;
  for (int i = 0; i < sentenc.size(); i++) {
    string word = "";
    while (sentenc[i] != " " && i < sentenc.length()) {
      word += st[i];
      i++
    }
  }
  return 0;
}
