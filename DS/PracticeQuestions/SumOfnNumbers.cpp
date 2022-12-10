/* We can add all the numbers from 1 to n using for loop but it is not that
   optimal so we will us a formula that we studied in sequence and series
   chapter, i.e if n is the number terms you want sum of then
          [ sum of n terms = (n*(n-1))/2 ]
*/

#include <iostream>
using namespace std;

int main() {
  int num;
  cout << " SUm up to";
  cin >> num;

  int total = (num * (num - 1)) / 2;
  cout << " Total : " << total;
  return 0;
}
