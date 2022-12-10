#include <iostream>
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
  int pop() {
    if (top != -1) {
      int temp = array[top];
      top--;
      return temp;
    }
    return -1;
  }

  void attop() {
    if (top != -1) {
      cout << "TOP: " << array[top];
    }
  }

  bool isempty() {
    if (top == -1) {
      return true;
    } else {
      return false;
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
  int Size() { return top; }
};

void reverce(stack &b) {
  if (b.isempty() == true) {
    return;
  }
  int element = b.pop();
  reverce(b);
  b.push(element);
}
int main() {
  stack a(6);
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);

  reverce(a);

  a.display();
  return 0;
}
