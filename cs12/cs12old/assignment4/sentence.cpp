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

// sentence.cpp
// Implement the Sentence class

#include "sentence.h"

//The default Constructor for the Sentence class: sets all pointers to NULL,
//the max sentence and badwords sizes to 40, the number of sentence & bad
//words to 0.
Sentence::Sentence()
:sentence(NULL),bad_words(NULL),max_sentence_size(40),
max_badwords_size(40),num_sentence_words(0),num_bad_words(0)
{
}

//Constructor for the Sentence class. max_words is the initial value
//of both max_sentence_size and max_badwords_size.
Sentence::Sentence(int max_words)
:max_sentence_size(max_words),max_badwords_size(max_words),
 num_sentence_words(0),num_bad_words(0)
{
 sentence = new string [max_sentence_size];
 bad_words = new Bad_word [max_badwords_size];
}

//Reset sentence to 0 words actually stored - i.e. reset all currently
//stored words in the sentence dynamic array to "", and reset
//num_sentence_words to 0.
void Sentence::clear()
{
    for(int i = 0; i < num_sentence_words; i++)
    {
        sentence[i] = "";
    }
    num_sentence_words = 0;
}

//Outputs the sentence to standard output (console).
void Sentence::print_sentence() const
{
    if(num_sentence_words <= max_sentence_size)
    {
        cout <<"\nCensored Sentence:: " << endl;
        for(int i = 0; i < num_sentence_words; i++)
        {
            cout << sentence[i] << " ";
        }
    }
}

//Add one word to the end of the sentence. word is the word to be added.
//If the word passed in is a "bad" word (i.e. if you can find it in the
//bad_words dynamic array) then, this function should obtain the replacement
//word, and add that word to the sentence dynamic array instead of the "bad"
//word.
//ALSO checks last sentence word.
void Sentence::add_word(const string & word)
{
    sentence[num_sentence_words] = word;

        for(int i = 0; i < max_badwords_size; i ++)
        {
            if( word == bad_words[i].get_badword())
            {
                sentence[num_sentence_words] = bad_words[i].get_replaceword();
            }
            else if( word == bad_words[i].get_badword() + "!")
            {
                sentence[num_sentence_words] =
                bad_words[i].get_replaceword() +"!";
            }
            else if( word == bad_words[i].get_badword() + ".")
            {
                sentence[num_sentence_words] =
                bad_words[i].get_replaceword() +".";
            }
            else if( word == bad_words[i].get_badword() + "?")
            {
                sentence[num_sentence_words] =
                bad_words[i].get_replaceword() +"?";
            }
        }
        num_sentence_words++;
}

//Add one "bad" and its "good" replacement word to the list of bad word
//objects. word is the "bad" word to be replaced and replacement is the
//"good" word that will replace it in the censored sentence.
void Sentence::add_bad_word(const string &word, const string & replacement)
{
    if(num_bad_words <= max_badwords_size)
    {
        bad_words[num_bad_words].set_badword(word);
        bad_words[num_bad_words].set_replaceword(replacement);
        num_bad_words++;
    }
}

//The destructor to deallocate all dynamically allocated arrays.
Sentence::~Sentence()
{
    delete []sentence;
    delete []bad_words;
    sentence = NULL;
    bad_words = NULL;
}


