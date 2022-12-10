/* You will be give an string and then a pattern to be replaced with another
pattern in our case we are gicen an string "pipxxpiiixppppix", what we have to
do in to replace all " pi " from the given string with 3.14.

Base Case: If the
string is empty: return “”; If s[0] == ‘p’ and s[1] == ‘i’ : print(“3.14”) else:
print(s[0])
Time Complexity: O(N2)
Space Complexity: O(N2)
FollowUp: Try to do this in O(N) time and space. Hint: Pass by reference and
indices.
*/
#include <iostream>
using namespace std;

void replace(string str) {
  if (str.length() == 0) {
    return;
  }
  if (str[0] == 'p' && str[1] == 'i') {
    cout << "3.14";
    replace(str.substr(2));
  } else {
    cout << str[0];
    replace(str.substr(1));
  }
}

int main() {
  string str = "pixxpxpxxxpiiipxpi";

  replace(str);
  return 0;
}
