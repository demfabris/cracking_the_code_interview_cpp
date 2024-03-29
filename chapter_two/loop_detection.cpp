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
// Loop detection: Given a circular linked list, implement an algorithm that
// returns the node at the beginning of the loop
//
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer
// points to an earlier node, so as to make a loop in the linked list
//
// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same C as earlier]
// Output: C
Node *loop_detection(LinkedList list) {

  Node *curr = list.head;
  Node *faster = list.head;

  while (faster->next != nullptr) {
    faster = faster->next->next;
    curr = curr->next;

    if (curr == faster) {
      // found the loop, now search for the beginning
      Node *head = list.head;
      while (head->next != curr->next) {
        head = head->next;
        curr = curr->next;
      }

      return curr; // this is the corrupted node
    }
  }

  return new Node(-1);
}

int main() {
  LinkedList input = LinkedList({1, 2, 3});
  Node *corrupted_node = input.head->next->next;
  corrupted_node->next = input.head->next; // input now: 1 -> 2 -> 3 -> 2...

  LinkedList input2 = LinkedList({1, 2, 3, 4, 5});
  Node *corrupted_node2 = input2.head->next->next->next->next;
  corrupted_node2->next = input2.head->next->next;

  LinkedList input3 = LinkedList({1, 2, 3, 4, 5, 6});
  Node *corrupted_node3 = input3.head->next->next->next->next->next;
  corrupted_node3->next = input3.head->next;

  assert(loop_detection(input) == corrupted_node);
  assert(loop_detection(input2) == corrupted_node2);
  assert(loop_detection(input3) == corrupted_node3);
}
