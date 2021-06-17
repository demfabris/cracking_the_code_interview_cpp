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
// Is Unique: implement an algorithm to determine if a string has all unique
// characters. What if you cannot use additional data structures?
bool is_unique(string input) {

  vector<char> cache;

  for (int i = 0; i < input.length(); i++) {
    for (char &c : cache) {
      if (input[i] == c) {
        return false;
      }
    }

    cache.push_back(input[i]);
  }

  return true;
}

bool is_unique_follow_up(string input) {
  // No extra data structures
  sort(input.begin(), input.end());

  for (int i = 1; i < input.length(); i++) {
    if (input[i] == input[i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  string input1 = "abadada";
  string input2 = "aberty";
  string input3 = "  asety";

  assert(!is_unique(input1));
  assert(is_unique(input2));
  assert(!is_unique(input3));
  assert(!is_unique_follow_up(input1));
  assert(is_unique_follow_up(input2));
  assert(!is_unique_follow_up(input3));

  return 0;
}
