/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn3

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

class Node
{
public:

	string data;
	int count;
	Node* left;
	Node* right;
	Node* parent;

	//Default constructor
	Node()
	:data(""),count(0),left(NULL),right(NULL),parent(NULL)
	 {
	 }

	//Constructor with initial values
	Node(string s)
	:data(s),count(1),left(NULL),right(NULL)
	 {
	 }

	 void reset()
	 {
	     data = "";
	     count = 0;
	     left = NULL;
	     right = NULL;
	     parent = NULL;
	 }

};
#endif
