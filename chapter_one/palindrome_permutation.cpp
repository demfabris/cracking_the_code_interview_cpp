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
// Palindrome permutation: Given a string, write a function to check if it is
// a permutation of a palindrome. A palindrome is a word or phrase that is the
// same forwards and backwards. A permutation is a rearrangement of letters.
// The palindrome does not need to be limited to just dictionary words.
//
// EXAMPLE
//
// Input:   tact coa
// Output   true (permutations: "taco cat", "atco cta", etc.)
bool palindrome_permutation(string input) {

  sort(input.begin(), input.end());
  vector<int> v;

  char last = input[0];
  int occur = 0;
  for (int i = 1; i < input.length(); i++) {
    if (input[i] == last) {
      occur++;
    } else {
      v.push_back((occur + 1) % 2);
      last = input[i];
      occur = 0;
    }
  }

  int odd = 0;
  for (int n : v) {
    if (n == 1) {
      odd++;
    }
  }

  if (input.length() % 2 != 0 && odd != 1) {
    return false;
  } else if (input.length() % 2 == 0 && odd % 2 != 0) {
    return false;
  }

  return true;
}

int main() {
  string input = "taco cat";
  assert(palindrome_permutation(input));
}
