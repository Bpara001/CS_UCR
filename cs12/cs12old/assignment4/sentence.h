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

// sentence.h

#ifndef __SENTENCE_H__
#define __SENTENCE_H__

#include <iostream>
#include <string>
#include "bad_word.h"
using namespace std;
class Sentence
{
//-------Private Data ( required )---------------

private:

//The size of the dynamic array, sentence - i.e. the max number
//of words that can be stored in the sentence array
int max_sentence_size;

//The size of the dynamic array, bad_words - i.e. the max number
//of words that can be stored in the bad_words array.
int max_badwords_size;

//The number of words currently stored in the array, sentence - obviously
//this will start at 0 and may go up to a maximum of max_sentence_size)
int num_sentence_words;

//The current number of Bad_word objects (i.e. "bad" word/replacement
//word pairs) currently stored in the array, bad_words - obviously this
//will start at 0 and may go up to a maximum of max_badwords_size).
int num_bad_words;

//The dynamically allocated array of strings that stores each word
//in the censored sentence.
string * sentence;

//The dynamically allocated array of Bad_words that stores each
//bad word as well as its replacement.

Bad_word * bad_words;


public:

//-------Public Interface ( public member functions - required )----------
//This class will encapsulate two dynamic arrays: one of bad word/replacement
//wordpairs, and one of strings (i.e. the collection of words that comprise
//the user's sentence); plus some "housekeeping" variables (see details below)

//The default Constructor for the Sentence class: sets all pointers to NULL,
//the max sentence and badwords sizes to 40, the number of sentence & bad
//words to 0.
Sentence();

//Constructor for the Sentence class. max_words is the initial value
//of both max_sentence_size and max_badwords_size.
Sentence( int max_words );

//Reset sentence to 0 words actually stored - i.e. reset all currently
//stored words in the sentence dynamic array to "", and reset
//num_sentence_words to 0.
void clear();

//Outputs the sentence to standard output (console).
void print_sentence() const;

//Add one word to the end of the sentence. word is the word to be added.
//If the word passed in is a "bad" word (i.e. if you can find it in the
//bad_words dynamic array) then, this function should obtain the replacement
//word, and add that word to the sentence dynamic array instead of the "bad"
//word.
void add_word( const string & word );

//Add one "bad" and its "good" replacement word to the list of bad word
//objects. word is the "bad" word to be replaced and replacement is the
//"good" word that will replace it in the censored sentence.
void add_bad_word( const string & word, const string & replacement );

//The destructor to deallocate all dynamically allocated arrays.
virtual ~Sentence();


//Private Members Functions

//You must come up with your own private helper functions.
};


#endif //__SENTENCE_H__

