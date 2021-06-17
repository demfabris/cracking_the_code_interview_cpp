#include "../lib/data_structures.h"
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
// Partition: Write code to partition a liked list around a value x, such that
// all nodes less than x come before all nodes greater than or equal to x. If
// x is contained within the list, the values of x only need to be after the
// elements less than x (see below). The partition element x can appear
// anywhere in the "right partition"; it does not need to appear between the
// left and the right partitions.
//
// EXAMPLE
// Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition=5]
// Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
LinkedList partition(LinkedList list, int part) {

  Node *curr = list.head; // 3
  Node *outer = list.head;

  while (curr != nullptr) {
    Node *inner = curr; // 5

    if (inner->data >= part) {
      while (inner->next != nullptr) {
        int aux = inner->data; // 5
        inner->data = inner->next->data;
        inner->next->data = aux;
        inner = inner->next;
      }

      if (outer->next != nullptr) {
        // outer counter to prevent infinite switching
        outer = outer->next;
      } else {
        break;
      }

    } else {
      curr = curr->next;
    }
  }

  return list;
}

int main() {
  LinkedList input = LinkedList({3, 5, 8, 5, 10, 2, 1});
  LinkedList expected = LinkedList({3, 2, 1, 10, 5, 8, 5});
  int index = 5;

  assert(partition(input, index) == expected);
}
