/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn2

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

#ifndef __STACKNODE_H__
#define __STACKNODE_H__

#include "StringStack.H"
class StackNode
{
public:
  StringStack data;
  StackNode *next;


  //!Defualt Constructor
  StackNode()
  :data(),next(NULL)
  {
  }

  //!Constructor with data
  StackNode(StringStack s)
  :data(s),next(NULL)
  {
  }

};

#endif

