/* Lab 3
   Will Zumbolo, Lydia Martin
   Febuary 1, 2024
*/

#include "sequence1.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3 {
// Constructor
sequence::sequence() {
  for (int i = 0; i < used; i++) {
    this->data[i] = data[i];
  }
  used = 0;
  current_index = 0;
}

bool sequence::is_item() const {
  if (current_index <= used) {
    return true;
  }
  return false;
}

// set iterator to 0
void sequence::start() { current_index = 0; }

// set iterator pointing to the last item
void sequence::end() {
  if (used != 0) {
    current_index = used - 1;
  } else {
    current_index = 0;
  }
}

// set iterator pointing to the last slot
void sequence::last() { current_index = CAPACITY; }
// increase the iterator value by 1
void sequence::advance() {
  if (current_index < used) {
    current_index++;
  }
}

// reduce the iterator value by 1
void sequence::retreat() {
  if (current_index > 0) {
    current_index--;
  }
}


void sequence::insert(const sequence::value_type &entry) {
  assert(is_item());
  //  shifting all items after (and including) current_index back one space
  for (int i = used; i > current_index; i--) {
    data[i] = data[i - 1];
  }
  // place entry at current and update used & current_index
  data[current_index] = entry;
  used++;
}

void sequence::insert_front(const sequence::value_type &entry) {
  assert(is_item());
  // shift everything back one space
  for (int i = used; i > 0; i--) {
    data[i] = data[i - 1];
  }
  // place entry at front and update used & current index
  data[0] = entry;
  current_index = 0;
  used++;
}

void sequence::attach(const sequence::value_type &entry) {
  assert(is_item());
  // shift
  for (int i = used; i > current_index; i--) {
    data[i] = data[i - 1];
  }
  // set entry as new current_index
  data[current_index] = entry;
  used++;
}

void sequence::attach_back(const sequence::value_type &entry) {
  assert(is_item());
  // attach entry to back and update used
  if (used < CAPACITY) {
    data[used] = entry;
    used++;
  }
}

void sequence::remove_current() {
  assert(is_item());
  // shift everything up one space, removing & replacing the current item
  for (int i = current_index; i < used; i++) {
    data[i] = data[i + 1];
  }
  if (used > 0) {
    used--;
  }
}

void sequence::remove_front() {
  assert(is_item());
  // shift everything up one space, removing & replacing the front item
  for (int i = 0; i < used; i++) {
    data[i] = data[i + 1];
  }
  if (used > 0) {
    used--;
  }
}

// return number of items
sequence::size_type sequence::size() const { return used; }

// return the item at the current position
sequence::value_type sequence::current() const {
  assert(is_item());
  return data[current_index];
}

// The value returned is the mean of the values stored in the sequence
double sequence::mean() const {
  value_type sum = 0.0;
  // find sum of all values
  for (int i = 0; i < used; i++) {
    sum += data[i];
  }
  return sum / used; // return mean
}

// standard deviation
double sequence::standardDeviation() const {
  value_type temp;
  value_type sqsum;
  for (int i = 0; i < used; i++) {
    temp = data[i] - mean();
    sqsum += temp * temp;
  }
  sqsum /= used;
  sqsum = sqrt(sqsum);
  return sqsum;
}

// sum
sequence::value_type sequence::summation(const sequence &s) {
  sequence::value_type sum;
  for (int i = 0; i < s.size(); i++) {
    sum += s.data[i];
  }
  return sum;
}

// return a new sequence
sequence operator+(sequence &lhs, sequence &rhs) {
  sequence result;
  result.start(); //all iterators reset to 0
  lhs.start();
  rhs.start();
  for (int i = 0; i < lhs.size(); i++) { //inserts lhs into new sequence
    result.attach_back(lhs.current()); //attaches lhs current to the back
    lhs.advance(); //iterator + 1
  }
  for (int i = 0; i < rhs.size(); i++) { //attaches rhs into the new sequence
    result.attach_back(rhs.current());
    rhs.advance();
  }
  return result; //new sequence
}

sequence operator+=(sequence &lhs, sequence &rhs) {
  rhs.start();
  for (int i = 0; i < rhs.size(); i++) { //adds items from rhs to lhs
    lhs.attach(rhs.current());
    rhs.advance();
  }
  return lhs;
}

// return the item at the index
sequence::value_type sequence::operator[](int index) const {
  return data[index];
}
} // namespace coen79_lab3