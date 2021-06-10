//   ___             _   _             _   _
//  / __|_ _ __ _ __| |_(_)_ _  __ _  | |_| |_  ___
// | (__| '_/ _` / _| / / | ' \/ _` | |  _| ' \/ -_)
//  \___|_| \__,_\__|_\_\_|_||_\__, |  \__|_||_\___|
//             _       _     _ |___/         _
//  __ ___  __| |___  (_)_ _| |_ ___ _ ___ _(_)_____ __ __
// / _/ _ \/ _` / -_) | | ' \  _/ -_) '_\ V / / -_) V  V /
// \__\___/\__,_\___| |_|_||_\__\___|_|  \_/|_\___|\_/\_/
//
//
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

string chapter_one_string_compression(string s1) {
  // String compression: Implement a method to perform basic string compression
  // using the counts of repeated characters. For example, the string
  // aabcccccaaa would become a2b1c5a3. If the `compressed` string would not
  // become smaller than the original string, your method should return the
  // original string. you can assume the string has only uppercase and lowercase
  // letters (a-z).

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

vector<vector<int>> chapter_one_rotate_matrix(vector<vector<int>> m) {
  // Rotate Matrix: Given an image represented by an NxN matrix, where each
  // pixel in the image is 4 bytes, write a method to rotate the image by 90
  // degrees. Can you do this in place?

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

vector<vector<int>> chapter_one_zero_matrix(vector<vector<int>> m) {
  // Zero Matrix: Write an algorithm such that if an element in an MxN matrix is
  // 0, its entire row and column are set to 0.

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

bool chapter_one_string_rotation(string s1, string s2) {
  // String Rotation: Assume you have a method `isSubstring` which checks if one
  // word is a substring of another. Given two strings, s1 and s2, write code to
  // check if s2 is a rotation of s1 using ony one call to `isSubstring` (e.g.,
  // "waterbottle" is a rotation of "erbottlewat").

  return true;
}

int main() {
  assert(chapter_one_is_unique("abxktyolwqd"));
  assert(chapter_one_check_permutation("abadada", "abadada"));
  assert(chapter_one_urlify("Mr John Smith     ", 13) == "Mr%20John%20Smith");
  assert(chapter_one_palindrome_permutation("tactcoaoa"));
  assert(chapter_one_one_away("abadada", "abadaxa"));
  assert(chapter_one_string_compression("aabcccccaaa") == "a2b1c5a3");
  vector<vector<int>> rotated = {
      {13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}};
  assert(chapter_one_rotate_matrix(
             {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}) ==
         rotated);
  vector<vector<int>> zeroed = {
      {0, 0, 0, 0}, {1, 2, 0, 4}, {6, 1, 0, 8}, {9, 2, 0, 1}};
  assert(chapter_one_zero_matrix(
             {{1, 2, 0, 4}, {1, 2, 3, 4}, {6, 1, 6, 8}, {9, 2, 1, 1}}) ==
         zeroed);
  assert(chapter_one_string_rotation("waterbottle", "erbottlewat"));

  return 0;
}
