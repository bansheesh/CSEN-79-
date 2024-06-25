#include "keyed_bag.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4 {
keyed_bag::keyed_bag() {
  // Sets each element of data to 0
  for (int i = 0; i < used; i++) {
    keys[i] = "";
    used = 0;
  }
}

void keyed_bag::erase() {
  // Sets each element of data to 0
  for (int i = 0; i < used; i++) {
    keys[i] = "";
    data[i] = 0;
  }
  used = 0;
}

bool keyed_bag::erase(const key_type &key) {
  // Iterates through the array of keys looking for the key
  for (int i = 0; i < used; i++) {
    if (keys[i] == key) {
      // If the key is found, every element after the key is shifted left to
      // essentially overwrite it
      for (int j = i; j < used; j++) {
        keys[j] = keys[j + 1];
        data[j] = data[j + 1];
      }
      if (used > 0) {
        used--;
      }
      return true;
    }
  }
  return false;
}

void keyed_bag::insert(const value_type &entry, const key_type &key) {
  assert(size() < CAPACITY);
  // If it isn't already in there, the key + data is added to the end
  if (!has_key(key)) {
    keys[used] = key;
    data[used] = entry;
    used++;
  }
}

void keyed_bag::operator+=(const keyed_bag &addend) {
  assert(size() + addend.size() <= CAPACITY);
  // Iterates through the addend's keys and adds them to the bag
  for (int i = 0; i < addend.used; i++) {
    if (!has_key(addend.keys[i])) {
      keys[used] = addend.keys[i];
      data[used] = addend.data[i];
      used++;
    }
  }
}

bool keyed_bag::has_key(const key_type &key) const {
  // Iterates through the array of keys looking for the key
  for (int i = 0; i < used; i++) {
    if (keys[i] == key) {
      return true;
    }
  }
  return false;
}

keyed_bag::value_type keyed_bag::get(const key_type &key) const {
  assert(has_key(key));
  // Iterates through the array of keys looking for the key
  for (int i = 0; i < used; i++) {
    if (keys[i] == key) {
      return data[i];
    }
  }
  return 0; // This is just to make the warning go away, it should never even
            // reach this point b/c of precondition
}
// Returns # of elements in the bag
keyed_bag::size_type keyed_bag::size() const { return used; }

keyed_bag::size_type keyed_bag::count(const value_type &target) const {
  size_type count = 0;
  // Iterates through the array of data looking for the target
  // and adds to count every time target is found
  for (int i = 0; i < size(); i++) {
    if (data[i] == target) {
      ++count;
    }
  }
  return count;
}

bool keyed_bag::hasDuplicateKey(const keyed_bag &otherBag) const {
  // Iterates through the array of keys looking for duplicates
  for (int i = 0; i < otherBag.size(); i++) {
    if (has_key(otherBag.keys[i])) {
      return true;
    }
  }
  return false;
}

keyed_bag operator+(const keyed_bag &b1, const keyed_bag &b2) {
  assert(b1.size() + b2.size() <= keyed_bag::CAPACITY);
  keyed_bag b3;
  // += operator does most of the heavy lifting here (checks for duplicates)
  b3 += b1;
  b3 += b2;
  return b3;
}
} // namespace coen79_lab4
