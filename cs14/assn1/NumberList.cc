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
#include "NumberList.h"

using namespace std;

#define NUM_TO_PRINT_PER_LINE 5

//-----------------------------------------------------------------------
// DO NOT MODIFY THIS PRINT FUNCTION
void
NumberList::print ( ) {

  NumberNode *temp = head;
  for ( int x = 0; x < size ( ) && temp != NULL; 
        x += NUM_TO_PRINT_PER_LINE ) {
    cout << "       " << flush;
    for ( int y = 0; y < NUM_TO_PRINT_PER_LINE && temp != NULL; 
          y ++, temp = temp->next ) {
      cout << temp->prefix << "-" << flush << temp->suffix << ", " << flush;
    }
    cout << endl;
  }
}

//-----------------------------------------------------------------------
//Returns number of elements in NumberList
int
NumberList::size ( ) {

	return size_of;
}

//-----------------------------------------------------------------------
//!Default Constructor
NumberList::NumberList( )
:head(NULL),size_of(0)
{
}

//-----------------------------------------------------------------------
//!Constructor creating a NumberList with the HEAD starting values
NumberList::NumberList(int prefix, int suffix)
:head(NULL),size_of(1)
{
	push_front(prefix,suffix);
}

//-----------------------------------------------------------------------
//!DeConstructor
NumberList::~NumberList()
{
	for(NumberNode* i = head; i != NULL; i = i->next)
	{
		delete i;
		i = NULL;
	}
}

//-----------------------------------------------------------------------
//!Returns head_ptr of NumberNode
NumberNode*
NumberList::get_head() {

	return head;
}

//-----------------------------------------------------------------------
//!Searches for specific prefix& suffix number, returns true if found
bool
NumberList::search(int prefix, int suffix)
{
	for(NumberNode* i = head; i != NULL; i = i->next)
	{
		if(i->prefix == prefix && i->suffix == suffix)
		{
			return true;
		}
	}

	return false;
}

//-----------------------------------------------------------------------
//!Removes specific prefix & suffix number
bool
NumberList::remove(int prefix, int suffix)
{
	//Case1, False parameters
	if(head == NULL)
	{
		return false;
	}



	//Case2, Value at Head
	if(head->prefix == prefix && head->suffix == suffix)
	{
		NumberNode* temp = head;
		head = head->next;
		size_of--;
		delete temp;
		temp = NULL;
		return true;
	}

	//Case3, Value at Other nodes
	for(NumberNode* i = head; i != NULL; i = i->next)
	{
		if((i->next->prefix) == prefix && (i->next->suffix) == suffix)
		{
			NumberNode* temp = i->next;
			delete temp;
			temp = NULL;

			i->next = i->next->next;
			size_of--;

			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------
//!Adds NumberNode to front of the list
void
NumberList::push_front(int prefix, int suffix) {

	 NumberNode* new_node = new NumberNode(prefix,suffix);

	 //Case1, Empty List
	 if(head == NULL)
	 {
	     head = new_node;
	     new_node->prefix = prefix;
	     new_node->suffix = suffix;
	     new_node->next = NULL;
	     size_of++;
	     return;
	 }

	 //Case2, non-empty List
	 new_node->next = head;
	 new_node->prefix = prefix;
	 new_node->suffix = suffix;
	 head = new_node;
	 size_of++;
}
