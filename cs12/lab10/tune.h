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
#ifndef __TUNE_H__
#define __TUNE_H__

#include <iostream>
using namespace std;

class Tune

{

private:
string title;

public:
Tune();
Tune(string n);
string get_title() const;


};

#endif
