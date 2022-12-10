/* Return the sub array that have largest sum */
#include <climits>
#include <iostream>
using namespace std;

int main() {
  int size;
  cin >> size;
  int array[size];
  cout << "Array: " << endl;
  for (int i = 0; i < size; i++) {
    cout << i << ": ";
    cin >> array[i];
  }

  int start = 0;
  int end = size;
  int Max = 0;
  int sum = 0;
  for (int j = 0; j < size; j++) {
    sum = 0;
    for (int k = j; k < size; k++) {
      sum = sum + array[k];
      if (sum > Max) {
        Max = sum;
        start = j;
        end = k;
      }
    }
  }
  cout << " MAX :" << Max << endl;
  for (int l = start; l <= end; l++) {
    cout << array[l];
    cout << ", ";
  }

  return 0;
}
