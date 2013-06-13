/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: lab2

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
*/

// CS14
// This file contains the list class declaration.

#ifndef __LIST_H_
#define __LIST_H_

#include "node.h"

class List {
private:
  Node* head;

public:
  List ( );
  List (const List &l );
  ~List ( );
  int size ( );
  void push_front ( int );
  void push_back ( int );
  void print ( );
  void pop_front();
  List& operator=(const List& p);
  void clear();
  // Add new member function declarations here
};

#endif

