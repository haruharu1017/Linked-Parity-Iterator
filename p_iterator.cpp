// Iterator implementation file for CSCI 60 Homework 10; due Thursday 3/16/23
// 
// All non-constructor functions in your P_iterator class must be defined here.
// Turn this in with p_iterator.h and parity.cpp.
// 
// Mengxi He

#include "p_iterator.h"

// TODO: Implement your P_iterator member functions here
int P_iterator::operator *() const
{
	if (currE == nullptr)
	return currO->data();
	else if (currO == nullptr)
	return currE->data();
	else{
		if (currE->data() < currO->data())
		return currE->data();
		else
		return currO->data();
	}
}

P_iterator P_iterator::operator ++()
{
	if (currE != nullptr && currO != nullptr){
		if(currE->data() < currO->data())
		currE = currE->link();
		else
		currO = currO->link();
	}
	else if (currE == nullptr && currO != nullptr)
	currO = currO->link();
	else if (currO == nullptr && currE != nullptr)
	currE = currE->link();
	return *this;
}

bool P_iterator::operator!=(const P_iterator& rhs) const{
    return (currE!=rhs.currE || currO!=rhs.currO);
}

bool P_iterator::operator==(const P_iterator& rhs) const{
    return (currE==rhs.currE && currO==rhs.currO);
}