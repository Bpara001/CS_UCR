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
#ifndef __Music_collection_H__
#define __Music_collection_H__

#include "tune.h"

class Music_collection

{

private:

// the number of tunes actually in the collection
int number;
// the number of tunes the collection will ever be able to hold
int max;
// a dynamic array of Tunes: "Music_collection has-many Tunes"
Tune* collection;

public:
// default value of max is a conservative 100
Music_collection();

// sets max to n
Music_collection( int n );

// overloaded copy constructor
Music_collection( const Music_collection& m);

// returns true if add was successful, false if not enough room to add
bool add_tune( const Tune& t );

// sets the Tune at position index in collection to t, returns true if index<number
bool set_tune( int index, const Tune& t );

// overloaded assignment operator
Music_collection& operator=( const Music_collection& m );
// Destructor
~Music_collection();

// overloaded stream insertion operator
friend ostream& operator << (ostream& out, const Music_collection& m );

};

#endif
