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
LinkedList sum_lists(LinkedList l1, LinkedList l2) {

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

int main() {
  LinkedList input1 = LinkedList({7, 1, 6});
  LinkedList input2 = LinkedList({5, 9, 2});
  LinkedList expected = LinkedList({2, 1, 9});
  assert(sum_lists(input1, input2) == expected);
}
