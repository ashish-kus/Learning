/* Euclidean Algorithm for Greatest Common Divisor (GCD)

The Euclidean Algorithm finds the GCD of 2 numbers.

You will better understand this Algorithm by seeing it in action. Assuming you
want to calculate the GCD of 1220 and 516, lets apply the Euclidean Algorithm-

Assuming you want to calculate the GCD of 1220 and 516, lets apply the Euclidean
Algorithm-

Pseudo Code of the Algorithm-
Step 1:  Let  a, b  be the two numbers
Step 2:  a mod b = R
Step 3:  Let  a = b  and  b = R
Step 4:  Repeat Steps 2 and 3 until  a mod b  is greater than 0
Step 5:  GCD = b
Step 6: Finish
*/

#include <iostream>
using namespace std;
int gcd_mod(int num1, int num2) {
  int Max = (num1 > num2) ? num1 : num2;
  int Min = (Max == num1) ? num2 : num1;
  int temp = Max % Min;
  if (temp == 0) {
    return Min;
  }
  return gcd_mod(Max, temp);
}

int gcd(int num1, int num2) {
  int Max = (num1 > num2) ? num1 : num2;
  int Min = (Max == num1) ? num2 : num1;
  int temp = Max - Min;
  if (temp == 0) {
    return Min;
  }
  return gcd(Min, temp);
}

int main() {
  int num1, num2;
  cout << "number 1: ";
  cin >> num1;
  cout << "number 2: ";
  cin >> num2;
  cout << gcd(num1, num2) << endl;

  cout << gcd_mod(num1, num2) << endl;

  return 0;
}
