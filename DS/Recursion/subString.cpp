#include <iostream>
using namespace std;

void substring(string str, string ans) {
  if (str.length() == 0) {
    return;
  }
  ans = ans + str[0];
  cout << ans << ", ";
  substring(str.substr(1), ans);
  substring(str.substr(1), "");
}
int main() {
  string str = "ABC";
  string ans = "";
  substring(str, ans);

  return 0;
}
