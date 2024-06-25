#include "sequence1.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;
using namespace coen79_lab3;

// Print each item
void printSequence(sequence &seq) {
  for (int i = 0; i < seq.size(); i++) {
    cout << seq.current() << " ";
    seq.advance();
  }
  seq.end();
  cout << endl;
}

// Print mean, standard deviation, sum. Then, print the content.
void printStats(sequence &seq) {
  cout << "Mean: " << seq.mean() << endl;
  cout << "StdDev: " << seq.standardDeviation() << endl;
  cout << "Sum: " << seq.summation(seq) << endl;
  seq.start();
  cout << "Contents: ";
  printSequence(seq);
  cout << endl;
}

//-------------MAIN INSTRUCTIONS-------------
// Create sequence object tester1
// Insert 1, 2, 3
// Printstats(tester1)
// Create sequence object tester2
// Insert 2, 3, 4
// Printstats(tester2)
// Sequence object tester3 = tester1+tester2
// Printstats(tester3)
// All following functions are called by tester3:
// Advance() - Printstats(tester3)
// Advance() - Printstats(tester3)
// Remove_front() – Printstats(tester3)
// Advance() - Printstats(tester3)
// Remove_front() – Printstats(tester3)
// Advance() - Printstats(tester3)
// Remove_current() – Printstats(tester3)
// Attach_back(14) – Printstats(tester3)

int main() {
  sequence tester1;
  tester1.insert(1);
  tester1.insert(2);
  tester1.insert(3);
  printStats(tester1);

  sequence tester2;
  tester2.insert(2);
  tester2.insert(3);
  tester2.insert(4);
  printStats(tester2);

  sequence tester3 = tester1 + tester2;
  printStats(tester3);

  tester3.advance();
  printStats(tester3);

  tester3.advance();
  printStats(tester3);

  tester3.remove_front();
  printStats(tester3);

  tester3.advance();
  printStats(tester3);

  tester3.remove_front();
  printStats(tester3);

  tester3.advance();
  printStats(tester3);

  tester3.remove_current();
  printStats(tester3);

  tester3.attach_back(14);
  printStats(tester3);
}
