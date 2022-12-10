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

  void pop() {
    if (top != -1) {
      cout << "POPED: " << array[top] << endl;
      top--;
    }
  }

  void attop() {
    if (top != -1) {
      cout << "TOP: " << array[top];
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
int main() {

  stack a(6);
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  a.push(6);
  a.display();
  a.attop();
  a.isfull();
  a.isempty();
  return 0;
}
