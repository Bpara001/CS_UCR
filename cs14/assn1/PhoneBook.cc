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
#include <string>
#include "PhoneBook.h"
#include <fstream>

using namespace std;

//-------------------------------------------------------------------------
//This function will read phone numbers in from a file and add them to the
//phone book.
//* fileName - the name of the file to read in from
//(NOTE: the file name is of type string. You may not change that)
void
PhoneBook::readFromFile ( string fileName ) {

	ifstream infile;
	infile.open(fileName.c_str());
	string numbers = "void";

	while(infile)
	{
		getline(infile,numbers);
		if(numbers.size() < 1)
		{
			return;
		}

		//Reads strings and converts to ints
		string area = numbers.substr(0,3);
		string prefix = numbers.substr(4,3);
		string suffix = numbers.substr(8,4);
		int area_int = atoi(area.c_str());
		int prefix_int = atoi(prefix.c_str());
		int suffix_int = atoi(suffix.c_str());
		insertPhoneNumber(area_int,prefix_int,suffix_int);

	}

	infile.close();
}

//-------------------------------------------------------------------------
//This function will remove a phone number from the phone book.
// area - the area code of the number to be removed
// prefix - the prefix of the number to be removed
// suffix - the suffix of the number to be removed
void
PhoneBook::removePhoneNumber ( int area, int prefix, int suffix ) {

	//Case1, False value
	if(!search(area,prefix,suffix))
	{
		cout <<"Error: Phone number does not exist" << endl;
		return;
	}

	//Case2, value at Head
	if(head->get_areaCode() == area)
	{
		if(head->remove_numbers(prefix,suffix))
		{
			if(head->get_head() == NULL)
			{
				head = (head->getNext());
			}
			return;
		}
	}

	//Case3, value at Other node
	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		AreaNode* temp = i->getNext();
		if(temp->get_areaCode() == area)
		{
			if(temp->remove_numbers(prefix,suffix))
			{
				if(temp->get_head() == NULL)
				{
					i->set_next(temp->getNext());
					return;
				}
			}
		}
	}
}

//-------------------------------------------------------------------------
//This function will insert a phone number into the phone book.
//* area - the area code of the number to be inserted
//* prefix - the prefix of the number to be inserted
//* suffix - the suffix of the number to be inserted
void
PhoneBook::insertPhoneNumber ( int area, int prefix, int suffix ) {

	//Case1, Duplicate
	if(search(area,prefix,suffix))
	{
		cout<<"Error: cannot insert duplicate phone numbers" << endl;
		return;
	}

	//Case2, non-empty List
	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		if(i->get_areaCode() == area)
		{
			i->push_numbers(prefix,suffix);
			return;
		}
	}

	//(For case3&4)
	AreaNode* new_node = new AreaNode(area, prefix, suffix);

	//Case3, Empty List
	if(head == NULL)
	{
		head = new_node;
		return;
	}

	//Case4, new areaCode
	new_node->set_next(head);
	head = new_node;
	return;

}

//-------------------------------------------------------------------------
//This function will search for a phone number in the phone book.
//The function will return true if the phone number is found and
//false if the phone number is not found.
//* area - the area code of the number to search for
//* prefix - the prefix of the number to search for
//* suffix - the suffix of the number to search for
bool
PhoneBook::search ( int area, int prefix, int suffix ) {

	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		if(i->get_areaCode() == area)
		{
			return (i->search_numbers(prefix,suffix));
		}
	}
	return false;
}

//-------------------------------------------------------------------------
// DO NOT MODIFY THIS PRINT FUNCTION

void
PhoneBook::print ( ) {

  if ( head == NULL ) {
    cout << "Phonebook is empty" << endl;
  }
  else {
    for ( AreaNode *temp = head; temp != NULL; temp = temp->getNext( ) ) {
      temp->print ( );
    }
  }

}

//-------------------------------------------------------------------------
//This function will return the total number of phone numbers in the phonebook.
int 
PhoneBook::numNumbers ( ) {

	int total = 0;

	if(head == NULL)
	{
		return 0;
	}
	for(AreaNode* i= head; i != NULL; i = i->getNext())
	{
		total += i->size() -1;
	}
	return total;
}

//-------------------------------------------------------------------------
//Returns the total number of phone numbers in the specified area code
int
PhoneBook::numAreaCodeNumbers ( int area ) {

	for(AreaNode* i = head; i != NULL; i = i->getNext() )
	{
		if(i->get_areaCode() == area)
		{
			if(head == NULL)
			{
				return 0;
			}
			else
			{
			return i->size() -1;
			}
		}

		return 0;
	}
	return 0;
}

//-------------------------------------------------------------------------
//This function will return the total number of phone numbers in the specified
//area code that belong to a specified prefix
int
PhoneBook::numAreaCodeAndPrefixNumbers ( int area , int prefix ) {

	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		if(i->get_areaCode() == area )
			{
				return i->prefix_count(prefix);
			}

	}
	return 0;
}

//-------------------------------------------------------------------------
//This function will take phone numbers from a given prefix in a given
//area code and place them into a new area code.
void
PhoneBook::split ( int oldAreaCode, int prefix, int newAreaCode ) {

	//Case1, Duplicate Case
	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		if(i->get_areaCode() == newAreaCode)
		{
			cout<<"Error: new area code already exists" << endl;
			return;
		}
	}

	//Case2, General Case
	for(AreaNode* i = head; i != NULL; i = i->getNext())
	{
		if(i->getNext()->get_areaCode() == oldAreaCode)
		{
			for(NumberNode* j = i->getNext()->get_head(); j != NULL;j= j->next)
			{
				if(j->prefix == prefix)
				{
					insertPhoneNumber(newAreaCode,prefix,j->suffix);
					i->getNext()->remove_numbers(prefix,j->suffix);
				}
			}
			if(i->getNext()->get_head() == NULL)
			{
				i->set_next(i->getNext()->getNext());
				return;
			}
			return;
		}
	}


}

//-------------------------------------------------------------------------
//!Default Constructor
PhoneBook::PhoneBook()
:head(NULL)
 {
 }

//-------------------------------------------------------------------------
//!DeConstructor
  PhoneBook::~PhoneBook()
  {
	  for(AreaNode* i = head; i != NULL; i->getNext())
	  {
		  i->~AreaNode();
	  }
  }
