#include "../lib/graph.h"
#include <bits/stdc++.h>
using namespace std;
//
//
//   ___ _              _             _ _
//  / __| |_  __ _ _ __| |_ ___ _ _  | | |
// | (__| ' \/ _` | '_ \  _/ -_) '_| |_  _|
//  \___|_||_\__,_| .__/\__\___|_|     |_|
//                |_|
//
// Route Between Nodes: Given a directed graph, design an algorithm to find out
// whether there is a route between two nodes.
enum Status { Unvisited, Visited, Visiting };

bool route_between_nodes(vector<vector<int>> list, int n, int start, int end) {
  map<int, vector<int>> adj;
  vector<Status> vis(n, Unvisited);
  //
  //   ┌──┐    ┌──┐    ┌──┐
  //   │ 1├────► 0├────► 4│
  //   └─┬┘    └─▲┘    └▲─┘
  //     │       │      │
  //     │       │      │
  //   ┌─▼┐    ┌─┴┐     │
  //   │ 2│    │ 3├─────┘
  //   └──┘    └──┘
  //
  for (auto &edge : list) {
    adj[edge[0]].push_back(edge[1]); // populating adjacency list
  }
  // adj[0]: [4]
  // adj[1]: [0, 2]
  // adj[2]: []
  // adj[3]: [0, 4]
  // adj[4]: []

  queue<int> q;
  q.push(start);
  vis[start] = Visiting;

  while (!q.empty()) {
    int node = q.front();
    cout << "Dequeueing node: " << node << endl;

    q.pop();

    for (auto &adj_node : adj[node]) {
      cout << "Visiting node: " << adj_node << endl;

      if (vis[adj_node] == Unvisited) {
        cout << "Node " << adj_node << " is unvisited" << endl;

        if (adj_node == end) {
          cout << "Node " << adj_node << " is destination!!! YEY" << endl;
          return true;
        } else {
          cout << "Node " << adj_node << " is not destination" << endl;
          vis[adj_node] = Visiting;
          q.push(adj_node);
        }
      }
    }

    vis[node] = Visited;
  }

  cout << "Can't reach destination :(" << endl;
  return false;
}

int main() {
  vector<vector<int>> input{{1, 2}, {1, 0}, {0, 4}, {3, 0}, {3, 4}};

  assert(route_between_nodes(input, 5, 1, 4));
}
