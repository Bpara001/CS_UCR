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


// main.cpp
// Test harness for censor assignment

#include "bad_word.h"
#include "sentence.h"

using namespace std;

int main()
{
    string input = "";
    string censor = "";
    string replacement = "";
    string choice1 = "";
    string choice2 = "";
    int max = 80;
    int count = 0;
    Sentence sen(max);
    int count2 = 0;

    //Reads, and inputs censored words
    while( choice1 != "no" & max > count2)
    {
        cout << "\nEnter a word to censor " << endl;
        cin >> censor;
        cout << "Enter the replacement word" << endl;
        cin >> replacement;
        sen.add_bad_word(censor,replacement);

        cout <<"\nEnter another censored word?(type 'yes' or 'no')" << endl;
        cin >> choice1;
        count2++;
    }

    //Reads, inputs, and outputs sentence and goes through censor
    while( choice2 != "no")
    {
        cout << "\nEnter a sentence, end the sentence with '. ? !'" << endl;

        do
        {
        cin >> input;
        sen.add_word(input);
        count++;
        }
        while( input.substr(input.length() -1, 1) !="."
           && input.substr(input.length() -1, 1) !="?"
           && input.substr(input.length() -1, 1) !="!"
           && count < max);
        sen.print_sentence();

        cout << endl;
        cout << endl;
        cout <<"\nEnter another Sentence?(type 'yes' or 'no')" << endl;
        cin >> choice2;
        sen.clear();
        count = 0;

    }
    return 0;
}
