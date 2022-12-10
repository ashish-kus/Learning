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
void insertBst(node *&root, int value) { root = insert(root, value); }
int mian() {
  node *root = NULL;
  cout << " ASHISH" << endl;

  while (true) {
    int number;
    cin >> number;
    if (number > 0) {
      insert(root, number);
    }
  }

  return 0;
}
