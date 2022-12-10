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

void flaten(node *&root) {
  if (root == NULL) {
    return;
  }
  node *temp = root;
  if (temp->left != NULL) {
    node *rnode = temp->right;
    temp->right = temp->left;
    temp->left = NULL;
    temp->right->right = rnode;

    flaten(temp->right);
  } else {
    temp = temp->right;
  }
}

void display(node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  display(root->right);
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

  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  flaten(root);
  preorder(root);
  display(root);
  return 0;
}
