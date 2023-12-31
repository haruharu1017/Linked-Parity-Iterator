// Updated parity interface file for CSCI 60 Homework 10; due Thursday 3/16/23
//
// This interface is a slight modification from the Parity interface from 
// Homework 9, with an additional include directive and declarations for
// the new iterator. Implement begin and end in parity.cpp.
// 
// Do not modify or upload this file.

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
using std::ostream;

#include "node.h"
#include "p_iterator.h" // NEW
#include <climits>

class Parity {
public:
  // constructors and functions to override for dynamic memory management
  Parity();
  Parity(const Parity& other);
  ~Parity();
  Parity& operator=(const Parity& rhs);

  // mutator
  void insert(int val); 

  // accessors
  int min() const;
  int max() const;
  friend ostream& operator <<(ostream& out, const Parity& lists);

  // NEW: iterator typedef and begin/end function declarations
  typedef P_iterator iterator;
  iterator begin();
  iterator end();

private:
  node * headE;
  node * tailE;
  size_t nE;
  node * headO;
  node * tailO;
  size_t nO;
  // INVARIANTS: headE and tailE address the first and last dynamic nodes in a
  //             linked list of the nE even ints that have been inserted;
  //             headO and tailO address the first and last dynamic nodes in a
  //             linked list of the nO odd ints that have been inserted;
  //             both lists store values in non-decreasing order.
};

#endif
