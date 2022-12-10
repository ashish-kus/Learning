/*
   In number theory, a narcissistic number (also known as a pluperfect
   digital invariant (PPDI),an Armstrong number (after Michael F.
   Armstrong) or a plus perfect number) in a given number base
   {\displaystyle b}b is a number that is the sum of its own digits each raised
   to the power of the number of digits.
   https://wikimedia.org/api/rest_v1/media/math/render/svg/7bfebf9c6f2983e62042bf994e617638432ded85
*/
#include <iostream>
using namespace std;
int main() {
  int num, onum, result = 0, reminder, power;
  cout << " Enter a number: ";
  cin >> onum;

  num = onum;

  while (num != 0) {
    reminder = num % 10;
    num = num / 10;
    result = result + (reminder * reminder * reminder);
  }

  if (result == onum) {
    cout << " its an Amstrong Number. ";
  }

  else {
    cout << onum << " is not a Amstrong Number.";
  }

  return 0;
}
