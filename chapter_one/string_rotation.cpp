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
// String Rotation: Assume you have a method `isSubstring` which checks if one
// word is a substring of another. Given two strings, s1 and s2, write code to
// check if s2 is a rotation of s1 using only one call to `isSubstring` (e.g.,
// "waterbottle" is a rotation of "erbottlewat").
bool string_rotation(string s1, string s2) {

  int index = 0;
  int len = s1.length();

  while (index < len) {
    char aux = s2[len - 1];
    s2.pop_back();
    s2 = aux + s2;

    if (s1 == s2) {
      return true;
    }

    index++;
  }

  return false;
}

int main() {
  string s1 = "waterbottle";
  string s2 = "erbottlewat";

  assert(string_rotation(s1, s2));
}
