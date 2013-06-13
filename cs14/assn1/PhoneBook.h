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

#ifndef __PHONE_BOOK_H
#define __PHONE_BOOK_H

#include "AreaNode.h"

using namespace std;

class PhoneBook {

private:
  AreaNode *head;

public:
  void insertPhoneNumber ( int, int, int );
  void removePhoneNumber ( int, int, int );
  bool search ( int, int, int );
  void print ( );
  int numNumbers ( );
  int numAreaCodeNumbers ( int );
  int numAreaCodeAndPrefixNumbers ( int, int );
  void readFromFile ( string );
  void split ( int, int, int );

// Do not modify anything above this line
//------------------------------------------------------------------------
// Add additional functions/variables here:

  //!Default Constructor
  PhoneBook();

  //!DeConstructor
  ~PhoneBook();


};

#endif
