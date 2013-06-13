// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// Assignment: ASSN 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
//! \file main.cpp
//! \brief Test harness for Linked List class L_list

#include <iostream>
#include "l_list.h"

using namespace std;

// ============================================================================
// Main code
// ============================================================================

int main()
{
  L_list list;

 cout << endl << "******TESTING PUSH_FRONT & POP_FRONT******" << endl;

  // push a value onto the front of the list.
  list.push_front( "first" );

   // adding more items to the list
  list.push_front( "second" );
  list.push_front( "third" );
  list.push_front( "fourth" );
   list.push_front( "fifth" );

   //print out list
  cout << endl
       << "List after first stage: size is " << list.get_size()
       << endl;
  list.print();
  cout << endl;

  //remove some items from the list
   list.pop_front();
  list.pop_front();
   list.pop_front();

  //print out list
   cout << endl
        << "List after second stage: size is " << list.get_size()
        << endl;
   list.print();
   cout << endl;

  //delete remaining items in list
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl
        << "List after third stage: size is " << list.get_size()
        << endl;
   list.print();
   cout << endl;



   cout << endl << "******TESTING PUSH_BACK & POP_FRONT******" << endl;

  //push a value onto the back of the list.
   list.push_back( "first" );

  // adding more items to the list
  list.push_back( "second" );
   list.push_back( "third" );
   list.push_back( "fourth" );
   list.push_back( "fifth" );

//   //print out list
   cout << endl << "List after first stage: size is " << list.get_size()
   << endl;
   list.print();
   cout << endl;

   //remove some items from the list
   list.pop_front();
   list.pop_front();
   list.pop_front();

//   //print out list
   cout << endl << "List after second stage: size is " << list.get_size()
   << endl;
   list.print();
   cout << endl;

   //delete remaining items in list
  list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size()
   << endl;
   list.print();
   cout << endl;

} // end main----------------------------------------------------------------
