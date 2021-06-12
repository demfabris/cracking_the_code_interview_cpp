#include "lib/chapter_two.h"
#include "lib/data_structures.h"
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
//
LinkedList chapter_two_remove_dups(LinkedList list) {
  // Remove Dups: Write code to remove duplicates from an unsorted linked list.
  // FOLLOW UP
  // How would you solve this problem if a temporary buffer is not allowed?

  Node *node = list.head;

  while (node != NULL) {
    Node *curr = node;

    while (curr->next != NULL) {
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

int chapter_two_return_kth_to_last(LinkedList list, int kth) {
  // Return Kth to Last: Implement an algorithm to find the kth to last element
  // of a singly linked list.

  Node *curr = list.head;
  Node *curr_ahead = list.head;

  for (int i = 0; i < kth - 1; i++) {
    // Setting curr_ahead to k elements ahead
    if (curr_ahead->next != NULL) {
      curr_ahead = curr_ahead->next;
    } else {
      // Not enough list elements to find kth
    }
  }

  while (curr_ahead->next != NULL) {
    curr_ahead = curr_ahead->next;
    curr = curr->next;
  }

  return curr->data;
}

void chapter_two() {
  LinkedList list = LinkedList({1, 2, 3, 1, 4, 5, 6, 1, 1, 5, 6, 9});
  LinkedList q1_expected = LinkedList({1, 2, 3, 4, 5, 6, 9});
  assert(chapter_two_remove_dups(list) == q1_expected);

  assert(chapter_two_return_kth_to_last(list, 3) == 5);
}
