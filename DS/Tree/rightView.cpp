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

void rightView(node *root) {
  if (root == NULL) {
    return;
  }
  queue<node *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      node *curr = q.front();
      q.pop();

      if (i == n - 1) {
        cout << curr->data << " ";
      }

      if (curr->left != NULL) {
        q.push(curr->left);
      }

      if (curr->right != NULL) {
        q.push(curr->right);
      }
    }
  }
}
int main() {

  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->left->right->left = new node(0);
  root->right->left = new node(6);
  root->right->right = new node(7);
  cout << endl << "HEIGHT: " << heigth(root);

  cout << "RIGHTVIEW: " << endl;
  rightView(root);
  return 0;
}
