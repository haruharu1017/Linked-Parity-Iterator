// Node implementation file for CSCI 60 Homework 10; due Thursday 3/16/23
//
// This is the same starter code from Homework 9. Add your list_insert_sorted 
// implementation from Homework 9 to test your iterator.
//
// Do not upload this file.

#include "node.h"

// overloaded << to print entire list
ostream& operator <<(ostream& out, const node * head) {
  if (head==nullptr) return out;
  return out << head->data() << " " << head->link();
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node*& head, node*& tail, int val) {
  head = new node(val,head);
  if (tail==nullptr) tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node*& head, node*& tail, int val) {
  node *temp = new node(val,nullptr);
  if (tail==nullptr) {
    head = tail = temp;
  } else {
    tail->set_link(temp);
    tail = tail->link();
  }
}

// iterates through list, keeping track of and then returning # nodes
size_t list_size(const node* head) {
  if (head==nullptr) return 0;
  return 1+list_size(head->link());
}

// iterates through list and returns true if given val is found, false otherwise
bool list_search(const node* head, int val) {
  if (head==nullptr) return false;
  if (head->data()==val) return true;
  return list_search(head->link(),val);
}

// TODO: copy your HW9 implementation of list_insert_sorted here
void list_insert_sorted(node*& head, node*& tail, int val)
{
  node* newnode = new node(val, nullptr);
  if(head==nullptr) head=tail=newnode;
  else if(val>=tail->data()){ 
    list_insert_tail(head,tail, val);
    } else if(val<=head->data()){
      list_insert_head(head, tail, val);
    }
  else{
    for(node* curr=head; curr!=nullptr; curr=curr->link())
    {
      if(val>=curr->data()){
        newnode->set_link(curr->link());
        curr->set_link(newnode);
      }
    }
  }
}
