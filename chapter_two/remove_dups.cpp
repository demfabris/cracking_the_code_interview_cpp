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
// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
LinkedList remove_dups(LinkedList list) {

  Node *node = list.head;

  while (node != nullptr) {
    Node *curr = node;

    while (curr->next != nullptr) {
      if (curr->next->data == node->data) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }

    node = node->next;
  }

  return list;
}

int main() {
  LinkedList input = LinkedList({1, 2, 3, 1, 4, 5, 6, 1, 1, 5, 6, 9});
  LinkedList expected = LinkedList({1, 2, 3, 4, 5, 6, 9});

  assert(remove_dups(input) == expected);
}
