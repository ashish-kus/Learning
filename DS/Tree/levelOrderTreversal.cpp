#include <iostream>
#include <queue>
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

void lot(node *root) {
  if (root == NULL) {
    return;
  }

  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();
    if (temp != NULL) {
      cout << temp->data << ", ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    } else if (!q.empty()) {
      q.push(NULL);
    }
  }
}

int main() {
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  lot(root);

  return 0;
}
