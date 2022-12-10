#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *prev;
  node *next;

  node(int value) {
    data = value;
    prev = NULL;
    next = NULL;
  }
};
void insert_at_end(node *&head, int value) {
  if (head == NULL) {
    head = new node(value);
  }
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(value);
}

void display(node *head) {
  while (head != NULL) {
    cout << head->data << ", ";
    head = head->next;
  }
  cout << endl;
}
void insert_at_head(node *&head, int value) {
  node *n = new node(value);
  n->next = head;
  if (head != NULL) {
    head->prev = n;
  }
  head = n;
}

void del(node *&head, int value) {}
int main() {
  node *head;
  head = NULL;
  head = new node(0);
  insert_at_end(head, 1);
  insert_at_end(head, 2);
  insert_at_end(head, 3);
  insert_at_head(head, 4);
  display(head);

  return 0;
}
