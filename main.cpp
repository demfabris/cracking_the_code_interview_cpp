//   ___             _   _             _   _
//  / __|_ _ __ _ __| |_(_)_ _  __ _  | |_| |_  ___
// | (__| '_/ _` / _| / / | ' \/ _` | |  _| ' \/ -_)
//  \___|_| \__,_\__|_\_\_|_||_\__, |  \__|_||_\___|
//             _       _     _ |___/         _
//  __ ___  __| |___  (_)_ _| |_ ___ _ ___ _(_)_____ __ __
// / _/ _ \/ _` / -_) | | ' \  _/ -_) '_\ V / / -_) V  V /
// \__\___/\__,_\___| |_|_||_\__\___|_|  \_/|_\___|\_/\_/
//
// https://github.com/fabricio7p
//
// Here you'll find all solutions for Cracking the Code Interview.
// These are MY solutions, definelly NOT the best out there.
//
#include "lib/chapter_one.h"
#include "lib/chapter_two.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  bool chap_one = false;
  bool chap_two = false;
  bool all = true;

  for (int i = 0; i < argc; i++) {
    if (argv[i] == string("--chapter-one") || argv[i] == string("-c1")) {
      cout << "Running chapter one solutions" << endl;

      chap_one = true;
      all = false;
      continue;
    }

    if (argv[i] == string("--chapter-two") || argv[i] == string("-c2")) {
      cout << "Running chapter two solutions" << endl;

      chap_two = true;
      all = false;
      continue;
    }
  }

  if (all) {
    cout << "Running all solutions" << endl;

    chapter_one();
    chapter_two();

    return 0;
  }

  if (chap_one)
    chapter_one();
  if (chap_two)
    chapter_two();

  return 0;
}
