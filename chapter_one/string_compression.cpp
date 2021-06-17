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
// String compression: Implement a method to perform basic string compression
// using the counts of repeated characters. For example, the string
// aabcccccaaa would become a2b1c5a3. If the `compressed` string would not
// become smaller than the original string, your method should return the
// original string. you can assume the string has only uppercase and lowercase
// letters (a-z).
string string_compression(string s1) {

  char last = s1[0];
  int occur = 1;
  string result;

  for (int i = 1; i < s1.length(); i++) {
    if (s1[i] == last) {
      occur++;
      if (i == s1.length() - 1) {
        result += last + to_string(occur);
        break;
      }
    } else {
      result += last + to_string(occur);
      last = s1[i];
      occur = 1;
    }
  }

  return result;
}

int main() {
  string input = "aabcccccaaa";
  string expected = "a2b1c5a3";

  assert(string_compression(input) == expected);
}
