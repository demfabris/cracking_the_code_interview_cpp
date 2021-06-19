#include "graph.h"
#include <bits/stdc++.h>

GraphNode::GraphNode(int value) { data = value; };

void GraphNode::append(GraphNode node) { nodes.push_back(node); }
