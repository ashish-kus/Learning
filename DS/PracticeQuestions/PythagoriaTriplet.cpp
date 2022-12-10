/*pythagorus triplet  ⊿
  Pythagorean triples are a^2+b^2 = c^2 where a, b and c are the three positive
  integers. These triples are represented as (a,b,c). Here, a is the
  perpendicular, b is the base and c is the hypotenuse of the right-angled
  triangle. The most known and smallest triplets are (3,4,5).
*/

#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int x, y, z;
  bool check;
  // max function compare 2  numbers and return tha greatest one.
  x = max(a, max(b, c));

  if (x == a) {
    y = b;
    z = c;
  }
  if (x == b) {
    y = a;
    z = c;
  }

  if (x == c) {
    y = a;
    z = b;
  }

  if (x * x == (y * y) + (z * z)) {
    cout << "pythagorus triplet" << endl;
  } else {
    cout << " NO its NOt";
  }

  return 0;
}
