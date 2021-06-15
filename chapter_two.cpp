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

int chapter_two_return_kth_to_last(LinkedList list, int kth) {
  // Return Kth to Last: Implement an algorithm to find the kth to last element
  // of a singly linked list.

  Node *curr = list.head;
  Node *curr_ahead = list.head;

  for (int i = 0; i < kth - 1; i++) {
    // Setting curr_ahead to k elements ahead
    if (curr_ahead->next != nullptr) {
      curr_ahead = curr_ahead->next;
    } else {
      // Not enough list elements to find kth
    }
  }

  while (curr_ahead->next != nullptr) {
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

LinkedList chapter_two_partition(LinkedList list, int part) {
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

LinkedList chapter_two_sum_lists(LinkedList l1, LinkedList l2) {
  // Sum Lists: you have two numbers represented by a linked list, where each
  // node contains a single digit. The digits are stored in reverse order, such
  // that the 1's digit is at the head of the list. Write a function that adds
  // the two numbers and returns the sum as a linked list.
  //
  // EXAMPLE
  // Input: ( 7 -> 1 -> 6 ) + ( 5 -> 9 -> 2 ) = 617 + 295
  // Output: 2 -> 1 -> 9 = 912
  //
  // FOLLOW UP
  // Suppose the digits are stored in forward order. Repeat the above problem.
  //
  // EXAMPLE
  // Input: ( 6 -> 1 -> 7 ) + ( 2 -> 9 -> 5 ) = 617 + 295
  // Output: 9 -> 1 -> 2 = 912

  Node *n1 = l1.head;
  Node *n2 = l2.head;
  int dec = 1;
  int sum = 0;

  while (true) {
    sum += (n1->data + n2->data) * dec;
    dec *= 10;

    if (n1->next == nullptr && n2->next == nullptr) {
      break;
    }

    if (n1->next != nullptr) {
      n1 = n1->next;
    } else {
      n1->data = 0;
    }

    if (n2->next != nullptr) {
      n2 = n2->next;
    } else {
      n2->data = 0;
    }
  }

  LinkedList list = LinkedList({});
  list.head = new Node(sum % 10);
  sum /= 10;
  Node *curr = list.head;

  while (sum > 0) {
    curr->next = new Node(sum % 10);
    sum /= 10;
    curr = curr->next;
  }

  return list;
}

bool chapter_two_palindrome(LinkedList list) {
  // Palindrome: Implement a function to check if a linked list is a palindrome.

  return true;
}

void chapter_two() {
  LinkedList list = LinkedList({1, 2, 3, 1, 4, 5, 6, 1, 1, 5, 6, 9});
  LinkedList q1_expected = LinkedList({1, 2, 3, 4, 5, 6, 9});
  assert(chapter_two_remove_dups(list) == q1_expected);

  assert(chapter_two_return_kth_to_last(list, 3) == 5);

  LinkedList list2 = LinkedList({1, 2, 3, 4, 5, 6});
  LinkedList q2_expected = LinkedList({4, 5, 6});
  assert(chapter_two_delete_middle_node(list2.head->next->next) == q2_expected);

  LinkedList list3 = LinkedList({3, 5, 8, 5, 10, 2, 1});
  LinkedList q3_expected = LinkedList({3, 2, 1, 10, 5, 8, 5});
  assert(chapter_two_partition(list3, 5) == q3_expected);

  LinkedList list4_1 = LinkedList({7, 1, 6});
  LinkedList list4_2 = LinkedList({5, 9, 2});
  LinkedList q4_expected = LinkedList({2, 1, 9});
  assert(chapter_two_sum_lists(list4_1, list4_2) == q4_expected);
}
