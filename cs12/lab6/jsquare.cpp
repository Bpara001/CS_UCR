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
// Assignment: LAB 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

//square implementation file

#include "jsquare.h"

JSquare::JSquare()
:JRectangle(Point(0,0),0,0)
{
}
JSquare::JSquare(Point p, double d)
:JRectangle(p,d,d)
{
}
JShape * JSquare::make_shape(Point p) const
{
    return new JSquare(p, 1);
}

