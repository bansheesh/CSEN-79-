#include "node.h"
#include <iostream>

using namespace std;
using namespace coen79_lab6;

int main(int argc, char const *argv[]) {

  // Create a null node *my_list. list_head_insert() 1, 1.5, 2, 2.5, 3, 3.5,
  // 4, 4.5.
  node *my_list = NULL;
  list_head_insert(my_list, 4.5);
  list_head_insert(my_list, 4);
  list_head_insert(my_list, 3.5);
  list_head_insert(my_list, 3);
  list_head_insert(my_list, 2.5);
  list_head_insert(my_list, 2);
  list_head_insert(my_list, 1.5);
  list_head_insert(my_list, 1);

  // list_print(). Create a node* temp.
  cout << "The list: ";
  list_print(my_list);
  node *temp;

  // List_piece tests
  cout << " *** list_piece tests ***" << endl;
  // Create a head and a tail node. The head and tail pointer are always the
  // 3rd/4th parameter of
  //  list_piece(). Always list_print() after list_piece().
  node *head = my_list;
  node *tail = list_locate(head, list_length(head));

  // ○ list_piece(NULL,NULL,head,tail);
  list_piece(NULL, NULL, head, tail);
  cout << "Empty: ";
  list_print(head);
  // ○ list_piece(my_list,my_list,head,tail);
  list_piece(my_list, my_list, head, tail);
  cout << "Both at head: ";
  list_print(list_copy_segment(my_list, 1, 1));
  // ○ list_piece(my_list,list_locate(my_list,4),head,tail);
  list_piece(my_list, list_locate(my_list, 4), head, tail);
  cout << "Three from head: ";
  list_print(head);
  // ○ list_piece(list_locate(my_list,3),list_locate(my_list,6),head,tail);
  list_piece(list_locate(my_list, 3), list_locate(my_list, 6), head, tail);
  cout << "Three in middle: ";
  list_print(head);
  // ○ list_piece(list_locate(my_list,6),NULL,head,tail);
  list_piece(list_locate(my_list, 6), NULL, head, tail);
  cout << "Three on end: ";
  list_print(head);
  // ○ list_piece(list_locate(my_list,list_length(my_list)),NULL,head,tail);
  list_piece(list_locate(my_list, list_length(my_list)), NULL, head, tail);
  cout << "The end: ";
  list_print(head);
  // ○ list_piece(my_list,NULL,head,tail);
  list_piece(my_list, NULL, head, tail);
  cout << "Full list: ";
  list_print(head);

  // List Copy Segment Tests (Think about how to write each case in one line)
  // ○ // Copy everything on my_list. list_print() after each list copy
  cout << endl;
  cout << " *** list_copy_segment tests ***" << endl;

  list_copy(my_list, head, tail);
  cout << "Both at head: ";
  list_print(list_copy_segment(my_list, 1, 2));
  // ○ Copy the first item
  list_copy(list_copy_segment(my_list, 1, 4), head, tail);
  cout << "Three from head:";
  list_print(head);
  // ○ Copy 1st-3rd items
  list_copy(list_copy_segment(my_list, 3, 6), head, tail);
  cout << "Three in middle: ";
  list_print(head);
  // ○ Copy 3rd-5th items
  list_copy(list_copy_segment(my_list, 6, 9), head, tail);
  cout << "Three on end: ";
  list_print(head);
  // ○ Copy 6th-end items
  list_copy(list_copy_segment(my_list, list_length(my_list) - 1,
                              list_length(my_list)),
            head, tail);
  cout << "The end: ";
  list_print(head);
  // ○ Copy the last item
  list_copy(
      list_copy_segment(my_list, list_length(my_list), list_length(my_list)),
      head, tail);
  // ○ Copy the entire list
  list_copy(my_list, head, tail);
  cout << "Full list: ";
  list_print(head);

  // List_insert_at
  // ○ // list_print() after each insertion.
  cout << endl;
  cout << " *** list_insert_at tests ***" << endl;

  // ○ Insert 0.5 at front of my_list
  cout << "Insert 0.5 at front: " << endl;
  cout << "	";
  list_insert_at(my_list, 0.5, 1);

  list_print(my_list);
  // ○ Insert 4.75 at back of my_list
  cout << "Inserting 4.75 at back: " << endl;
  cout << "	";
  list_insert_at(my_list, 4.75, list_length(my_list) + 1);
  list_print(my_list);
  // ○ Insert 2.25 at position=5 of my_list
  cout << "Inserting 2.25 in middle: " << endl;
  cout << "	";
  // list_insert_at(my_list, 2.25, 5);
  list_insert_at(my_list, 2, 4);
  list_print(my_list);
  // ○ Assign temp = NULL
  temp = NULL;
  // ○ Inserting -4.3 into temp
  cout << "Inserting -4.3 into an empty list: " << endl;
  cout << "	";
  list_insert_at(temp, -4.3, 1);
  list_print(temp);
  // ○ list_clear() temp
  list_clear(temp);

  // ● List_piece()
  // ○ list_insert_at(my_list, 2, 5) twice. list_print() my_list.
  cout << endl;
  cout << " *** list_occurances tests ***" << endl;

  list_insert_at(my_list, 2, 5);
  list_insert_at(my_list, 2, 5);
  cout << "The list: ";
  list_print(my_list);
  // ○ Read the expected output to infer the code needed
  cout << "Number of 0.5's: " << list_occurrences(my_list, 0.5) << endl;
  cout << "Number of 4.75's: " << list_occurrences(my_list, 4.75) << endl;
  cout << "Number of 3's: " << list_occurrences(my_list, 3) << endl;
  cout << "Number of 2's: " << list_occurrences(my_list, 2) << endl;
  cout << "Number of 0's: " << list_occurrences(my_list, 0) << endl;
  // list_print(my_list);

  // ● List_remove_at()
  cout << endl;
  cout << " *** list_remove_at tests ***" << endl;
  // ○ list_print() my_list.
  cout << "The list: ";
  list_print(my_list);
  // ○ Remove first item, last item, and item at position=9. list_print() after
  // each removal. ○ Read the expected output to infer the code needed ●
  cout << "Removing first item: " << endl;
  cout << "	";
  list_remove_at(my_list, 1);
  list_print(my_list);
  cout << "Removing last item: " << endl;
  cout << "	";
  list_remove_at(my_list, list_length(my_list));
  list_print(my_list);
  cout << "Removing 3.5 from the middle: " << endl;
  cout << "	";
  list_remove_at(my_list, 8);
  list_print(my_list);

  // List_remove_dups() ○ Let node* head_ptr = NULL ○ list_head_insert(head_ptr,
  // 1) four times. list_print() head_ptr. ○ list_remove_dups(head_ptr);
  cout << endl;
  cout << " *** list_remove_dups tests ***" << endl;
  node *head_ptr = NULL;
  for (int i = 0; i < 4; i++) {
    list_head_insert(head_ptr, 1);
  }
  list_print(head_ptr);
  list_remove_dups(head_ptr);
  // list_print() head_ptr.
  list_print(head_ptr);

  // list_detect_loop()
  cout << endl;
  cout << " *** list_detect_loop tests ***" << endl;
  // ○ Let node* head_ptr2 = NULL.
  node *head_ptr2 = NULL;
  // ○ list_head_insert() 10,9,8,7,6,5,4,3,2,1 into head_ptr2
  list_head_insert(head_ptr2, 10);
  list_head_insert(head_ptr2, 9);
  list_head_insert(head_ptr2, 8);
  list_head_insert(head_ptr2, 7);
  list_head_insert(head_ptr2, 6);
  list_head_insert(head_ptr2, 5);
  list_head_insert(head_ptr2, 4);
  list_head_insert(head_ptr2, 3);
  list_head_insert(head_ptr2, 2);
  list_head_insert(head_ptr2, 1);
  // ○ Let node* tmp = list_locate (head_ptr2, 10);
  node *tmp = list_locate(head_ptr2, 10);
  // ○ tmp->set_link(head_ptr2->link()->link()->link()->link());
  tmp->set_link(head_ptr2->link()->link()->link()->link());
  // ○ node* loop_start = list_detect_loop(head_ptr2);
  node *loop_start = list_detect_loop(head_ptr2);
  // ○ If loop_start is not NULL, cout loop_start->data().
  if (loop_start != NULL) {
    cout << "The pointers met!" << endl;
    cout << "Loop starting location is: " << loop_start->data();
  }
}