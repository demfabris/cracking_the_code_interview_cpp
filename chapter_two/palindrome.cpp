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
// Palindrome: Implement a function to check if a linked list is a palindrome.
LinkedList palindrome_1(LinkedList list) {
  // Reverse the list and compare input == output
  Node *curr = list.head;
  Node *prev = nullptr;
  Node *head = nullptr;

  while (curr != nullptr) {
    head = curr->next;
    curr->next = prev;
    prev = curr;
    curr = head;
  }

  LinkedList reversed = LinkedList({});
  reversed.head = prev;

  return reversed;
}

bool palindrome_2(LinkedList list) {
  // TODO: Recursive method.

  return true;
}

int main() {
  LinkedList input = LinkedList({1, 2, 2, 3, 3, 5, 3, 3, 2, 2, 1});
  LinkedList expected = LinkedList({1, 2, 2, 3, 3, 5, 3, 3, 2, 2, 1});
  assert(palindrome_1(input) == expected);
  palindrome_2(input);
}
