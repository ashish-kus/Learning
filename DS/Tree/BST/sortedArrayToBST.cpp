#include <iostream>
using namespace std;

struct node {
  int data;
  node *left, *right;

  node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

node *BST(int array[], int start, int end) {

  if (start > end) {
    return NULL;
  }
  int mid = (start + end) / 2;
  node *root = new node(array[mid]);

  root->left = BST(array, start, mid - 1);
  root->right = BST(array, mid + 1, end);

  return root;
}

void preorder(struct node *root) {

  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
int main() {
  cout << "ASHISH" << endl;
  int array[] = {20, 30, 40, 50, 70, 80, 90};
  int start = 0;
  int end = sizeof(array) / sizeof(array[0]);
  node *root = BST(array, 0, end - 1);

  preorder(root);
  return 0;
}
