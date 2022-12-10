/* Isyana is given the number of visitors at her local theme park on N
consecutive days. The number of visitors on the i-th day is Vi

. A day is record breaking if it

satisfies both of the following conditions:
● The number of visitors on the day is strictly larger than the number of
visitors on each of the previous days.
● Either it is the last day, or the number of visitors on the day is strictly
larger than the number of visitors on the following day. Note that the very
first day could be a record breaking day!
*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << " Enter the number of days: ";
  cin >> size;
  int arr[size + 1];
  arr[size] = -1;
  cout << " Enter the number of visiters each day: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  int RB_days = 0, max = arr[0];
  for (int j = 1; j < size; j++) {
    if (arr[j] > max && arr[j] > arr[j + 1]) {
      RB_days++;
    }
    if (max < arr[j]) {
      max = arr[j];
    }
  }
  cout << " total number of record breaking days are : " << RB_days;

  return 0;
}
