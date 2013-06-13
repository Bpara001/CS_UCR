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

// triangle header file

#ifndef __OTRIANGLE_H__
#define __OTRIANGLE_H__

#include "jshape.h"
#include "instinct.h"


class JTriangle : public JShape
{
public:
    JTriangle();
    JTriangle(Point, double h, double w);
    virtual double area() const;
    virtual void plot() const;
    virtual JShape * make_shape(Point) const;
    virtual ~JTriangle();
private:
    double height;
    double width;

};


#endif
