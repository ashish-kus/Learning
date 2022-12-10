// you have to reverce k nodes in a link list
// example linklist= [ 1 -> 2 -> 3 -> 4-> 5 -> 6 ]
// then if we consider k=2 then required linked list
// will be = [ 2 -> 1 -> 3 -> 4 -> 5 -> 6 ]
// SOLUTION:
// constrain. consider user is kind a dum and may try
// to reverce n element but linked list contain lexx
// then n elements.

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

void revercek(node *&head, int k) {
  node *first = head;

  node *prev = NULL;
  node *current = head;
  node *next;

  int count = 0;
  while (current->next != NULL && count < k) {

    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }

  if (count < k) {
    current->next = prev;
    head = current;
    return;
  }
  head = prev;
  first->next = current;
  head = current;
}

int main() {

  node *head;
  head = NULL;
  insertEnd(head, 0);
  insertEnd(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 3);
  insertEnd(head, 4);
  insertEnd(head, 5);
  insertEnd(head, 6);
  display(head);
  revercek(head, 9);
  display(head);

  return 0;
}
