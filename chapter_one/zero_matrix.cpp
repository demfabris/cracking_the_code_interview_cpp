#include <bits/stdc++.h>
using namespace std;
//
//
//   ___ _              _             _
//  / __| |_  __ _ _ __| |_ ___ _ _  / |
// | (__| ' \/ _` | '_ \  _/ -_) '_| | |
//  \___|_||_\__,_| .__/\__\___|_|   |_|
//                |_|
//
//
// Zero Matrix: Write an algorithm such that if an element in an MxN matrix is
// 0, its entire row and column are set to 0.
vector<vector<int>> zero_matrix(vector<vector<int>> m) {

  int n = m.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == 0) {
        m[i][j] = -1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == -1) {
        for (int x = 0; x < n; x++) {
          // zeroing row
          m[i][x] = 0;
        }

        for (int y = 0; y < n; y++) {
          // zeroing col
          m[y][j] = 0;
        }
      }
    }
  }

  return m;
}

int main() {
  vector<vector<int>> input = {
      {1, 2, 0, 4}, {1, 2, 3, 4}, {6, 1, 6, 8}, {9, 2, 1, 1}};
  vector<vector<int>> expected = {
      {0, 0, 0, 0}, {1, 2, 0, 4}, {6, 1, 0, 8}, {9, 2, 0, 1}};

  assert(zero_matrix(input) == expected);
}
