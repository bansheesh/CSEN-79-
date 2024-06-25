#include "keyed_bag.h"
#include <iostream>

using namespace std;
using namespace coen79_lab4;

void Insert(const int val, const string &key, keyed_bag &kb) {
  // Inserting <val> with key "<key>"
  kb.insert(val, key);
  cout << "Inserting " << val << " with key \"" << key << "\"." << endl;
}

void Erase(const string &key, keyed_bag &kb) {
  // Erasing "<key>".
  kb.erase(key);
  cout << "Erasing \"" << key << "\"." << endl;
}

void Get(const string &key, const keyed_bag &kb) {
  // Value for "<key>": <value>
  cout << "Value for \"" << key << "\": " << kb.get(key) << endl;
}

void Has(const string &key, const keyed_bag &kb) {
  // Has <key>: <count>
  cout << "Has " << key << ": " << kb.has_key(key) << endl;
}

void Count(const int val, const keyed_bag &kb) {
  // Number of <value>'s in the bag: <count>
  cout << "Number of " << val << "'s in the bag: " << kb.count(val) << endl;
}

void bSize(const keyed_bag &kb) {
  // Bag size: <size>
  cout << "Bag size: " << kb.size() << endl;
}

//-----------MAIN INSTRUCTIONS------------
// Create Keyed_bag objects kb1, kb2 and kb3
// Insert (5, “five”), (3,”three”),(1,”one”) to kb1
// Get (“one”), (“three”), (“five”) from kb1
// Has (“five”), (“two”) from kb1
// bSize(kb1) -> Erase(“five”) from kb1 -> bSize(kb1)
// Has (“five”), (“three”) from kb1
// Insert (-8, “neg_eight”) to kb1
// bSize(kb1)
// Has (“neg_eight”) from kb1 -> Get (“neg_eight”) from kb1
// Count(9), (1) from kb1
// Insert (1, “ONE”) to kb1
// Count(1) from kb1
// Insert(7, “seven”),(9,”nine”),(11,”eleven”) to kb1
// bSize(kb1) -> Erase(“eleven”) from kb1 -> bSize(kb1) -> Erase(“ONE”) from kb1
// -> bSze(kb1) Insert(1,”1”),(2,”2”),(3,”3”),(4,”4”),(5,”5”) to kb2
/// kb3=kb1+kb2
// bSize(kb3)
// Has (“1”), (“one”), (“turkey”) from kb3
// Count(1), (9), (-5) from kb3
// Get (“three”) from kb3
// cout << "Erasing all of kb2." << endl;
// kb2.erase()
// bSize(kb2)
// Insert(22,"I'm feelin’”) to kb2
// Get("I'm feelin’”) from kb2

int main() {
  keyed_bag kb1, kb2, kb3;
  Insert(5, "five", kb1);
  Insert(3, "three", kb1);
  Insert(1, "one", kb1);
  Get("one", kb1);
  Get("three", kb1);
  Get("five", kb1);
  Has("five", kb1);
  Has("two", kb1);
  bSize(kb1);
  Erase("five", kb1);
  bSize(kb1);
  Has("five", kb1);
  Has("three", kb1);
  Insert(-8, "neg_eight", kb1);
  bSize(kb1);
  Has("neg_eight", kb1);
  Get("neg_eight", kb1);
  Count(9, kb1);
  Count(1, kb1);
  Insert(1, "ONE", kb1);
  Count(1, kb1);
  Insert(7, "seven", kb1);
  Insert(9, "nine", kb1);
  Insert(11, "eleven", kb1);
  bSize(kb1);
  Erase("eleven", kb1);
  bSize(kb1);
  Erase("ONE", kb1);
  bSize(kb1);
  Insert(1, "1", kb2);
  Insert(2, "2", kb2);
  Insert(3, "3", kb2);
  Insert(4, "4", kb2);
  Insert(5, "5", kb2);
  kb3 = kb1 + kb2;
  bSize(kb3);
  Has("1", kb3);
  Has("one", kb3);
  Has("turkey", kb3);
  Count(1, kb3);
  Count(9, kb3);
  Count(-5, kb3);
  Get("three", kb3);
  cout << "Erasing all of kb2." << endl;
  kb2.erase();
  bSize(kb2);
  Insert(22, "I'm feelin’", kb2);
  Get("I'm feelin’", kb2);
}