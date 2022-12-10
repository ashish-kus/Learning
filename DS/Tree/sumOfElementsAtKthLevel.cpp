#include <iostream>
#include <queue>
using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;

  node(int num) {
    key = num;
    left = NULL;
    right = NULL;
  }
};

int sumk(node *root, int k) {
  if (root == NULL) {
    return 0;
  }

  if (k == 0) {
    return root->key;
  }
  int sum;
  int level = 0;
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty() && level <= k) {
    node *temp = q.front();
    q.pop();

    if (temp != NULL) {
      if (level == k) {
        sum += temp->key;
      }
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    } else {
      if (!q.empty()) {
        level++;
        q.push(NULL);
      }
    }
  }
  return sum;
}

int main() {
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  cout << "Ashish";
  cout << sumk(root, 2);
  return 0;
}
