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
// Assignment: lab 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
// This program plays a guessing game where you try to guess the number
// the computer has picked.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//changed the bounds of the number to be inbetween 1 and 100
int main()
{
  int number_to_guess = rand()%101;
  int guess = 0;

  cout << "Guess a number between 1 and 100." << endl
	    << "? ";

//removed equal&less than, equal&greater than, changed to donotequal
  do
  {
    cin >> guess;

    if ( guess > number_to_guess )
      cout << "Try lower." << endl << "? ";

    else if ( guess < number_to_guess )
      cout << "Try Higher." << endl << "? ";

    else
    {
      cout << "You guessed right!!!" << endl;
    }
  } while ( number_to_guess != guess );

  return 0;
}
