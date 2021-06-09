//    ___             _   _             _   _                     _       _ _ _
//  / __|_ _ __ _ __| |_(_)_ _  __ _  | |_| |_  ___   __ ___  __| |___  (_)_ _|
//  |_ ___ _ ___ _(_)_____ __ __
// | (__| '_/ _` / _| / / | ' \/ _` | |  _| ' \/ -_) / _/ _ \/ _` / -_) | | '
// \  _/ -_) '_\ V / / -_) V  V /
//  \___|_| \__,_\__|_\_\_|_||_\__, |  \__|_||_\___| \__\___/\__,_\___|
//  |_|_||_\__\___|_|  \_/|_\___|\_/\_/
//                             |___/
//
// https://github.com/fabricio7p
//
// Here you'll find all solutions for Cracking the Code Interview.
// These are MY solutions, definelly NOT the best out there.
//
#include <bits/stdc++.h>
#include <bitset>
#include <vector>
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
bool chapter_one_is_unique(string input) {
  // Is Unique: implement an algorithm to determine if a string has all unique
  // characters. What if you cannot use additional data structures?
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

int chapter_one_check_permutation(string input1, string input2) {
  // Check Permutation: Given two string, write a method to decide if one is a
  // permutation of the other.
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

string chapter_one_urlify(string input, int len) {
  // URLify: Write a method to replace all spaces in a string with `%20`. You
  // may assume that the string has sufficient space at the end to hold the
  // additional characters, and that you are given the "true" length of the
  // string.
  //
  // INPUT:
  // Input:   "Mr John Smith   ", 13
  // Output:  "Mr%20John%20Smith"

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

bool chapter_one_palindrome_permutation(string input) {
  // Palindrome permutation: Given a string, write a function to check if it is
  // a permutation of a palindrome. A palindrome is a word or phrase that is the
  // same forwards and backwards. A permutation is a rearrangement of letters.
  // The palindrome does not need to be limited to just dictionary words.
  //
  // EXAMPLE
  //
  // Input:   tact coa
  // Output   true (permutations: "taco cat", "atco cta", etc.)

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

bool chapter_one_one_away(string s1, string s2) {
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

  return false;
}

int main() {
  assert(chapter_one_is_unique("abxktyolwqd"));
  assert(chapter_one_check_permutation("abadada", "abadada"));
  assert(chapter_one_urlify("Mr John Smith     ", 13) == "Mr%20John%20Smith");
  assert(chapter_one_palindrome_permutation("tactcoaoa"));

  return 0;
}
