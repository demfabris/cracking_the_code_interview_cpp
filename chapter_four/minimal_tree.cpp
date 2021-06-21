#include "../lib/graph.h"
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
// Minimal Tree: Given a sorted (increasing order) array with unique integer
// elements, write an algorithm to create a binary search tree with minimal
// height.
class Node {
public:
  int data;

  Node *left;
  Node *right;

  Node(int value) { data = value; };
};

Node *make_bst(vector<int> nums, int start, int end) {
  // 1. Check if start and end colide
  // 2. Get middle point
  // 3. recurse on left and right.
  // 4. return this root node
  if (start > end) {
    return nullptr;
  }

  int mid = (start + end) / 2;
  Node *n = new Node(nums[mid]);
  n->left = make_bst(nums, start, mid - 1);
  n->right = make_bst(nums, mid + 1, end);

  return n;
}

Node *minimal_tree(vector<int> input) {
  return make_bst(input, 0, input.size() - 1);
}

int main() {
  vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  Node *n = new Node(5);
  n->left = new Node(2);
  n->right = new Node(8);

  assert(minimal_tree(input)->data == n->data);
  assert(minimal_tree(input)->left->data == n->left->data);
  assert(minimal_tree(input)->right->data == n->right->data);
}
