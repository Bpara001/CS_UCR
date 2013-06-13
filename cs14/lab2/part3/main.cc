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
// lab 2 main.cc

#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int
main (int argc, char ** argv ) {

  if(argc != 2)
  {
	  cerr << "Usage error: expected <excutable> <input file> " << endl;
	  exit(1);
  }

  ifstream ifs;
  ifs.open(argv[1]);

  if(!ifs)
  {
	  cerr << "Input file" << argv[1] << "not found" << endl;
	  exit(1);
  }



  List first_list;
  List second_list;

  first_list.push_front(1);
  first_list.push_front(2);
  first_list.push_front(3);
  first_list.push_front(4);
  first_list.push_front(5);

  cout << "The first list is" << endl;
  first_list.print();

  second_list.push_front(10);
  second_list.push_front(9);
  second_list.push_front(8);
  second_list.push_front(7);
  second_list.push_front(6);

  cout << "The second list is" << endl;
  second_list.print();

  cout << "Making second equal to the first." << endl;
  second_list = first_list;

  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Adding 100 to the front of the first, and " << endl;
  cout << "200 to the front of the second" << endl;
  first_list.push_front(100);
  second_list.push_front(200);

  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Adding 1000 to the end of the first, and " << endl;
  cout << "2000 to the end of the second" << endl;
  first_list.push_back(1000);
  second_list.push_back(2000);

  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  // add file I/O and merge testing here
ifs.close();
  return 0;
}
