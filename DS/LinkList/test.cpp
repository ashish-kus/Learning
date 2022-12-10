#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

void preorder(node *root) {

  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void add(node *&root, int num) {}
int main() {
  node *root = NULL;
  add(root, 3);
  cout << &root->right->data << endl;
  add(root, 5);
  cout << &root->left->data << endl;
  preorder(root);
  return 0;
}

/*

  node *temp = root;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(value);

  */
