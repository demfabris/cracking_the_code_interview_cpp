#pragma once
#include <bits/stdc++.h>

using namespace std;

class StackNode {
public:
  int data;
  StackNode *prev;

  StackNode(int value);
};

class Stack {
public:
  StackNode *top;
  int capacity;

  Stack(int cap);

  void push(int data);

  int pop();

  bool is_empty();

  bool is_full();

  void transverse();
};
