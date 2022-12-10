/* Task is to return first repeating element:
   ex array = [1, 5, 3, 2, 5, 3, 3, 5, 1 ]
output: 1
*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << "SIZE:";
  cin >> size;
  int array[size];

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }

  return 0;
}
