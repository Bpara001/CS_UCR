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

//class Shape header file

#ifndef __JShape_H__
#define __JShape_H__

#include "instinct.h"

//base class
class JShape
{
public:
    JShape();
    JShape(Point);
    Point get_center() const;
    virtual double area() const = 0;
    virtual void plot() const = 0;
    virtual JShape * make_shape(Point) const = 0;
    virtual ~JShape();
private:
    Point center;
};

#endif
