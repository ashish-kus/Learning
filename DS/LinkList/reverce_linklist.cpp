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

void reverce(node *&head) {
  node *previous = NULL;
  node *current = head;
  node *upnext = head->next;

  while (current != NULL) {
    upnext = current->next;
    current->next = previous;

    previous = current;
    current = upnext;
  }
  head = previous;
}

int main() {
  node *head = new node(0);
  insertEnd(head, 2);
  insertEnd(head, 4);
  insertEnd(head, 6);
  insertEnd(head, 8);
  insertEnd(head, 10);
  insertEnd(head, 12);
  display(head);
  reverce(head);
  display(head);
  return 0;
}
