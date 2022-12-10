#include <iostream>
using namespace std;

void permutation(string str, string ans) {
  if (str.length() == 0) {
    cout << ans << endl;
    return;
  }
  char first = str[0];
  permutation(str.substr(1), ans);
  permutation(str.substr(1), ans + first);
}

int main() {
  string str = "ABC";
  string ans = "";
  permutation(str, ans);
  return 0;
}
