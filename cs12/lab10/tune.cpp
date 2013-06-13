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
// Assignment: LAB 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "tune.h"
using namespace std;



Tune::Tune()
:title("")
{
}

Tune::Tune(string n)
:title(n)
{
}

string Tune::get_title() const
{
    return title;
}
