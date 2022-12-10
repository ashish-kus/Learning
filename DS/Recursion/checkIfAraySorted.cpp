#include <iostream>
using namespace std;

bool check(int array[], int size) {

  if (size == 1) {
    return true;
  }
  if (array[0] <= array[1]) {
    return check(array + 1, size - 1);
  }
  return false;
}

int main() {
  int array[] = {2, 3, 9, 5, 6, 7, 8};
  cout << check(array, 7);
  return 0;
}
