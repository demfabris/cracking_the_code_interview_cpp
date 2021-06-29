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
// Build Order: You are given a list of projects and a list of dependencies
// (which is a list of pairs of projects, where the second project is dependent
// on the first project). All of a project's dependencies must be built before
// the project is. Find a build order that will allow the projects to be built.
// If there is no valid build order, return an error.
//
// EXAMPLE
// Input:
//  projects: a, b, c, d, e, f
//  dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
//
// Output: f, e, a, b, d, c
enum State { Unvisited, Visiting, Visited };

bool dfs(map<char, vector<char>> &adj, char node, map<char, State> &vis,
         stack<char> &order) {
  if (vis[node] == Visiting)
    return false;

  if (vis[node] == Visited) {
    return true;
  }

  vis[node] = Visiting;
  for (auto &x : adj[node]) {
    dfs(adj, x, vis, order);
  }

  order.push(node);
  vis[node] = Visited;
  return true;
}

stack<char> build_order(vector<char> projs, vector<vector<char>> deps) {
  map<char, vector<char>> adj;
  map<char, State> vis;
  stack<char> order;
  // adj[a]: [d]
  // adj[b]: [d]
  // adj[c]: []
  // adj[d]: [c]
  // adj[e]: []
  // adj[f]: [a, b]

  for (auto &x : deps) {
    adj[x[0]].push_back(x[1]);
  }

  for (auto &x : projs) {
    vis[x] = Unvisited;
  }

  for (auto &x : projs) {
    if (!dfs(adj, x, vis, order)) {
      return {};
    }
  }

  return order;
}

int main() {
  vector<char> input = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<vector<char>> deps = {
      {'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
  stack<char> expected;
  expected.push('c');
  expected.push('d');
  expected.push('a');
  expected.push('b');
  expected.push('e');
  expected.push('f');

  assert(build_order(input, deps) == expected);
}
