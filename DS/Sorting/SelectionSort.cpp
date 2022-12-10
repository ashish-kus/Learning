/*
SELECTION SORT
    In selection sort, the first smallest element is selected from the unsorted
   array and placed at the first position. After that second smallest element is
   selected and placed in the second position. The process continues until the
   array is entirely sorted.
ALGORITHM:
  SELECTION SORT(arr, n)

Step 1: Repeat Steps 2 and 3 for i = 0 to n-1
Step 2: CALL SMALLEST(arr, i, n, pos)
Step 3: SWAP arr[i] with arr[pos]
[END OF LOOP]
Step 4: EXIT

SMALLEST (arr, i, n, pos)
Step 1: [INITIALIZE] SET SMALL = arr[i]
Step 2: [INITIALIZE] SET pos = i
Step 3: Repeat for j = i+1 to n
if (SMALL > arr[j])
     SET SMALL = arr[j]
SET pos = j
[END OF if]
[END OF LOOP]
Step 4: RETURN pos

 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void selectionsort(int array[], int size) {
  int min = INT_MAX;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

int main() {
  int size;
  cout << "SIZE of array";
  cin >> size;
  int array[size];

  for (int i = 0; i < size; i++) {
    cout << "element at " << i << ":";
    cin >> array[i];
  }
  selectionsort(array, size);
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  return 0;
}
