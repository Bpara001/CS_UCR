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

// bad_word.cpp
// Implement the Bad_word class

#include "bad_word.h"

Bad_word::Bad_word()
:badword(),replaceword()
{
}

Bad_word::Bad_word( const string &bw, const string &rw)
 :badword(bw),replaceword(rw)
{
}

string Bad_word::get_badword() const
{
    return badword;
}

string Bad_word::get_replaceword() const
{
    return replaceword;
}

void Bad_word::set_badword( const string &bw )
{
    badword = bw;
}

void Bad_word::set_replaceword( const string &rw )
{
    replaceword = rw;
}
