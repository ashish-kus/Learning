#include <iostream>
using namespace std;
int getbit(int num, int position) { return ((num & (1 << position)) != 0); }
int main() {
  int i = 0;
  cout << getbit(5, 2);
  return 0;
}
