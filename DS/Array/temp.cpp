#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  char arr[n + 1];

  cin.getline(arr, n);
  cin.ignore();

  int i = 0;
  int clen = 0, mlen = 0;

  while (1) {
    if (arr[i] == ' ' || arr[i] == '\0') {
      if (clen > mlen) {
        mlen = clen;
      }
      clen = 0;
    }
    clen++;
    if (arr[i] == '\0') {
      break;
    }
    i++;
  }
  cout << "MAX: " << mlen;
  return 0;
}
