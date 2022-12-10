#include <iostream>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;

  node() {}
  node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};
node *insert(node *root, int value) {
  if (root == NULL) {
    return new node(value);
  }
  if (root->data > value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }
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
void insertBst(node *&root, int value) { root = insert(root, value); }
int main() {
  cout << "ASHISH" << endl;
  node *root = NULL;
  insertBst(root, 2);
  insertBst(root, 7);
  preorder(root);
  return 0;
}
