// Starter iterator interface file for CSCI 60 Homework 10; due Thursday 3/16/23
// 
// Design this P_iterator class so it works with the other Parity files.
// You may define your constructor(s) inline below, but all other functions
// should be declared in this file and implemented in p_iterator.cpp.
// Turn this in with p_iterator.cpp and parity.cpp.
// Mengxi He

#ifndef P_ITERATOR_H
#define P_ITERATOR_H

#include "node.h"

class P_iterator {
public:
	// TODO: define and implement *, ++, ==, !=
	P_iterator(node* headE = nullptr, node* headO = nullptr) : currE(headE), currO(headO) {}
	int operator * () const;
	P_iterator operator++();
	bool operator==(const P_iterator& rhs) const;
	bool operator!=(const P_iterator& rhs) const;

private:
	node* currE;
	node* currO;
	bool parity;
};

#endif