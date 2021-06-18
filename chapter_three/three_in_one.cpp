#include "../lib/stack.h"
#include <bits/stdc++.h>
using namespace std;
//
//
//
//   ___ _              _             ____
//  / __| |_  __ _ _ __| |_ ___ _ _  |__ /
// | (__| ' \/ _` | '_ \  _/ -_) '_|  |_ \
//  \___|_||_\__,_| .__/\__\___|_|   |___/
//                |_|
//
// Three in one: Describe how you could use a single array to implement three
// stacks.
//
Stack *three_in_one(int index) {
  // Each element in array is a pointer to the top of a stack
  // Each stach is implemented similarly to a linked list
  const int LENGTH = 3;
  Stack *array[LENGTH];
  array[0] = new Stack(10), array[1] = new Stack(10), array[2] = new Stack(10);

  // make value of top of the stack `index` = 10
  array[index]->top = new StackNode(10);

  // return mutated stack `index`
  return array[index];
}

int main() {
  // Interact with the triple stack by giving an index for the stack you wish to
  // mutate
  int expected = 10;
  assert(three_in_one(1)->top->data == 10);
}
