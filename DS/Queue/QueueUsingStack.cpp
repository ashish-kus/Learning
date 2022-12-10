/*
 Idea is to implement all properties of Queue using Stack data structure

#include <iostream>
using namespace std;

class stack {
  int size;
  int top;
  int *array;

public:
  stack(int value) {
    size = value;
    array = new int[size];
    top = -1;
  }

  int peek(int num) { return array[top]; }

  void insert(int value) {
    if (top < size - 1) {
      top++;
      array[top] = value;
    }
  }

  void pop() {
    if (top > -1) {
      cout << "POP: " << array[top];
      top--;
    }
  }

  void display() {
    for (int i = 0; i <= top; i++) {
      cout << array[i] << ", ";
    }
    cout << endl;
  }
};

class Queue : public stack {
  stack m;
};

int main() {

  Queue n(10);
  n.insert(1);
  n.insert(2);
  n.insert(3);
  n.insert(4);
  n.insert(5);
  n.insert(6);
  n.insert(7);
  n.insert(8);
  n.insert(9);
  n.display();
  return 0;
}
*/

#include <iostream>
#include <stack>
using namespace std;

class queue {
  stack<int> s1;
  stack<int> s2;

public:
  void push(int x) { s1.push(x); }
  int pop() {
    if (s1.empty() && s2.empty()) {
      cout << "Queue is empty";
      return -1;
    }
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int topval = s2.top();
    s2.pop();
    return topval;
  }
  bool empty() {
    if (s1.empty() && s2.empty()) {
      return true;
    } else
      return false;
  }
};

int main() {
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout << q.pop();
  cout << q.pop();
  cout << q.pop();

  return 0;
}
