// setbit, clearbit,

#include <iostream>
using namespace std;
int setbit(int num, int position) {
  //
  return ((num | (1 << position)) != 0);
}

int clearbit(int num, int position) {
  int mask = ~(1 << position);
  return (num & mask);
}

int updatebit(int num, int position, int uvalue) {
  int mask = ~(1 << pos);
  num = num & mask;
}
int main() {
  int i = 0;
  cout << setbit(5, 1);
  return 0;
}
