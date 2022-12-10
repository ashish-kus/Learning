/*
   Pascal's triangle is the triangular array of numbers that begins with 1 on
   the top and with 1's running down the two sides of a triangle. Each new
   number lies between two numbers and below them, and its value is the sum of
   the two numbers above it.
*/
#include <iostream>
using namespace std;

int facto(int num) {
  if (num <= 1)
    return 1;
  else
    return num * facto(num - 1);
}

int ncr(int n, int r) {
  int result = (facto(n) / (facto(n - r) * facto(r)));
  return result;
}

int main() {

  int n, r;
  cin >> n >> r;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << ncr(i, j) << "   ";
    }
    cout << endl;
  }

  return 0;
}
