#pragma once
#include <bits/stdc++.h>

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

  bool operator==(LinkedList const other);

  void transverse();

  void push(int value);

  int length();
};
