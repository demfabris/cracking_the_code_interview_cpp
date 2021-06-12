#include "../lib/data_structures.h"
#include <bits/stdc++.h>

using namespace std;

Node::Node(int value) { data = value; }

bool LinkedList::operator==(LinkedList other) {
  Node *curr1 = head;
  Node *curr2 = other.head;

  while (curr1->next != NULL && curr2->next != NULL) {
    if (curr1->data == curr2->data) {
      curr1 = curr1->next;
      curr2 = curr2->next;
    } else {
      return false;
    }
  }

  if ((curr1->next == NULL && curr2->next != NULL) ||
      curr1->next != NULL && curr2->next == NULL) {
    return false;
  }

  return true;
}

LinkedList::LinkedList(vector<int> vec) {
  if (vec.size() == 0) {
    head = NULL;
  } else {
    int i = 0;
    head = new Node(vec[i++]);
    Node *curr = head;

    while (i < vec.size()) {
      curr->next = new Node(vec[i]);
      curr = curr->next;
      i++;
    }
  }
}

void LinkedList::transverse() {
  Node *curr = head;

  if (curr == NULL) {
    cout << "EMPTY" << endl;
    return;
  }

  while (curr != NULL) {
    cout << curr->data << ' ';
    curr = curr->next;
  }

  cout << endl;
}

void LinkedList::push(int value) {
  Node *curr = head;
  Node *n = new Node(value);

  if (curr == NULL) {
    curr = n;
    head = curr;
    return;
  }

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = n;
}
