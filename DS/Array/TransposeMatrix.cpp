/* Give a matrix A, we have to return the transpose of that given matrix,
   w are doing by creating a new matrix ie 2-D array and then we are reading
   values from Matrix one and putting it into appropriate position in the 2nd
   array, we are doing this in O(n)
   There is anothetr approch for doing this, ie by swaping all the element of
   one side of the matrix that will reduce the time complexity by half
   [ O(n/2) )]
*/
#include <iostream>
using namespace std;

int main() {
  int size;
  cin >> size;

  int array[size][size];

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {
      cin >> array[i][j];
    }
  }

  cout << " MATRIX:" << endl;
  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {
      cout << array[i][j];
    }
    cout << endl;
  }
  cout << " Transpose calculating......." << endl;
  int array2[size][size];
  int i = 0, j = 0;
  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {
      array2[j][i] = array[i][j];
    }
  }

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {
      cout << array2[i][j] << " ";
    }
    cout << endl;
  }
}
