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
// One Away: There are three types of edits that can be performed on strings:
// insert a character, remove a character, or replace a character. Given two
// strings, write a function to check if they are one edit (or zero edits)
// away.
//
// EXAMPLE
//
// pale,  ple   ->  true
// pales, pale  ->  true
// pale,  bale  ->  true
// pale,  bake  ->  false
bool one_away(string s1, string s2) {

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  int ld = abs(int(s1.length() - s2.length()));
  int mm = 0;
  int bigger = s1.length() > s2.length() ? s1.length() : s2.length();

  if (ld > 1) {
    return false;
  }

  for (int i = 0; i < bigger; i++) {
    // this is a crime, i know
    if (s1[i] != s2[i]) {
      mm++;
    }
  }

  if (ld == 1) {
    return mm == 1;
  } else if (ld == 0) {
    return mm <= 1;
  }

  return false;
}

int main() {
  string s1 = "pale";
  string s2 = "ale";

  assert(one_away(s1, s2));
}
