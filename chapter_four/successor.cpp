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
// Successor: Write an algorithm to find the "next" node (i.e., in-order
// successor) of a given node in a binary search tree. You may assume that each
// node has a link to its parent.
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

BTNode *successor(BTNode *root) {
  //
  return root;
}

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  successor(node);
}
