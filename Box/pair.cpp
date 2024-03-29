#include <iostream>
#include <vector>

using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first;
}
int main() {
  int array[] = {10, 16, 7, 14, 5, 3, 2, 9};
  vector<pair<int, int>> v;

  for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
    v.push_back(make_pair(array[i], i));
  }

  sort(v.begin(), v.end(), myCompare);
  return 0;
}
