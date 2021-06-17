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
// Palindrome: Implement a function to check if a linked list is a palindrome.
bool palindrome(LinkedList list) {

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

  reversed.transverse();
  list.transverse();

  return true;
}

int main() {
  LinkedList input = LinkedList({1, 2, 2, 3, 3, 5, 3, 3, 2, 2, 1});

  palindrome(input);
}
