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
// URLify: Write a method to replace all spaces in a string with `%20`. You
// may assume that the string has sufficient space at the end to hold the
// additional characters, and that you are given the "true" length of the
// string.
//
// INPUT:
// Input:   "Mr John Smith   "
// Output:  "Mr%20John%20Smith"
string urlify(string input) {

  // TODO: Refactor needed
  int il = input.length();
  string result;

  if (input[0] != ' ') {
    result += input[0];
  }

  for (int i = 1; i < il - 1; i++) {
    if (input[i] == ' ') {
      if (input[i - 1] != ' ' && input[i + 1] != ' ') {
        result.append("%20");
      }
    } else {
      result += input[i];
    }
  }

  return result;
}

int main() {
  string input1 = "Mr John Smith   ";
  string expected1 = "Mr%20John%20Smith";
  string input2 = "Asd Asd Asd";
  string expected2 = "Asd%20Asd%20Asd";

  assert(urlify(input1) == expected1);
}
