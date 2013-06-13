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

//Shape implementation file

#include "jshape.h"

JShape::JShape()
  : center( Point(0,0) )
{
}

JShape::JShape(Point center)
  : center( center )
{
}

Point JShape::get_center() const
{
  return center;
}

JShape::~JShape()
{
}
