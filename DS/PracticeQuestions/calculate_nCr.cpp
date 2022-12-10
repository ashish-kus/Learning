/*
   Combination: nCr represents the selection of objects from a group of objects
   where order of objects does not matter. nCr = n!/[r!*(n-r)!] Where n is the
   total number of objects and r is the number of selected objects.
*/
#include <iostream>
using namespace std;

int factorial(int num) {
  if (num <= 1)
    return 1;
  else
    return num * factorial(num - 1);
}

int main() {
  int n, r, value;
  cout << " ENter the value for n: ";
  cin >> n;

  cout << " Enter the value for r ";
  cin >> r;

  value = factorial(n) / (factorial(n - r) * factorial(r));
  cout << "the value is" << value;

  return 0;
}
