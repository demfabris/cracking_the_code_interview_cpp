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

LinkedList chapter_two_delete_middle_node(Node *middle) {
  // Delete middle node: Implement an algorithm to delete a node in the middle
  // (i.e., any node but the first and last node, not necessarily the exact
  // middle) of a singly linked list, given only access to that node.
  //
  // EXAMPLE
  // Input: the node C from the linked list A -> B -> C -> D -> E -> F
  // Output: A -> B -> D -> E -> F

  Node *curr = middle;

  while (curr->next->next != NULL) {
    curr->data = curr->next->data;
    curr = curr->next;
  }

  curr->data = curr->next->data;
  curr->next = NULL;

  LinkedList list = LinkedList({});
  list.head = middle;

  return list;
}

LinkedList chapter_two_partition(LinkedList list) {
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

  return list;
}

void chapter_two() {
  LinkedList list = LinkedList({1, 2, 3, 1, 4, 5, 6, 1, 1, 5, 6, 9});
  LinkedList q1_expected = LinkedList({1, 2, 3, 4, 5, 6, 9});
  assert(chapter_two_remove_dups(list) == q1_expected);

  assert(chapter_two_return_kth_to_last(list, 3) == 5);

  LinkedList list2 = LinkedList({1, 2, 3, 4, 5, 6});
  LinkedList q2_expected = LinkedList({4, 5, 6});
  assert(chapter_two_delete_middle_node(list2.head->next->next) == q2_expected);
}
