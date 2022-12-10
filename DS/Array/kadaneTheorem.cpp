/*
   The simple idea of Kadane’s algorithm is to look for all positive contiguous
segments of the array (max_ending_here is used for this). And keep track of the
maximum sum contiguous segment among all positive segments (max_so_far is used
for this). Each time we get a positive-sum compare it with max_so_far and update
max_so_far if it is greater than max_so_far.

ALGORITHM

Initialize: max_so_far =
INT_MIN max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cin >> size;
  int array[size];
  cout << "Array: " << endl;
  for (int i = 0; i < size; i++) {
    cout << i << ": ";
    cin >> array[i];
  }
  int sum = 0;
  int maxsum = 0;
  for (int j = 0; j < size; j++) {
    sum = sum + array[j];
    if (sum > maxsum) {
      maxsum = sum;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  cout << maxsum;

  cout << sum;

  return 0;
}
