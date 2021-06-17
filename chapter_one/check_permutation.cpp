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
// Check Permutation: Given two string, write a method to decide if one is a
// permutation of the other.
int check_permutation(string input1, string input2) {

  int len = input1.length();

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < input2.length(); j++) {
      if (input1[i] == input2[j]) {
        input2.erase(j, 1);
      }
    }
  }

  if (input2.length()) {
    return false;
  } else {
    return true;
  }
}

int main() {
  string input1_1 = "abada";
  string input2_1 = "adaba";
  string input1_2 = "asdwer";
  string input2_2 = "asdwwr";

  assert(check_permutation(input1_1, input2_1));
  assert(!check_permutation(input1_2, input2_2));
  assert(!check_permutation(input1_2, input2_1));

  return 0;
}
