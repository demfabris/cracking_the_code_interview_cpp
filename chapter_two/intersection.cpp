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
// Intersection: Given two (singly) linked lists, determine if the two lsits
// intersect. Return the intersecting node. Note that the intersection is
// defined based on reference, not value. That is, if the kth node of the first
// linked list is the exact same node (by reference) as the jth node of the
// second linked list, then they are intersecting.
Node *intersection(LinkedList list1, LinkedList list2) {
  // If they're the same length. O(A) where A is length
  Node *c1 = list1.head;
  Node *c2 = list2.head;

  while (c1->next != nullptr && c2->next != nullptr) {
    if (c1 == c2) {
      return c1;
    } else {
      c1 = c1->next;
      c2 = c2->next;
    }
  }

  return new Node(-1); // not intersecting
}

Node *intersection_1(LinkedList list1, LinkedList list2) {
  // If they differ in length. O(A+B)
  Node *c1 = list1.head;
  Node *c2 = list2.head;

  int diff = list1.length() - list2.length();

  // We can safely ignore the case where first element is intersect because
  // otherwise they would be the same length
  if (diff > 0) {
    // list1 is bigger
    for (; diff > 0; diff--) {
      c1 = c1->next;
    }
  } else {
    // list2 is bigger
    for (; diff < 0; diff++) {
      c2 = c2->next;
    }
  }

  while (c1->next != nullptr && c2->next != nullptr) {
    if (c1 == c2) {
      return c1;
    } else {
      c1 = c1->next;
      c2 = c2->next;
    }
  }

  return new Node(-1);
}

int main() {
  LinkedList input1 = LinkedList({0, 1, 2});
  LinkedList input2 = LinkedList({9, 8, 7});

  LinkedList input3 = LinkedList({0, 1, 2});
  LinkedList input4 = LinkedList({9, 8, 7, 6});

  LinkedList input5 = LinkedList({0, 1, 2});
  LinkedList input6 = LinkedList({9, 8, 7, 6});

  LinkedList intersect = LinkedList({3, 4, 5});

  input1.head->next->next->next = intersect.head;
  input2.head->next->next->next = intersect.head;

  input3.head->next->next->next = intersect.head;
  input4.head->next->next->next->next = intersect.head;

  Node *expected = intersect.head;
  Node *negative_expected = new Node(-1);

  assert(intersection(input1, input2) == expected);
  assert(intersection_1(input3, input4) == expected);
  assert(intersection(input5, input6)->data == negative_expected->data);
  assert(intersection_1(input5, input6)->data == negative_expected->data);
}
