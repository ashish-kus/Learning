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

// function check for bst

bool check(node *root, node *min, node *max) {
  if (root == NULL) {
    return true;
  }

  if (min != NULL && root->data <= min->data) {
    return false;
  }
  if (max != NULL && root->data >= max->data) {
    return false;
  }

  bool leftvalid = check(root->left, min, root);
  bool rightvalid = check(root->right, root, max);
  return leftvalid and rightvalid;
}

void insertBst(node *&root, int value) { root = insert(root, value); }
int main() {
  cout << "ASHISH" << endl;
  node *root = NULL;
  insertBst(root, 2);
  insertBst(root, 7);
  insert(root, 4);
  insert(root, 9);
  insert(root, 3);
  insert(root, 6);
  preorder(root);
  if (check(root, NULL, NULL)) {
    cout << "true";
  } else {
    cout << "FALSE";
  }
  return 0;
}
