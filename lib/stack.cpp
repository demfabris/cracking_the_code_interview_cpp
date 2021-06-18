#include "stack.h"

StackNode::StackNode(int value) { data = value; };

Stack::Stack(int max_cap) {
  capacity = max_cap;
  top = nullptr;
};

void Stack::push(int data) {
  if (this->is_full()) {
    cout << "FULL" << endl;
    return;
  }

  if (top == nullptr) {
    top = new StackNode(data);
  } else {
    StackNode *node = new StackNode(data);
    node->prev = top;
    top = node;
  }
}

int Stack::pop() {
  if (top == nullptr) {
    cout << "EMPTY" << endl;
    return -1;
  }

  int data = top->data;
  StackNode *node = top;
  top = top->prev;

  node->prev = nullptr;
  delete node;

  return data;
}

bool Stack::is_empty() {
  if (top == nullptr) {
    return true;
  } else {
    return false;
  }
}

bool Stack::is_full() {
  int count = 0;
  StackNode *curr = top;

  while (curr->prev != nullptr) {
    count++;
    if (count >= capacity) {
      return true;
    }

    curr = curr->prev;
  }

  return false;
}

void Stack::transverse() {
  StackNode *curr = top;

  if (top == nullptr) {
    return;
  }

  while (curr->prev != nullptr) {
    cout << curr->data << endl;
    curr = curr->prev;
  }
}
