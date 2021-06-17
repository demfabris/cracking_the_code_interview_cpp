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
// Rotate Matrix: Given an image represented by an NxN matrix, where each
// pixel in the image is 4 bytes, write a method to rotate the image by 90
// degrees. Can you do this in place?
vector<vector<int>> rotate_matrix(vector<vector<int>> m) {

  int len = m.size();

  for (int i = 0; i < len / 2; i++) {
    for (int j = i; j < len - i - 1; j++) {
      int aux = m[i][j];

      m[i][j] = m[len - j - 1][i]; // bottom left -> up

      m[len - j - 1][i] = m[len - i - 1][len - j - 1]; // bottom right -> left

      m[len - i - 1][len - j - 1] = m[j][len - i - 1]; // top right -> bottom

      m[j][len - i - 1] = aux;
    }
  }

  return m;
}

int main() {
  vector<vector<int>> input = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> expected = {
      {13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}};

  assert(rotate_matrix(input) == expected);
}
