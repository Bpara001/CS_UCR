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


// sentence.h
#include "bad_word.h"

#ifndef __SENTENCE_H__
#define __SENTENCE_H__

class Sentence
{
    private:

    int max_sentence_size;
    int max_badwords_size;
    int num_sentence_words;
    int num_bad_words;
    string *sentence;
    Bad_word *bad_word;

    public:

    //The defualt Constructor for the Sentence class:sets all pointers to NULL,
    //the max sentence and badwords sizes to 40, the number of sentence &
    //bad words to 0.
    Sentence();

    //Constructor for the Sentence class. max_words is the initial value of
    //both max_sentence_size and max_badwords_size
    Sentence(int max_words);

    //Reset sentence to 0 words actually stored - ie. reset all currently
    //words in the sentence dynamic array to""< and reset num_sentence_words
    //to 0.
    void clear();

    //Outputs the sentence to standard output (console).
    void print_sentence() const;

    //Add one word to the end of the sentence. word is the word to be added.
    //If the word passed in is a "bad" word (i.e. if you can find it in the
    //bad_words dynamic array) then, this function should obtain
    //the replacement word, and add that word to the sentence dynamic array
    //instead of the "bad" word.
    void add_word( const string & word );

    //Add one "bad" and its "good" replacement word to the list of bad word
    //objects. word is the "bad" word to be replaced and replacement is the
    //"good" word that will replace it in the censored sentence.
    void add_bad_word( const string & word, const string & replacement );

    //The destructor to deallocate all dynamically allocated arrays.
    ~Sentence();

    //PRIVATE MEMBER FUNCTIONS
    private:
    //EXTRA CREDIT: HELPER FUCTION USED TO RESIZE THE ARRAY WHEN NEEDED.
    void resize();

};

#endif //__SENTENCE_H__

