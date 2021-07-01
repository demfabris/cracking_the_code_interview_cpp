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
// BST Sequences: A binary search tree was created by traversing through an
// array from left to right and inserting each element. Given a binary search
// tree with distinct elements, print all possible arrays that could have led to
// this tree.
//
// EXAMPLE
// Input:
//          ┌────┐
//          │ 2  │
//       ┌──┤    ├───┐
//       │  └────┘   │
//       │           │
//       │           │
//     ┌─▼──┐     ┌──▼─┐
//     │    │     │    │
//     │ 1  │     │  3 │
//     └────┘     └────┘
//
// Output: {2, 1, 3}, {2, 3, 1}
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

vector<vector<int>> bst_sequences(BTNode *root) {
  //

  return {{}};
}

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  bst_sequences(node);
}
