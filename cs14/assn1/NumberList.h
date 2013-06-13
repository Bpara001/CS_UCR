/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn1

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */


#ifndef __NUMBER_LIST_H
#define __NUMBER_LIST_H

#include "NumberNode.h"

class NumberList {
private:
  NumberNode *head;

public:
  void print ( );
  int size ( );

// Do not modify anything above this line
//------------------------------------------------------------------------
// Add additional functions/variables here:

 //!Default Constructor
  NumberList( );

 //!Constructor creating a NumberList with the HEAD starting values
  NumberList(int prefix, int suffix);

  //!DeConstructor
  ~NumberList();

 //!Returns head_ptr of NumberNode
  NumberNode* get_head( );

 //!Searches for specific prefix& suffix number, returns true if found
  bool search(int prefix, int suffix);

 //!Removes specific prefix & suffix number, returns true or false
  bool remove(int prefix, int suffix);

 //!Adds NumberNode to front of the list
  void push_front(int prefix, int suffix);

private:
  int size_of;

// DO NOT make any of the other classes a friend of this class

};

#endif
