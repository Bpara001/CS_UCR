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


#ifndef __NUMBER_NODE_H
#define __NUMBER_NODE_H

class NumberNode {
public:
  int prefix;
  int suffix;
  NumberNode *next;

// Do not modify anything above this line
//------------------------------------------------------------------------

// Add additional functions/variables here:

  //!Constructor with values
  NumberNode(int p, int s)
  :prefix(s),suffix(s),next(NULL)
  {}

};

#endif
