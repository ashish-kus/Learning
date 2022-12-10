#include <iostream>
using namespace std;

class queue {
  int *array;
  int front;
  int back;
  int size;

public:
  queue(int value) {
    size = value;
    array = new int[size];
    front = -1;
    back = -1;
  }

  void enqueue(int value) {
    if (back == -1) {
      back++;
      array[back] = value;
      front++;
    } else if (back < size - 1) {
      back++;
      array[back] = value;
    } else {
      cout << "ERROR";
    }
  }

  void dequeue() { front++; }
  void display() {
    for (int i = front; i <= back; i++) {
      cout << array[i] << ", ";
    }
    cout << "null" << endl;
  }

  int peek() { return array[front]; }
};

int main() {
  queue Q(10);
  Q.enqueue(1);
  Q.enqueue(1);
  Q.enqueue(3);
  Q.dequeue();
  Q.display();
  return 0;
}
