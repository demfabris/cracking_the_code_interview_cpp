#include "../lib/linked_list.h"
#include <bits/stdc++.h>
using namespace std;
//
//
//   ___ _              _             ___
//  / __| |_  __ _ _ __| |_ ___ _ _  |_  )
// | (__| ' \/ _` | '_ \  _/ -_) '_|  / /
//  \___|_||_\__,_| .__/\__\___|_|   /___|
//                |_|
//
// Delete middle node: Implement an algorithm to delete a node in the middle
// (i.e., any node but the first and last node, not necessarily the exact
// middle) of a singly linked list, given only access to that node.
//
// EXAMPLE
// Input: the node C from the linked list A -> B -> C -> D -> E -> F
// Output: A -> B -> D -> E -> F
LinkedList delete_middle_node(Node *middle) {

  Node *curr = middle;

  while (curr->next->next != nullptr) {
    curr->data = curr->next->data;
    curr = curr->next;
  }

  curr->data = curr->next->data;
  curr->next = nullptr;

  LinkedList list = LinkedList({});
  list.head = middle;

  return list;
}

int main() {
  LinkedList input = LinkedList({1, 2, 3, 4, 5, 6});
  LinkedList expected = LinkedList({4, 5, 6});

  assert(delete_middle_node(input.head->next->next) == expected);
}
