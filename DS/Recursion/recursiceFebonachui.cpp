
#include <iostream>
using namespace std;

int febonachi(int n) {
  return (n == 1)             ? 0
         : (n == 2 || n == 3) ? 1
                              : febonachi(n - 1) + febonachi(n - 2);
}

int main() {
  int num;
  cout << "NUMBER OF TERMS: ";
  cin >> num;

  cout << febonachi(num) << endl;

  return 0;
}
