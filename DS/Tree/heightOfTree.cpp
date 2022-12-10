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
int heigth(node *root) {
  if (root == NULL) {
    return 0;
  }

  int right = heigth(root->right);
  int left = heigth(root->left);
  if (left > right) {
    return 1 + left;
  }
  return 1 + right;
}

int main() {

  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  cout << endl << "HEIGHT: " << heigth(root);
  return 0;
}
