// FILE: sequence.cpp
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//
//   COEN 79
//   --- Behnam Dezfouli, COEN, SCU ---
//
//
// INVARIANT for the sequence class
//   1. The number of items in the sequence is stored in the member variable
//   "many_nodes"
//
//   2. For an empty sequence, we do not care what is stored in any of data and
//   head_ptr
//       and tail_ptr point to NULL; for a non-empty sequence, the items stored
//       in the sequence can be accessed using head_ptr and tail_ptr and we
//       don't care what is stored in the rest of the data.
//
//   3. If there is a current item, then it lies in *cursor; if there is no
//      current item, then cursor* equals NULL.
//
//   4. If there is a previous item, then it lies in precursor*.  If there is no
//   previous
//        item, then precursor equals NULL.

#include "sequence.h" //header file for class
#include "node.h"     // provides node class
#include <algorithm>  //provides copy function
#include <cassert>    //for assert function
#include <iostream>

using namespace std; // For copy function

namespace coen79_lab6 {

// Default private member variable initialization function.
void sequence::init() {
  // Initializing pointers to NULL
  head_ptr = NULL;
  tail_ptr = NULL;
  cursor = NULL;
  precursor = NULL;
  // Initializiing many_nodes (or our counter) to 0
  many_nodes = 0;
}

// CONSTRUCTOR IMPLEMENTATION for default constructor
sequence ::sequence() { init(); }

// Copy Constructor
sequence ::sequence(const sequence &source) {
  init();
  *this = source;
}

// deconstructor
sequence::~sequence() {
  // delete all nodes and set all pointers = NULL
  list_clear(head_ptr);
  head_ptr = NULL;
  tail_ptr = NULL;
  cursor = NULL;
  precursor = NULL;
  many_nodes = 0;
}

// MODIFICATION MEMBER FUNCTIONS

// Postcondition: The precursor and cursor are adjusted such that the first item
// in the sequence becomes the current item (but if the sequence is empty, then
// there is no current item).
void sequence::start() {
  cursor = head_ptr;
  precursor = NULL;
}

// Postcondition: The precursor and cursor are adjusted such that the last item
// in the sequence becomes the current item (but if the sequence is empty, then
// there is no current item).
void sequence::end() {
  if (many_nodes == 0) // if empty return
    return;
  cursor = tail_ptr;        // set cursor to the end
  if (head_ptr == tail_ptr) // if only one node, precursor = NULL
    precursor = NULL;
  else // precursor points to second to last node
    precursor = list_locate(head_ptr, many_nodes - 1);
}

// Precondition: is_item returns true.
// Postcondition: If the current item was already the last item in the sequence,
// then there is no longer any current item. Otherwise, the new current item is
// the item immediately after the original current item.
void sequence::advance() {
  assert(is_item());
  // move precursor and cursor to next node
  precursor = cursor;
  cursor = cursor->link();
}

// Postcondition: A new copy of entry has been inserted in the sequence before
// the current item. If there was no current item, then the new entry has been
// inserted at the front of the sequence. In either case, the newly inserted
// item is now the current item of the sequence.
void sequence::insert(const value_type &entry) {
  if (!is_item() || precursor == NULL) {
    list_head_insert(head_ptr, entry); //insert at front
    if (tail_ptr == NULL) //if no tail element, set tail = head
      tail_ptr = head_ptr;
    cursor = head_ptr;
    precursor = NULL;
    many_nodes++;
  } else {
    list_insert(precursor, entry); //insert into precursor
    cursor = precursor->link();
    many_nodes++;
  }
}

// Postcondition: A new copy of entry has been inserted in the sequence after
// the current item. If there was no current item, then the new entry has been
// attached to the end of the sequence. In either case, the newly inserted item
// is now the current item of the sequence.
void sequence::attach(const value_type &entry) {
  if (head_ptr == NULL) { // if empty insert head and orient pointers so that
                          // cursor = head_ptr
    list_head_insert(head_ptr, entry);
    tail_ptr = head_ptr;
    cursor = head_ptr;
    precursor = NULL;
    
  } else if (cursor == NULL) { // if cursor = NULL, insert at end of list
    list_insert(tail_ptr, entry);
    cursor = tail_ptr->link();
    //precursor = tail_ptr;
    tail_ptr = tail_ptr->link();
    
  } else { // insert after cursor, update pointers
    list_insert(cursor, entry);
    precursor = cursor;
    cursor = cursor->link();
    if (cursor->link() == NULL) // if next node is NULL, set tail_ptr to cursor
      tail_ptr = cursor;
    
  }
  many_nodes++;
}

void sequence::operator=(const sequence &source) {
  if (this == &source) // if source and this are the same, do nothing
    return;
  list_copy(source.head_ptr, head_ptr, tail_ptr); // copy source
  many_nodes = source.many_nodes;
  start();                        // set everything to NULL
  node *temp = source.head_ptr;   // temporary node
  while (temp != source.cursor) { // iterate until source.cursor
    advance();
    temp = temp->link();
  }
}

// Precondition: is_item returns true.
// Postcondition: The current item has been removed from the sequence, and the
// item after this (if there is one) is now the new current item.
void sequence::remove_current() {
  assert(is_item());
  if (cursor == head_ptr) { // if cursor is at head
    if (head_ptr ==
        tail_ptr) { // if only one node, remove it and set everything to NULL
      list_head_remove(head_ptr);
      head_ptr = NULL;
      tail_ptr = NULL;
      cursor = NULL;
      precursor = NULL;
    } else { // remove head and set cursor to new head
      list_head_remove(head_ptr);
      cursor = head_ptr;
      precursor = NULL;
    }
  } else if (cursor == tail_ptr) { // if at end
    tail_ptr = precursor;          // set tail_ptr to precursor
    cursor = cursor->link();
    list_remove(precursor); // delete node after precursor
  } else {                  // remove node, set cursor to next node
    cursor = cursor->link();
    list_remove(precursor);
  }
  many_nodes--;
}

// CONSTANT MEMBER FUNCTIONS

// Postcondition: Returns the number of items in the sequence.
sequence::size_type sequence::size() const { return many_nodes; }

// Postcondition: A true return value indicates that there is a valid "current"
// item that may be retrieved by activating the
bool sequence::is_item() const {
  if (cursor == NULL) // check if cursor points to anything
    return false;
  else
    return true;
}

// Postcondition: Returns the current item in the sequence.
sequence::value_type sequence::current() const {
  assert(is_item());
  return cursor->data(); // return data in node
}
} // namespace coen79_lab6
