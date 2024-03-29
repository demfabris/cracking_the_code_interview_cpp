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
// First Common Ancestor: Design an algorithm and write code to find the first
// common ancestor of two nodes in a binary tree. Avoid storing additional nodes
// in a data structure. NOTE: This is not necessarily a binary search tree.
//
//                           ┌────┐
//                           │    │
//                     ┌─────┤ 3  ├────┐
//                     │     └────┘    │
//                     │               │
//                     │               │
//                   ┌─▼──┐          ┌─▼──┐
//                   │    │          │    │
//          ┌────────┤ 1  │          │ 5  ├─────────┐
//          │        └──┬─┘          └──┬─┘         │
//          │           │               │           │
//          │           │               │           │
//       ┌──▼─┐         │               │        ┌──▼─┐
//       │  0 │         │               │        │ 6  │
//       │    │      ┌──▼─┐          ┌──▼─┐      │    │
//       └────┘      │    │          │    │      └────┘
//                   │  2 │          │  4 │
//                   └────┘          └────┘
//
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

BTNode *recurse(BTNode *n1, BTNode *n2, BTNode *root) {
  if (root == n1 || root == n2 || root == nullptr) {
    return root;
  }

  BTNode *left = recurse(n1, n2, root->left);
  BTNode *right = recurse(n1, n2, root->right);

  if (left and right) {
    return root;
  } else {
    return left ? left : right;
  }
}

BTNode *first_common_ancestor(BTNode *n1, BTNode *n2, BTNode *root) {
  // 1. do DFS to find either n1 or n2 in left and right subtree.
  // 2. if both n1 and n2 are in some subtree. then there's a new first common
  // ancestor.
  // 3. if only one of them are in the subtree. the current root is the first
  // common ancestor.
  // 4. if none of them are in the subtree, panic.
  return recurse(n1, n2, root);
}

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  // Passing node(2), node(6) and root
  first_common_ancestor(node->left->right, node->right->right, node);
}
