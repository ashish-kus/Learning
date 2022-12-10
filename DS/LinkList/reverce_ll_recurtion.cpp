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

void insertEnd(node *&head, int value) {
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

void display(node *head) {
  if (head == NULL) {
    return;
  }
  while (head != NULL) {
    cout << head->data << ", ";
    head = head->next;
  }
  cout << endl;
}

node *reverce(node *&head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  node *newhead = reverce(head->next);
  head->next->next = head;
  head->next = NULL;
  return newhead;
}

int main() {
  node *head;
  head = NULL;
  insertEnd(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 3);
  insertEnd(head, 4);
  insertEnd(head, 5);
  insertEnd(head, 6);
  reverce(head, NULL);
  display(head);
  return 0;
}
