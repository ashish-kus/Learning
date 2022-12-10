/* SUM OF ALL POSIBLE SUB ARRAY
   A subarray is commonly defined as a part or section of an array. An array is
   a set of variables that a programmer defines collectively. Instead of
   creating separate variables, the programmer can declare a single array with
   multiple values labeled.
*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cin >> size;
  int array[size];

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }

  int total = 0;
  for (int i = 0; i < size; i++) {
    int sum = 0;
    for (int j = i; j < size; j++) {
      sum = sum + array[j];
      total = total + sum;
    }
  }
  cout << total;
  return 0;
}
