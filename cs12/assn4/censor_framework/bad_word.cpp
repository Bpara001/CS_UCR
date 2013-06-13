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
// Assignment: Programming Assignment 4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

// bad_word.cpp
// Implement the Bad_word class
#include "bad_word.h"

//The default constructor - sets both member variables to the null string
Bad_word::Bad_word()
:bad_word(""),replace_word("")
{
}

//The principal constructor -set bad_word and replace_word respectively
Bad_word::Bad_word(const string &bw, const string &rw)
:bad_word(bw),replace_word(rw)
{
}

//Accessor - returns bad_word
string Bad_word::get_badword() const
{
    return bad_word;
}

//Accesssor - returns replace_word
string Bad_word::get_replaceword() const
{
    return replace_word;
}

//Mutator - sets bad_word
void Bad_word::set_badword(const string &bw)
{
    bad_word = bw;
}

//Mutator - sets replace_word
void Bad_word::set_replaceword(const string &rw)
{
    replace_word = rw;
}
