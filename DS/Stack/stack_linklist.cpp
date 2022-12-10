#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *next;

  node(int value) {
    data = value;
    next = NULL;
  }
};

void insert(node *&head, int value) {
  if (head == NULL) {
    head = new node(value);
    return;
  }
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(value);
}
int main() {

  cout << "ASHISH";
  return 0;
}
