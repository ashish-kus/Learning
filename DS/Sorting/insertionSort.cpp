/* INSERTION SORT
   Insertion sort iterates, consuming one input element each repetition, and
   grows a sorted output list. At each iteration, insertion sort removes one
   element from the input data, finds the location it belongs within the sorted
   list, and inserts it there. It repeats until no input elements remain.Sorting
   is typically done in-place, by iterating up the array, growing the sorted
   list behind it. At each array-position, it checks the value there against the
   largest value in the sorted list (which happens to be next to it, in the
   previous array-position checked). If larger, it leaves the element in place
   and moves to the next. If smaller, it finds the correct position within the
   sorted list, shifts all the larger values up to make a space, and inserts
   into that correct position

ALGORITHM:
i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while

   */
#include <iostream>
using namespace std;
void InsertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int current = array[i];
    int j = i - 1;
    while (array[j] > current && j >= 0) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = current;
  }
};
int main() {
  int size;
  cout << "SIZE of array";
  cin >> size;
  int array[size];

  for (int i = 0; i < size; i++) {
    cout << "element at " << i << ":";
    cin >> array[i];
  }
  InsertionSort(array, size);
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }

  return 0;
}
