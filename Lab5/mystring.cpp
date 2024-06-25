#include "mystring.h"
#include <cassert>
#include <cstdlib> // Provides size_t
#include <cstring>
#include <iostream>

using namespace coen79_lab5;

namespace coen79_lab5 {
// constructor
string::string(const char str[]) {
  current_length = strlen(str);
  allocated = current_length + 1;
  characters = new char[allocated];
  strncpy(characters, str, allocated);
}

// The string contains c and then the null character.
string::string(char c) {
  current_length = 1;
  allocated = current_length + 1;
  characters = new char[allocated]; // allocate space and place c
  characters[0] = c;
  characters[1] = '\0';
} // NEW FUNCTION 1

// The string becomes a copy of the source string.
string::string(const string &source) {
  // updating current length and allocated
  current_length = source.current_length;
  allocated = source.allocated;
  // creating new array and copy from source string
  characters = new char[source.current_length];
  strncpy(characters, source.characters, source.current_length);
}
// deconstructor
string::~string() {
  // set equal to zero
  current_length = 0;
  allocated = 0;
  // delete characters from the heap
  delete[] characters;
}

// MODIFICATION MEMBER FUNCTIONS

// addend has been catenated to the end of the string.
void string::operator+=(const string &addend) {
  current_length = current_length + addend.current_length;
  allocated = current_length + 1;
  // reserve space and copy string
  reserve(allocated);
  strncat(characters, addend.characters, addend.current_length);
}

// Postcondition: addend has been catenated to the end of the string.
void string::operator+=(const char addend[]) {
  current_length += strlen(addend);
  allocated = current_length + 1;
  // reserve space and copy addend[] to string
  reserve(allocated);
  strncat(characters, addend, strlen(addend));
}

// The single character addend has been catenated to the end of the string.
void string::operator+=(char addend) {
  current_length += 1;
  allocated = current_length + 1;
  // reserve space and copy addend to string and add null
  reserve(allocated);
  characters[current_length - 1] = addend;
  characters[current_length] = '\0';
}

// All functions will now work efficiently (without allocating new memory) until
// n characters are in the string.
void string::reserve(size_t n) {
  // create new heap array w size n then copy into array
  char *temp = new char[n];
  strncpy(temp, characters, current_length);
  allocated = n;
  // delete old characters and set to new array
  delete[] characters;
  characters = temp;
}

string &string::operator=(const string &source) {
  // if source is same as this string update current length and allocated and allocate space then copy source string in to characters
  if (this != &source) {
    current_length = source.current_length;
    allocated = source.allocated;
    characters = new char[source.current_length];
    strncpy(characters, source.characters, source.current_length);
  }
  return *this;
}

// Precondtion: position <= length()
// Postcondition: The source string is inserted into this string before the
// character at the given index.
void string::insert(const string &source, unsigned int position) {
  assert(position <= length());
  if (length() + source.current_length > allocated) // allocating more space
    reserve(length() + source.current_length);
  for (int i = length(); i > position; i--) // shift
    characters[i] = characters[i - 1];
  for (int i = 0; i < source.length(); i++) // inserting source characters
    characters[position + i] = source.characters[i];
  current_length += source.current_length;
}

// Precondition: (position + num) <= length( ).
// Postcondition: num characters are deleted from the sequence, starting at
// index position.
void string::dlt(unsigned int position, unsigned int num) {
  assert(position + num <= length());
  // Shifts every character after the deleted characters to the left.
  // Target character is overwritten and essentially deleted
  for (int i = position; i < current_length - num; i++)
    characters[i] = characters[i + num];
  current_length -= num;
}

// Precondition: position < length()
// Postcondtion: the character at the given position in the string is replaced
// with c.
void string::replace(char c, unsigned int position) {
  assert(position < length());
  characters[position] = c;
}

// Precondition: (position + source.length()) <= length()
// Postcondtion: the characters in this string starting at position are replaced
// with those in the source srting.
void string::replace(const string &source, unsigned int position) {
  assert(position + source.length() <= length());
  // Replaces every character from position to position + source.length()
  for (int i = 0; i < source.length(); i++)
    characters[position + i] = source.characters[i];
}

// CONSTANT MEMBER FUNCTIONS
size_t string::length() const { return current_length; }

char string::operator[](size_t position) const {
  assert(position < length());
  return characters[position];
}

int string::search(char c) const {
  // Searches for the first occurrence of the character c in the string and
  // returns index
  for (int i = 0; i < current_length; i++)
    if (characters[i] == c)
      return i;
  return -1;
}

int string::search(const string &substring) const {
  // Searches for the first occurrence of substring in this string.
  for (int i = 0; i < current_length; i++) {
    if (characters[i] == substring.characters[0]) {
      int j = 0;
      // Checks if the rest of the characters match
      while (characters[i + j] == substring.characters[j] &&
             j < substring.current_length) {
        j++;
      }
      if (j == substring.current_length) {
        return i;
      }
    }
  }
  return -1;
}

unsigned int string::count(char c) const {
  int count = 0;
  // Searches through every element to find c
  for (int i = 0; i < current_length; i++)
    if (characters[i] == c)
      count++;
  return count;
}

// FRIEND FUNCTIONS
std::ostream &operator<<(std::ostream &outs, const string &source) {
  // Iterates through source and places every character in outs
  for (int i = 0; i < source.current_length; i++) {
    outs << source.characters[i];
  }
  return outs;
}

bool operator==(const string &s1, const string &s2) {
  if (s1.length() != s2.length()) {
    return false;
  }
  // Checks every element of s1 and s2 for equality
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] != s2.characters[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const string &s1, const string &s2) {
  if (s1.length() != s2.length()) {
    return true;
  }
  // Iterates through each character in s1 and s2 to an inequality
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] != s2.characters[i]) {
      return true;
    }
  }
  return false;
}

bool operator>(const string &s1, const string &s2) {
  if (s1.length() > s2.length()) {
    return true;
  }
  // Iterates through every char in s1 to see if it is greater than every char
  // in s2
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] > s2.characters[i]) {
      return true;
    }
  }
  return false;
}

bool operator<(const string &s1, const string &s2) {
  if (s1.length() < s2.length()) {
    return true;
  }
  // Iterates through every char in s1 to see if it is less than every char in
  // s2
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] < s2.characters[i]) {
      return true;
    }
  }
  return false;
}

bool operator>=(const string &s1, const string &s2) {
  bool same = false;
  if (s1.length() > s2.length()) {
    return true;
  }
  // Iterates through every char in s1 to see if it is greater than  or equal to
  // every char in s2
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] > s2.characters[i]) {
      return true;
    } else if (s1.characters[i] == s2.characters[i]) {
      same = true;
    }
  }
  return same;
}

bool operator<=(const string &s1, const string &s2) {
  bool same = false;
  if (s1.length() < s2.length()) {
    return true;
  }
  // Iterates through every char in s1 to see if it is less than or equal to
  // every char in s2
  for (int i = 0; i < s1.length(); i++) {
    if (s1.characters[i] < s2.characters[i]) {
      return true;
    } else if (s1.characters[i] == s2.characters[i]) {
      same = true;
    }
  }
  return same;
}

// NON-MEMBER FUNCTIONS for the string class
string operator+(const string &s1, const string &s2) {
  string s3;
  // Puts s1 and s2 into s3
  s3 += s1;
  s3 += s2;
  return s3;
}

string operator+(const string &s1, const char addend[]) {
  string s3;
  // Puts s1 and addend into s3
  s3 += s1;
  s3 += addend;
  return s3;
}

std::istream &operator>>(std::istream &ins, string &target) {
  char *temp = new char[100];
  // ignores spaces at the front
  while (ins && isspace(ins.peek())) {
    ins.ignore();
  }
  ins >> temp;
  target = temp;
  return ins;
}
} // namespace coen79_lab5