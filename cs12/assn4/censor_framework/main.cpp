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

// main.cpp
// Test harness for censor assignment

#include "sentence.h"

int main()
{
   //Initializes variables
   string condition_badwords = "";
   string condition_sentence = "";
   Sentence the_sentence = Sentence(30);

   //Continous loop for add badwords
   while(condition_badwords != "n")
   {
      string bw = "";
      string rw= "";
      cout <<"\n====================================================="<<endl;
      cout <<"Input the bad word, followed by the replacement word!" << endl;
      cout <<"ex: 'damn darn'\n" << endl;

      cin >> bw >> rw;
      the_sentence.add_bad_word(bw,rw);

      cout <<"\n'" << rw <<"' will now replace '" << bw <<"'\n" << endl;
      cout <<"Add another badword?? Type 'y' or 'n': ";
      cin >> condition_badwords;
   }

   //Continous loop for inputing sentences and display censored sentences
   while(condition_sentence != "n")
   {
      int last_char = 0;
      string sentence_word = "";
      cout <<"\n====================================================="<<endl;
      cout <<"Input a sentence,";
      cout <<"end with period, question mark, or exclaimnation" << endl;
      cout <<"ex. 'That damn programming assignment was so easy!\n" << endl;

      //Must use 'do while' loop to keep the programing looping
      do
      {
         cin >> sentence_word;
         the_sentence.add_word(sentence_word);
         last_char = sentence_word.length() - 1;
      }
      while(sentence_word.substr(last_char,1) != "!"
      && sentence_word.substr(last_char,1) != "?"
      && sentence_word.substr(last_char,1) != ".");

      cout << endl;
      the_sentence.print_sentence();
      cout <<"\nInput another sentence? Type 'y' or 'n': ";
      cin >> condition_sentence;
      the_sentence.clear();
   }
   cout <<"\nQuiting censor program...\n" << endl;
   return 0;
}
