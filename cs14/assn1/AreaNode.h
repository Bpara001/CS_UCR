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

#ifndef __AREA_NODE_H
#define __AREA_NODE_H

#include "NumberList.h"

class AreaNode {
private:
  int areaCode;
  AreaNode *next;
  NumberList numbers;

public:
  void print ( );
  int size ( );
  AreaNode * getNext( );

// Do not modify anything above this line
//------------------------------------------------------------------------
// Add additional functions/variables here:

  //!Default Constructor
  AreaNode();

  //!Constructor creating a AreaNode with numbers starting values
  AreaNode(int value,int prefix,int suffix);

  //!DeConstructor
  ~AreaNode();

  //!Returns the ptr of head of the numbers
  NumberNode* get_head();

  //!Returns the AreaCode number
  int get_areaCode() const;

  //!Counts specific number of prefixes in the AreaNode
  int prefix_count(int prefix);

  //!Searches for specific prefix& suffix number, returns true if found
  bool search_numbers(int prefix, int suffix);

  //!Sets the next AreaNode in the list
  void set_next(AreaNode* n );

  //!Removes specific prefix & suffix number
  bool remove_numbers(int prefix, int suffix);

  //!Adds NumberNode to front of the numbers
  void push_numbers(int prefix, int suffix);


// DO NOT make any of the other classes a friend of this class

};

#endif
