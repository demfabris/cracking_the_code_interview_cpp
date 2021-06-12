#include <bits/stdc++.h>

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

class Node {

public:
  int data;
  Node *next;

  Node(int value);
};

class LinkedList {

public:
  Node *head;

  LinkedList(std::vector<int> vec);

  void transverse();

  void push(int value);
};

#endif
