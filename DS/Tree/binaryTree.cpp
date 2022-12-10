#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left;
  struct Node *right;

  Node(int num) {
    key = num;
    left = NULL;
    right = NULL;
  }
};

void insert(Node *&root, int num) {
  if (root == NULL) {
    root = new Node(num);
  }
  Node *temp = root;
  while (temp != NULL) {
    if (temp->key > num) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  temp = new Node(num);
}

int main() {
  struct Node *root = NULL;
  insert(root, 7);
  insert(root, 9);
  cout << root->key << " " << root->right->key;

  return 0;
}
