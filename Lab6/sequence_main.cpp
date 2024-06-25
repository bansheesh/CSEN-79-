#include <iostream>
#include "sequence.h"

using namespace std;
using coen79_lab6::sequence;

void printSequence(sequence &s) {
  sequence seq(s);
  seq.start();
  // Loop to print the sequence.
  while(seq.is_item()) {
    cout << seq.current() << " ";
    seq.advance();
  }
  cout << endl;
}

int main(int argc, const char * argv[]){
  
  sequence seq1, seq2;
  
  //Testing attach
  seq1.attach(42);
  printSequence(seq1);
  seq1.attach(25);
  printSequence(seq1);
  seq1.attach(2);
  printSequence(seq1);

  //testing insert
  seq1.insert(9);
  printSequence(seq1);
  seq1.insert(17);
  printSequence(seq1);
  seq1.attach(13);
  printSequence(seq1);
  
  //End/Start/Middle Removal Test
  
  cout << " *** End Removal Test *** " << endl; 
  seq1.end();
  if (seq1.is_item())
    seq1.remove_current();
  printSequence(seq1);

  cout << " *** Start Removal Test *** " << endl;
  seq1.start();
  if (seq1.is_item())
    seq1.remove_current();
  printSequence(seq1);
  
  cout << " *** Middle Removal Test *** " << endl;
  seq1.start();
  seq1.advance();
  if (seq1.is_item())
    seq1.remove_current();
  printSequence(seq1);

  cout << " *** First Assignment Test *** " << endl;
  seq2 = seq1;
  seq1.attach(5);
  printSequence(seq1);
  printSequence(seq2);
  seq2.insert(18);
  seq2.attach(92);
  printSequence(seq2);
  
  //  More Assignment Tests
  cout << " *** More Assignment Tests *** " << endl;
  sequence seqA, seqEmpty, seqOneItem, seqTenItems;
  for(int i = 0;i < 5;i++)
    seqA.attach(i);
  seqOneItem.attach(1.001);
  for(int i = 0;i < 10;i++)
    seqTenItems.attach(i);
  printSequence(seqA);
  seqA = seqEmpty;
  printSequence(seqA);
  seqA = seqOneItem;
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;
  seqOneItem.advance();
  seqA = seqOneItem;
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;
  seqTenItems.start();
  seqA = seqTenItems;
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;
  for(int i = 0; i < 4; ++i)
    seqTenItems.advance();
  seqA = seqTenItems;
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;
  seqTenItems.end();
  seqA = seqTenItems; 
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;
  seqTenItems.advance();
  seqA = seqTenItems;
  printSequence(seqA);
  cout << "Is item: " << seqA.is_item() << endl;

  // Lab Example
  cout << " *** Lab Example *** " << endl;
  sequence labsequence;
  cout << "Size: " << labsequence.size() << endl;
  cout << "Is_Item: " << labsequence.is_item() << endl;
  labsequence.insert(12);
  printSequence(labsequence);
  labsequence.insert(17);
  printSequence(labsequence);
  labsequence.advance();
  cout << "Is_Item: " << labsequence.is_item() << endl;
  labsequence.insert(7);
  printSequence(labsequence);
  labsequence.attach(4);
  printSequence(labsequence);
  labsequence.advance();
  labsequence.advance();
  cout << "Size: " << labsequence.size() << endl;
  cout << "Is_Item: " << labsequence.is_item() << endl;
  labsequence.insert(3);
  printSequence(labsequence);
  
  labsequence.advance();
  labsequence.remove_current();
  printSequence(labsequence);
  labsequence.advance();
  labsequence.remove_current();
  printSequence(labsequence);
  labsequence.advance();
  labsequence.attach(11);
  printSequence(labsequence);
  labsequence.start();
  cout << "Start: " << labsequence.current() << endl;
  labsequence.end();
  cout << "End: " << labsequence.current() << endl;
}