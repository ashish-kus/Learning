/*
   An arithmetic array is an array that contains at least two integers and the
differences between consecutive integers are equal. For example, [9, 10], [3, 3,
3], and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and
[1, 2, 4] are not arithmetic arrays. Sarasvati has an array of N non-negative
integers. The i-th integer of the array is Ai . She wants to choose a contiguous
arithmetic subarray from her array that has the maximum length. Please help her
to determine the length of the longest contiguous arithmetic subarray.
*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << " Enter the size of array{r: ";
  cin >> size;
  int arr[size];

  cout << " Enter the elements of list" << endl;

  for (int i = 0; i < size; i++) {

    cin >> arr[i];
  }

  int ccd, pcd, tlen, clen;

  pcd = arr[1] - arr[0];
  clen = 2;
  tlen = 2;

  for (int i = 2; i < size; i++) {
    ccd = arr[i] - arr[i - 1];

    if (ccd == pcd) {
      clen++;
    }

    if (clen > tlen) {
      tlen = clen;
    }

    if (ccd != pcd) {
      pcd = ccd;
      clen = 2;
    }
  }

  cout << tlen;
  return 0;
}
