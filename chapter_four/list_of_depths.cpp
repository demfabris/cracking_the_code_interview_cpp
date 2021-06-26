#include "../lib/linked_list.h"
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
// List of depths: Given a binary tree, design an algorithm which creates a
// linked list of all the nodes at each depth (e.g., if you have a tree with
// depth D, you'll have D linked lists)
class BTNode {
public:
  int data;

  BTNode *left;
  BTNode *right;

  BTNode(int value) { data = value; };
};

void recurse(vector<Node *> &res, int depth, BTNode *node) {
  if (res[depth] == nullptr) {
    res[depth] = new Node(node->data);
  } else {
    Node *curr = res[depth];
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new Node(node->data);
  }

  if (node->right != nullptr) {
    recurse(res, depth + 1, node->right);
  }
  if (node->left != nullptr) {
    recurse(res, depth + 1, node->left);
  }
}

vector<Node *> list_of_depths(BTNode *node) {
  // 1. Initialize result vector which will contain all the head nodes
  // 2. Keep track of the depth
  // 3. Recursive function that receives BTree Node, depth, and result array.
  int depth = 0;
  vector<Node *> res(3, nullptr);
  BTNode *curr = node;

  recurse(res, depth, curr);

  return res;
}

int main() {
  BTNode *node = new BTNode(3);
  node->right = new BTNode(5);
  node->right->right = new BTNode(6);
  node->right->left = new BTNode(4);

  node->left = new BTNode(1);
  node->left->right = new BTNode(2);
  node->left->left = new BTNode(0);

  vector<Node *> result = list_of_depths(node);
  assert(result[0]->data == 3);
  assert(result[1]->data == 5);
  assert(result[1]->next->data == 1);
  assert(result[2]->data == 6);
  assert(result[2]->next->data == 4);
}
