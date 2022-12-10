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
void add_at_end(node *&head, int value) {
  if (head == NULL) {
    head = new node(value);
  }
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(value);
}

void add_at_head(node *&head, int num) {
  node *temp = new node(num);
  temp->next = head;
  head = temp;
}

bool search(node *head, int num) {
  while (head != NULL) {
    if (head->data == num) {
      return true;
    }
    head = head->next;
  }
  return false;
}

void display(node *head) {
  while (head != NULL) {
    cout << head->data << ", ";
    head = head->next;
  }
  cout << endl;
}

// delete function and stuff;

void del(node *&head, int value) {
  while (head->data == value) {
    if (head->next != NULL) {
      node *todelete = head;
      head = head->next;
      delete todelete;
    } else {
      head = NULL;
    }
  }
}
int main() {
  node *head = new node(8);
  display(head);
  cout << endl;
  add_at_head(head, 8);

  add_at_head(head, 8);

  add_at_head(head, 8);
  add_at_head(head, 8);
  add_at_head(head, 8);
  display(head);
  del(head, 8);
  cout << endl;

  // display(head);
  return 0;
}
