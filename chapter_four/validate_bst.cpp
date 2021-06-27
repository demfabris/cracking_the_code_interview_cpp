#include <bits/stdc++.h>
using namespace std;
//
//
//   ___ _              _             _ _
//  / __| |_  __ _ _ __| |_ ___ _ _  | | |
// | (__| ' \/ _` | '_ \  _/ -_) '_| |_  _|
//  \___|_||_\__,_| .__/\__\___|_|     |_|
//                |_|
//
// Validate BST: Implement a function to check if a binary tree is a binary
// search tree.
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

bool check_subtree(BTNode *node, int min, int max) {
  if (node == nullptr)
    return true;

  if (!check_subtree(node->left, min, node->data))
    return false;
  if (!check_subtree(node->right, node->data, max))
    return false;

  if (node->data < min or node->data > max) {
    return false;
  }

  return true;
}

bool validate_bst(BTNode *root) {
  return check_subtree(root, INT_MIN, INT_MAX);
}

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  assert(validate_bst(node));
  node->left->left = new BTNode(5);
  assert(!validate_bst(node));
}
