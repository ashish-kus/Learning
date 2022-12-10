#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;

  node(int num) {
    data = num;
    left = NULL;
    right = NULL;
  }
};
int sum(node *root) {
  if (root == NULL) {
    return 0;
  }
  return root->data + sum(root->left) + sum(root->right);
}

int main() {

  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  cout << endl << "HEIGHT: " << sum(root);
  return 0;
}
