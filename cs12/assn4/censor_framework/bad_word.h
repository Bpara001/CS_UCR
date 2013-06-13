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

// bad_word.h

#ifndef __BAD_WORD_H__
#define __BAD_WORD_H__

#include <iostream>
//#include <string>
using namespace std;

class Bad_word
{
    private:
    string bad_word;
    string replace_word;

    public:

    //The default constructor - sets both member variables to the null string
    Bad_word();

    //The principal constructor -set bad_word and replace_word respectively
    Bad_word(const string &bw, const string &rw);

    //Accessor - returns bad_word
    string get_badword() const;

    //Accesssor - returns replace_word
    string get_replaceword() const;

    //Mutator - sets bad_word
    void set_badword(const string &bw);

    //Mutator - sets replace_word
    void set_replaceword(const string &rw);

};

#endif // __BAD_WORD_H__
