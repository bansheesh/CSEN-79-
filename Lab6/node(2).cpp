// FILE: node.cpp
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL and size_t
#include <iostream> // Provides cout and cin

using namespace std;

namespace coen79_lab6 {
// LIST TOOLKIT

// Library facilities used: cstdlib
size_t list_length(const node *head_ptr) {
  const node *cursor;
  size_t answer;

  answer = 0;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    ++answer;

  return answer;
}

void list_head_insert(node *&head_ptr, const node::value_type &entry) {
  head_ptr = new node(entry, head_ptr);
}

void list_insert(node *previous_ptr, const node::value_type &entry) {
  node *insert_ptr;

  insert_ptr = new node(entry, previous_ptr->link());
  previous_ptr->set_link(insert_ptr);
}

// Library facilities used: cstdlib
node *list_search(node *head_ptr, const node::value_type &target) {
  node *cursor;

  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    if (target == cursor->data())
      return cursor;

  return NULL;
}

// Library facilities used: cstdlib
const node *list_search(const node *head_ptr, const node::value_type &target) {
  const node *cursor;

  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    if (target == cursor->data())
      return cursor;

  return NULL;
}

// Library facilities used: cassert, cstdlib
node *list_locate(node *head_ptr, size_t position) {
  node *cursor;
  size_t i;

  assert(0 < position);
  cursor = head_ptr;
  for (i = 1; (i < position) && (cursor != NULL); i++)
    cursor = cursor->link();

  return cursor;
}

// Library facilities used: cassert, cstdlib
const node *list_locate(const node *head_ptr, size_t position) {
  const node *cursor;
  size_t i;

  assert(0 < position);
  cursor = head_ptr;
  for (i = 1; (i < position) && (cursor != NULL); i++)
    cursor = cursor->link();

  return cursor;
}

void list_head_remove(node *&head_ptr) {
  node *remove_ptr;

  remove_ptr = head_ptr;
  head_ptr = head_ptr->link();
  delete remove_ptr;
}

void list_remove(node *previous_ptr) {
  node *remove_ptr;

  remove_ptr = previous_ptr->link();
  previous_ptr->set_link(remove_ptr->link());
  delete remove_ptr;
}

// Library facilities used: cstdlib
void list_clear(node *&head_ptr) {
  while (head_ptr != NULL)
    list_head_remove(head_ptr);
}

// Library facilities used: cstdlib
void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr) {
  head_ptr = NULL;
  tail_ptr = NULL;

  // Handle the case of the empty list.
  if (source_ptr == NULL)
    return;

  // Make the head node for the newly created list, and put data in it.
  list_head_insert(head_ptr, source_ptr->data());
  tail_ptr = head_ptr;

  // Copy the rest of the nodes one at a time, adding at the tail of new list.
  source_ptr = source_ptr->link();
  while (source_ptr != NULL) {
    list_insert(tail_ptr, source_ptr->data());
    tail_ptr = tail_ptr->link();
    source_ptr = source_ptr->link();
  }
}

// IMPLEMENT THE FOLLOWING FUNCTIONS

void list_piece(node *start_ptr, node *end_ptr, node *&head_ptr,
                node *&tail_ptr) {
  head_ptr = NULL;
  tail_ptr = NULL;

  if (start_ptr == NULL || start_ptr == end_ptr) {
    return;
  }
  list_head_insert(head_ptr, start_ptr->data());
  tail_ptr = head_ptr;
  while (start_ptr != NULL && start_ptr->link() != end_ptr) {
    start_ptr = start_ptr->link();
    list_insert(tail_ptr, start_ptr->data());
    tail_ptr = tail_ptr->link();
  }
}

size_t list_occurrences(node *head_ptr, const node::value_type &target) {
  node *temp;
  temp = head_ptr;
  size_t count = 0;
  while (temp != NULL) {
    if (temp->data() == target) {
      count++;
    }
    temp = temp->link();
  }
  return count;
}

void list_insert_at(node *&head_ptr, const node::value_type &entry,
                    size_t position) {
  assert(position > 0 && position <= list_length(head_ptr) + 1);
  node *temp;
  temp = head_ptr;
  if (position == 1) {
    list_head_insert(head_ptr, entry);
  } else {
    for (size_t i = 1; i < position - 1; i++) {
      temp = temp->link();
    }
    list_insert(temp, entry);
  }
}

node::value_type list_remove_at(node *&head_ptr, size_t position) {
  assert(position > 0 && position <= list_length(head_ptr));
  node *temp;
  temp = head_ptr;
  node::value_type answer;
  if (position == 1) {
    answer = head_ptr->data();
    list_head_remove(head_ptr);
  } else {
    for (size_t i = 1; i < position - 1; i++) {
      temp = temp->link();
    }
    answer = temp->link()->data();
    list_remove(temp);
  }
  return answer;
}

node *list_copy_segment(node *head_ptr, size_t start, size_t finish) {
  assert(start > 0 && start <= list_length(head_ptr));
  // assert(finish > 0 && finish <= list_length(head_ptr));
  node *temp;
  temp = head_ptr;
  node *answer;
  list_piece(list_locate(head_ptr, start), list_locate(head_ptr, finish),
             answer, temp);
  return answer;
}

void list_print(const node *head_ptr) {
  const node *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
    if (cursor->link() == NULL) {
      cout << cursor->data();
    } else {
      cout << cursor->data() << ", ";
    }
  }
  cout << endl;
}

void list_remove_dups(node *head_ptr) {
  node *temp;
  temp = head_ptr;
  node *temp2;
  for (size_t i = 0; i < list_length(head_ptr); i++) {
    temp2 = temp;
    for (size_t j = i; j < list_length(head_ptr) - 1; j++) {
      if (temp->data() == temp2->link()->data()) {
        list_remove(temp2);
        j--;
      } else {
        temp2 = temp2->link();
      }
    }
    temp = temp->link();
  }
}

node *list_detect_loop(node *head_ptr) {
  if (head_ptr == NULL || head_ptr->link() == NULL) {
    return NULL;
  }

  node *slowPointer = head_ptr, *fastPointer = head_ptr;

  while (slowPointer != NULL && fastPointer != NULL &&
         fastPointer->link() != NULL) {
    slowPointer = slowPointer->link();
    fastPointer = fastPointer->link()->link();
    if (slowPointer == fastPointer)
      break;
  }

  if (slowPointer != fastPointer)
    return NULL;

  slowPointer = head_ptr;
  while (slowPointer != fastPointer) {
    slowPointer = slowPointer->link();
    fastPointer = fastPointer->link();
  }

  return slowPointer;
}

} // namespace coen79_lab6
