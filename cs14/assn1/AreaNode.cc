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

#include <iostream>
#include "AreaNode.h"

using namespace std;

//-----------------------------------------------------------------------
// DO NOT MODIFY THIS PRINT FUNCTION

void
AreaNode::print ( ) {
  cout << "( " << areaCode << " )" << endl;
  numbers.print ( );
}

//-----------------------------------------------------------------------
//!Returns the number of phone numbers in the list for this area code
int
AreaNode::size ( ) {

  return numbers.size();
}

//-----------------------------------------------------------------------
//!Gets the next AreaNode
AreaNode *
AreaNode::getNext ( ) {

	return next;
}

//-----------------------------------------------------------------------
//!Default Constructor
AreaNode::AreaNode()
:areaCode(0),next(NULL),numbers(0,0)
{
}

//-----------------------------------------------------------------------
//!Constructor creating a AreaNode with numbers starting values
AreaNode::AreaNode(int area, int prefix, int suffix)
:areaCode(area),next(NULL),numbers(prefix,suffix)
 {
 }


//-----------------------------------------------------------------------
//!DeConstructor
AreaNode::~AreaNode()
{
	numbers.~NumberList();
}

//-----------------------------------------------------------------------
//!Returns the ptr of head of the numbers
NumberNode* AreaNode::get_head()
{
	return numbers.get_head();
}

//-----------------------------------------------------------------------
//!Returns the AreaCode number
int
AreaNode::get_areaCode() const {

	return areaCode;
}

//-----------------------------------------------------------------------
//!Searches for specific prefix& suffix number, returns true if found
int
AreaNode::prefix_count(int prefix)
{
	int total = 0;
	for(NumberNode* i = numbers.get_head(); i != NULL; i = i->next)
	{
		if(i == NULL)
		{
			return 0;
		}
		if(i->prefix == prefix)
		{
			total += 1;
		}
	}
	return total;
}

//-----------------------------------------------------------------------
//!Sets the next AreaNode in the list
bool
AreaNode::search_numbers(int prefix, int suffix) {

	return (numbers.search(prefix,suffix));
}

//-----------------------------------------------------------------------
//!Sets the next AreaNode in the list
void
AreaNode::set_next(AreaNode *n) {

	next = n;
}

//-----------------------------------------------------------------------
//!Removes specific prefix & suffix number
bool
AreaNode::remove_numbers(int prefix, int suffix)
{
	if(numbers.remove(prefix,suffix))
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------
//!Adds NumberNode to front of the numbers
void
AreaNode::push_numbers(int prefix, int suffix)
{
	numbers.push_front(prefix,suffix);
}
