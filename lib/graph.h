#pragma once
#include <bits/stdc++.h>

using namespace std;

class GraphNode {
public:
  int data;
  vector<GraphNode> nodes;

  GraphNode(int value);

  void append(GraphNode node);
};

class Graph {
public:
  vector<GraphNode> nodes;
};
