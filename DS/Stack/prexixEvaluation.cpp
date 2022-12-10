#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class stack {
public:
  int size;
  int *array;
  int top;

  stack(int n) {
    size = n;
    array = new int[size];
    top = -1;
  }

  void push(int num) {
    if (top != size - 1) {
      top++;
      array[top] = num;
    }
  }
  int Top() {
    if (top != -1) {
      return array[top];
    }
  }

  int pop() {
    if (top != -1) {
      int temp = array[top];
      top--;
      return temp;
    }
  }

  void isempty() {
    if (top == -1) {
      cout << "TRUE";
    } else {
      cout << "FALSE";
    }
  }

  void isfull() {
    if (top == size - 1) {
      cout << "TRUE";
    } else {
      cout << "FALSE";
    }
  }

  void display() {
    for (int i = 0; i <= top; i++) {
      cout << array[i] << ", ";
    }
    cout << "NULL" << endl;
  }
};
int evaluate(string s) {
  stack st(100);
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] >= '0' && s[i] <= '9') {
      st.push(s[i] - '0');
    } else {
      int op1 = st.pop();
    }
  }
}
int main() {
  cout << "HELLO";
  return 0;
}
