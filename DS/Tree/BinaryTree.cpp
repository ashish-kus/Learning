#include <ios>
#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int num) {
    data = num;
    left = NULL;
    right = NULL;
  }
};
void insert(node *&root, int num) {
  if (root == NULL) {
    root = new node(num);
    return;
  }
  node *temp = root;
  while (temp != NULL) {
    if (temp->data > num) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  temp = new node(num);
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
  cout << "ASHISH";
  node *root = NULL;

  insert(root, 5);
  insert(root, 6);
  insert(root, 2);
  preorder(root);
  cout << endl << root->left->data;
  return 0;
}
