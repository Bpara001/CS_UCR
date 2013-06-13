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

// sentence.cpp
// Implement the Sentence class
#include "sentence.h"

//The defualt Constructor for the Sentence class:sets all pointers to NULL,
//the max sentence and badwords sizes to 40, the number of sentence &
//bad words to 0.
Sentence::Sentence()
:max_sentence_size(40),max_badwords_size(40),
num_sentence_words(0),num_bad_words(0),
sentence(NULL),bad_word(NULL)
{
}

//Constructor for the Sentence class. max_words is the initial value of
//both max_sentence_size and max_badwords_size
Sentence::Sentence(int max_words)
:max_sentence_size(max_words),max_badwords_size(max_words),
num_sentence_words(0),num_bad_words(0),
sentence(new string[max_words]),bad_word(new Bad_word[max_words])
{
}

//Reset sentence to 0 words actually stored - ie. reset all currently
//words in the sentence dynamic array to"", and reset num_sentence_words
//to 0.
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
    cout <<"Censored: ";
    for(int i =0; i < num_sentence_words; i++)
    {
        cout << sentence[i] << " ";
    }
    cout << endl;
}

//Add one word to the end of the sentence. word is the word to be added.
//If the word passed in is a "bad" word (i.e. if you can find it in the
//bad_words dynamic array) then, this function should obtain
//the replacement word, and add that word to the sentence dynamic array
//instead of the "bad" word.
void Sentence::add_word( const string & word )
{
    bool is_badword = false;

    if(num_sentence_words == max_sentence_size)
    {
       resize();
    }
    for(int i = 0; i < num_bad_words; i ++)
    {
        if(word == bad_word[i].get_badword()
        || word == bad_word[i].get_badword() + "!"
        || word == bad_word[i].get_badword() + "?"
        || word == bad_word[i].get_badword() + "."
        || word == bad_word[i].get_badword() + ",")
        {
            sentence[num_sentence_words] = bad_word[i].get_replaceword();
            is_badword = true;
        }
    }
    if(is_badword == false)
    {
        sentence[num_sentence_words] = word;
    }

    num_sentence_words++;
}

//Add one "bad" and its "good" replacement word to the list of bad word
//objects. word is the "bad" word to be replaced and replacement is the
//"good" word that will replace it in the censored sentence.
void Sentence::add_bad_word( const string & word, const string & replacement )
{
    if(num_bad_words == max_badwords_size)
    {
        resize();
    }
    bad_word[num_bad_words].set_badword(word);
    bad_word[num_bad_words].set_replaceword(replacement);
    num_bad_words++;
}

//The destructor to deallocate all dynamically allocated arrays.
Sentence::~Sentence()
{
    delete []sentence;
    sentence = NULL;
    delete []bad_word;
    bad_word = NULL;
}
//PRIVATE MEMBER FUNCTIONS
//EXTRA CREDIT: HELPER FUCTION USED TO RESIZE THE ARRAY WHEN NEEDED.
void Sentence::resize()
{
    max_sentence_size = max_sentence_size* 2;
    max_badwords_size = max_badwords_size* 2;
    string* temp1 = new string[max_sentence_size];
    Bad_word* temp2 = new Bad_word[max_badwords_size];

    for(int i = 0; i < num_sentence_words; ++i)
    {
        temp1[i] = sentence[i];
    }

    for(int i = 0; i < num_bad_words; ++i)
    {
        temp2[i] = bad_word[i];
    }

    delete []sentence;
    delete []bad_word;
    sentence = temp1;
    bad_word = temp2;
}
