// Driver program for CSCI 60 Homework 10; due Thursday 3/16/23
//
// The littleDriverProgram tests the Parity iterator you designed for HW10.
// Note that the class allows clients to insert 0, but this program doesn't
// because 0 is used as a sentinal value. Also note that the program assumes
// the user doesn't enter any non-ints and will throw an uncaught exception if
// the user provides the wrong input. (Test programs don't have to be robust!)
// 
// Do not upload this file; do use it in any way helpful to you!

#include <iostream>
#include "parity.h"

using namespace std;

void littleDriverProgram();

int main() {
  littleDriverProgram();
  return 0;
}

void littleDriverProgram() {
  Parity lists;
  cout << "Enter a list of ints, one per line, 0 to end:\n";
  int val;
  while (true) {
    cin >> val;
    if (val==0) break;
    lists.insert(val);
  }
  cout << "All contents, separated by parity:\n";
  cout << lists; 

  // TODO: write your own code to test iterator functionality as you go

  cout << "All contents in sorted order: ";
  for (auto e : lists) {
    cout << e << " ";
  }
  cout << endl;

  cout << "Sum of all contents: ";
  size_t sum = 0;
  for (Parity::iterator it=lists.begin(); it!=lists.end(); ++it) {
    sum += *it;
  }
  cout << sum << endl;

  cout << "Second entry: " << *(++lists.begin()) << endl;
}
