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

//rectangle header file

#ifndef __JRectangle_H__
#define __JRectangle_H__

#include "jshape.h"
#include "instinct.h"

class JRectangle : public JShape
{
public:
    JRectangle();
    JRectangle(Point, double, double);
    virtual double area() const;
    virtual void plot() const;
    virtual JShape * make_shape(Point) const;
    virtual ~JRectangle();
private:
    double height;
    double width;
};

#endif
