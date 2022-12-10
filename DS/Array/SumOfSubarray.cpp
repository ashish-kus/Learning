#include <iostream>
using namespace std;

int main() {
  int sum = 0, size;
  cout << "Enter the size of array: ";
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  for (int j = 0; j < size; j++) {
    for (int k = j; k < size; k++) {
      sum = sum + arr[k];
    }
  }
  cout << sum;

  return 0;
}
