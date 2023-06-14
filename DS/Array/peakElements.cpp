#include <iostream>
using namespace std;

void findPeak(int array[], int n) {
  int rarray[n];
  if (n == 0) {
    return;
  }
  if (n == 1) {
    cout << array[0];
  }
  if (array[n - 1] >= array[n - 2]) {
    cout << array[n - 1];
  }

  for (int i = 0; i < n - 1; i++) {
    if (array[i] >= array[i - 1] && array[i] >= array[i + 1]) {
      cout << array[i];
    }
  }
}

int main() {
  int arr[] = {1, 3, 20, 4, 1, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Index of a peak point is " << endl;
  findPeak(arr, n);
  return 0;
}
