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
// Assignment: LAB 9
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


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                           TEST #1                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   cout << endl << "******TEST #1: PUSH_FRONT & POP_FRONT******" << endl;
   // push a value onto the front of the list.
   list.push_front( "1" );
   // adding more items to the list
   list.push_front( "2" );
   list.push_front( "3" );
   list.push_front( "4" );
   list.push_front( "5" );

   //print out list
   cout << endl << "List after first stage: size is " << list.get_size();
   cout << "\n(push_front list with values)" << endl;
   list.print();
   cout << endl;

  //remove some items from the list
   list.pop_front();
  list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after second stage: size is " << list.get_size();
   cout << "\n(Pop_front 3 times)" << endl;
   list.print();
   cout << endl;

  //delete remaining items in list
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size();
   cout << "\n(Pop_front the remaining values)" << endl;
   list.print();
   cout << endl;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                           TEST #2                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   cout << endl << "******TEST #2: PUSH_BACK & POP_FRONT******" << endl;
   // push a value onto the front of the list.
   list.push_front( "1" );
   // adding more items to the list
   list.push_front( "2" );
   list.push_front( "3" );
   list.push_front( "4" );
   list.push_front( "5" );

   //print out list
   cout << endl << "List after first stage: size is " << list.get_size();
   cout << "\n(push_back list with values)" << endl;
   list.print();
   cout << endl;

   //remove some items from the list
   list.pop_front();
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after second stage: size is " << list.get_size();
   cout << "\n(Pop_front 3 times)" << endl;
   list.print();
   cout << endl;

   //delete remaining items in list
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size();
   cout << "\n(Pop_front the remaining values)" << endl;
   list.print();
   cout << endl;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                           TEST #3                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   cout << endl << "******TEST #3: ERASE*****" << endl;
   // push a value onto the front of the list.
   list.push_front( "1" );
   // adding more items to the list
   list.push_front( "2" );
   list.push_front( "3" );
   list.push_front( "4" );
   list.push_front( "5" );

   //print out list
   cout << endl << "List after first stage: size is " << list.get_size();
   cout << "\n(push_back list with values)" << endl;
   list.print();
   cout << endl;

   //erase some items from the list
   Node* ptr_second = list.search("2");
   Node* ptr_fourth = list.search("4");
   list.erase(ptr_second);
   list.erase(ptr_fourth);

   //print out list
   cout << endl << "List after second stage: size is " << list.get_size();
   cout << "\n(Searches ptr for 2 & 4, Eraseing 2 and 4)" << endl;
   list.print();
   cout << endl;

   //delete remaining items in list
   list.pop_front();
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size();
   cout << "\n(Pop_front the remaining values)" << endl;
   list.print();
   cout << endl;

   delete ptr_second;
   ptr_second = NULL;
   delete ptr_fourth;
   ptr_fourth = NULL;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                           TEST #4                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   cout << endl << "******TEST #4: SEARCH && INSERTION*****"
   << endl;
   // push a value onto the front of the list.
   list.push_front( "1" );
   // adding more items to the list
   list.push_front( "2" );
   list.push_front( "3" );
   list.push_front( "4" );
   list.push_front( "5" );

   //print out list
   cout << endl << "List after first stage: size is " << list.get_size();
   cout << "\n(push_back list with values)" << endl;
   list.print();
   cout << endl;

   //erase some items from the list
   ptr_second = list.search("2");
   ptr_fourth = list.search("4");
   list.insert("2.5",ptr_second);
   list.insert("4.5",ptr_fourth);

   //print out list
   cout << endl << "List after second stage: size is " << list.get_size();
   cout << "\n(Searches ptr for 2 & 4, Inserting 2.5 & 4.5)" << endl;
   list.print();
   cout << endl;

   //delete remaining items in list
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size();
   cout << "\n(Pop_front the remaining values)" << endl;
   list.print();
   cout << endl;

   //delete pointers, set to null
   delete ptr_second;
   ptr_second = NULL;
   delete ptr_fourth;
   ptr_fourth = NULL;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                           TEST #5                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   cout << endl << "******TEST #5: REVERSE*****"
   << endl;
   //push a value onto the back of the list.
   list.push_back( "1" );
   //adding more items to the list
   list.push_back( "2" );
   list.push_back( "3");
   list.push_back( "4" );
   list.push_back( "5" );
   list.push_back( "6" );
   list.push_back( "7" );
   list.push_back( "8" );
   list.push_back( "9" );
   list.push_back( "10" );

   //print out list
   cout << endl << "List after first stage: size is " << list.get_size();
   cout << "\n(push_back list with values)" << endl;
   list.print();
   cout << endl;

   //erase some items from the list
   list.reverse();

   //print out list
   cout << endl << "List after second stage: size is " << list.get_size();
   cout << "\n(reverses list)" << endl;
   list.print();
   cout << endl;

   //delete remaining items in list
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();
   list.pop_front();

   //print out list
   cout << endl << "List after third stage: size is " << list.get_size();
   cout << "\n(Pop_front the remaining values)" << endl;
   list.print();
   cout << endl;

   //delete pointers, set to NULL
   delete ptr_second;
   ptr_second = NULL;
   delete ptr_fourth;
   ptr_fourth = NULL;

   cout << endl;
   cout << "end of main" << endl;

return 0;
} // end main----------------------------------------------------------------
