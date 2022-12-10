/*
   IN this problem we are given a linklist ex [ 1, 2, 3, 4, 5, 6, 7, 8 ]
   now were are asked to append k nodes from the last of the linklist to
   the starting of tha link list;
    EXample given link list is [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]; and k =4
    then required linklist is [ 6, 7, 8, 9, 0, 1, 2 ,3 ,4 , 5 ]
*/

#include <iostream>
#include <iterator>
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
  } else {
    node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new node(value);
  }
}

void display(node *head) {
  while (head != NULL) {
    cout << head->data << ", ";
    head = head->next;
  }
  cout << endl;
}

int leng(node *head) {
  if (head == NULL) {
    return 0;
  }
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->next;
  }
  return count;
}
/* thia is our functio that will answer the question
   of the above question

   */

void appendk(node *&head, int k) {
  int length = leng(head);
  int parta = length - k;
  node *last = head;
  if (parta < length) {
    int count = 1;
    while (count < parta) {
      last = last->next;
      count++;
    }
    node *newhead = last->next;
    last->next = NULL;
    node *temp = newhead;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = head;
    head = newhead;
  }
}
int main() {
  node *head;
  head = NULL;
  add_at_end(head, 1);
  add_at_end(head, 2);
  add_at_end(head, 3);
  add_at_end(head, 4);
  add_at_end(head, 5);
  add_at_end(head, 6);
  add_at_end(head, 7);
  add_at_end(head, 8);
  add_at_end(head, 9);
  display(head);
  appendk(head, 3);
  display(head);
  return 0;
}
