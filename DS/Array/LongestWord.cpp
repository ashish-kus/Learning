
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << "SIZE :";
  cin >> size;
  cin.ignore();

  char array[size];

  cin.getline(array, size);
  cin.ignore();

  int i = 0;
  int clen = 0, Max = 0;

  while (1) {

    if (array[i] == ' ' || array[i] == '\0') {
      if (Max < clen) {
        Max = clen;
      }
      clen = 0;
    }

    if (array[i] == '\0') {
      break;
    }

    clen++;
    i++;
  }

  cout << endl << " max length   :" << Max;
  return 0;
}
