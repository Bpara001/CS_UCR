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
// Assignment: lab 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#include <iostream>
using namespace std;

int main()
{
  cout << endl;

  /////// PART 1 ///////////////////////////////////////////



  int int_var = 100;

  //point int_ptr1 to int_var

  int* int_ptr1 = &int_var;


  //allocate memory from the heap (dynamically) and point int_ptr2 at it
  //store the value 200 in this memory
  int* int_ptr2 = NULL;
  int_ptr2 = new int;
  *int_ptr2 = 200;



  cout << "int_var: " << int_var << endl
       << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << endl;

  //add 100 to the values pointed to by both int pointers
  *int_ptr1 += int_var;
  *int_ptr2 += int_var;


  cout << "int_var: " << int_var << endl
       << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << endl;

  //delete all dynamically allocated memory in Part 1

  // delete int_ptr1;
  //int_ptr1 = NULL;
  delete int_ptr2;
  int_ptr2 = NULL;




  /////// PART 2 ///////////////////////////////////////////

  //dynamically allocate new memory from the heap for all 3 pointers
  int_ptr1 = new int;
  *int_ptr1 = 400;

  int_ptr2 = new int;
  *int_ptr2 = 500;

  int * int_ptr3 = NULL;
  int_ptr3 = new int;
  *int_ptr3 = 600;

  cout << "int_var: " << int_var << endl
       << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << "*int_ptr3: " << *int_ptr3 << endl
       << endl;

  //point all pointers to the same memory location
  //  (the one pointed to by int_ptr1)
  //make sure you don't leave allocated memory floating around
  delete int_ptr1;
  delete int_ptr2;
  *int_ptr2 = *int_ptr1;
  *int_ptr3 = *int_ptr2;
  

  cout << "*int_ptr1: " << *int_ptr1 << endl
       << "*int_ptr2: " << *int_ptr2 << endl
       << "*int_ptr3: " << *int_ptr3 << endl
       << endl;

  //delete all dynamically allocated memory in part2
  int_ptr1 = NULL;
  int_ptr2 = NULL;
  delete int_ptr3;
  int_ptr3 = NULL;

  return 0;
}
