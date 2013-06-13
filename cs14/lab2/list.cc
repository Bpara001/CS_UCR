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
// This file contains all of the functions for the list class

#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List ( ) {

  head = NULL;

}

List::List(const List& l )
:head(NULL)
{
	for(Node* temp; temp != NULL; temp = temp->next)
	{
		push_back(temp->value);
	}
}

//------------------------------------------------------------------------

List::~List ( ) {

  // ADD: to avoid memory leaks, make sure you delete all allocated memory
cout << "\nList Destructor called...\n";

  while(head)
	{
	Node* temp = head;
	head = head->next;
	cout << "Deleting.... " << temp->value << endl;
	delete temp;
	temp = NULL;
	}

	clear();
}

//------------------------------------------------------------------------

int
List::size ( ) {
  int size = 0;
  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    size ++;
  }
  return size;
}

//------------------------------------------------------------------------

void
List::push_front ( int value ) {

  Node* insert = new Node;
  insert->value = value;
  insert->next = head;
  head = insert;

}

//------------------------------------------------------------------------

void
List::push_back ( int value ) {

  if ( size ( ) == 0 ) {
    push_front ( value );
  }
  else {
    Node* tail;
    for ( tail = head; tail->next != NULL; tail = tail->next );
    Node* insert = new Node;
    insert->value = value;
    insert->next = NULL;
    tail->next = insert;
  }

}

//------------------------------------------------------------------------

void
List::print ( ) {

  if ( size ( ) == 0 ) {
    cout << "No elements in the array" << endl;
    return;
  }

  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    cout << temp->value << " ";
  }
  cout << endl;
}

//------------------------------------------------------------------------

void
List::pop_front()
{
	if(head == NULL)
	{
		return;
	}
	head = head->next;
}

//------------------------------------------------------------------------

List& List::operator=(const List& l)
{
	if(this != &l)
	{
	clear();
		for(Node* temp = l.head; temp != NULL; temp = temp->next)
		{
			push_back(temp->value);
		}
	}

}

//------------------------------------------------------------------------
void List::clear()
{
	while(head)
	{
		pop_front();
	}
}

