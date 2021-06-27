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
// Check Balanced: Implement a function to check if a binary tree is balanced.
// For the purposes of this question, a balanced tree is defined to be a tree
// such that the heights of the two subtrees of any node never differ by more
// than one.
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

int get_height(BTNode *node) {
  if (node == nullptr)
    return -1;

  int left = get_height(node->left);
  if (left == INT_MIN)
    return INT_MIN;

  int right = get_height(node->right);
  if (right == INT_MIN)
    return INT_MIN;

  if (abs(right - left) > 1) {
    return INT_MIN;
  } else {
    return max(left, right) + 1;
  }
}

bool check_balanced(BTNode *root) { return get_height(root) != INT_MIN; }

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  assert(check_balanced(node));
  node->left->left->left = new BTNode(-5);
  assert(check_balanced(node));

  // Unbalanced
  node->left->left->left->left = new BTNode(-6);
  assert(!check_balanced(node));
}
