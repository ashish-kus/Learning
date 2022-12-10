#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "Number :";

  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++) {
    arr[i] = 1;
  }
  int i = 2;
  while (i * i < num) {
    cout << "Hello" << endl;
    for (int j = i; j < num; j = j + i) {
      arr[j] = -1;
    }
    i++;
  }
  for (int i = 0; i < num; i++) {
    if (arr[i] == 1) {
      cout << i << ", ";
    }
  }
  return 0;
}
