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
// Return Kth to Last: Implement an algorithm to find the kth to last element
// of a singly linked list.
int return_kth_to_last(LinkedList list, int kth) {

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

int main() {
  LinkedList input = LinkedList({1, 2, 3, 1, 4, 5, 6, 1, 1, 5, 6, 9});
  int kth = 3;
  int expected = 5;

  assert(return_kth_to_last(input, kth) == expected);
}
