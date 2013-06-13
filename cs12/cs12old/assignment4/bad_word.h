// Course: CS 12 Winter Quarter, 2010
//
// First Name: Chris
// Last Name: Wong
// Username: wongc
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Denise Duma
//
// Assignment: Assignment 4
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
// =======================================================================

// bad_word.h


#ifndef __BAD_WORD_H__
#define __BAD_WORD_H__
#include <iostream>
#include <string>
using namespace std;

class Bad_word
{
private:
string badword;
string replaceword;

public:
//The default constructor - sets both member variables to the null string
Bad_word();

//The principal constructor - sets bad_word and replace_word respectively
Bad_word( const string &bw, const string &rw );

//Accessor - returns bad_word
string get_badword() const;

//Accessor - returns replace_word
string get_replaceword() const;

//Mutator - sets bad_word
void set_badword( const string &bw );

//Mutator - sets replace_word
void set_replaceword( const string &rw );
};





#endif // __BAD_WORD_H__
