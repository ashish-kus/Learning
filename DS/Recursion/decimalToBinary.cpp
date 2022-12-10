#include <iostream>
using namespace std;
// void D2B(int num) {
//   if (num == 0) {
//     return;
//   }
//   if (num > 0) {
//     int result = num % 2;
//     D2B(num / 2);
//     cout << result << " ";
//   }
// }
string d2b(int num, string result) {
  if (num == 0) {
    return result;
  }
  int res = num % 2;
  result = result + to_string(res);
  return d2b(num / 2, result);
}
int main() {
  int num;
  cin >> num;
  string result = "";
  // D2B(num);
  string out = d2b(num, result);
  char chara = (num >= 0) ? '0' : '1';
  cout << endl << chara + out;
  return 0;
}
