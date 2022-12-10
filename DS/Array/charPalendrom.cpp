/* Palendrom is a pattern that is equal to its reverse, or if printed backword.
 */
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Size";
  cin >> n;
  char name[n + 1];
  cin >> name;
  bool check = false;

  for (int i = 0; i < n; i++) {
    cout << name[i] << ": " << i << endl;
    if (name[i] == name[n - i - 1]) {
      check = true;
    } else {
      check = false;
    }
  }
  if (check) {
    cout << "TRUE";
  } else {
    cout << "NO";
  }
  return 0;
}
