/* BUBBLE SORT
   A bubble sort algorithm goes through a list of data a number of times,
   comparing two items that are side by side to see which is out of order. It
   will keep going through the list of data until all the data is sorted into
   order. Each time the algorithm goes through the list it is called a 'pass'.
  ALGORITHM
  We assume list is an array of n elements. We further assume that swap function
swaps the values of the given array elements.

begin BubbleSort(list)

   for all elements of list
      if list[i] > list[i+1]
         swap(list[i], list[i+1])
      end if
   end for

   return list

end BubbleSort
 */
#include <iostream>
using namespace std;
void BubbleSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}
int main() {
  int size;
  cin >> size;
  int array[size];

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
  BubbleSort(array, size);
  for (int j = 0; j < size; j++) {
    cout << array[j];
  }

  return 0;
}
