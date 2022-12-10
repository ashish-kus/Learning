/*
   IN this Question we are given a link list
   our gole is to return a link list which
   contain all the odd position element of
   the provided list first in order and then
   all the rest of the element,

   Let us understand with the help of example:
given list:    [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 ]
        for better understand, all odd no are  at odd position,
requred list:  [ 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 ]
       now all odd numbers are before even.
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
/*
void oddeven(node *&head) {
  if (head == NULL) {
    return;
  }
  node *odd;
  odd = NULL;
  node *even;
  even = NULL;

  node *current = head;
  int data;
  cout << "a";
  while (current != NULL) {
    data = current->data;
    add_at_end(odd, data);
    data = current->next->data;
    add_at_end(even, data);
    current = current->next->next;
  }
  head = odd;
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = even;

  return;
}
*/

void oddeven(node *&head) {
  node *odd = head;
  node *even = head->next;
  node *evenStart = even;
  while (even->next != NULL && odd->next != NULL) {
    odd->next = even->next;
    odd = odd->next;

    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenStart;
  if (odd->next != NULL) {
    even->next = NULL;
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
  oddeven(head);
  display(head);
  return 0;
}
