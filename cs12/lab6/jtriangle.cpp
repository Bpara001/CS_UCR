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

//triangle implementation file

#include "jtriangle.h"

JTriangle::JTriangle()
{
  height = 0;
  width = 0;
}

//calls Shape constructor to set center Point
JTriangle::JTriangle(Point c, double h, double w)
  : JShape(c), height(h), width(w)
{
}

double JTriangle::area() const
{
  return (height * width) / 2;
}

void JTriangle::plot() const
{
Point center = get_center();
double x = center.get_x();
double y = center.get_y();
Point lower_right = Point(x + width/2, y + height/2);
Point lower_left =Point(x - width/2, y + height/2);
Point upper_right=Point(x + width/2, y - height/2);
Line horz = Line(lower_right,lower_left);
Line vert = Line(lower_right,upper_right);
Line diag = Line(lower_left,upper_right);

win << horz << vert << diag;

  win.output_buffer();
}


// dynamically allocates a JRectangle of default size at point passed in
JShape * JTriangle::make_shape(Point center) const
{
  return new JTriangle(center, 0.75,0.75);
}

JTriangle::~JTriangle()
{

}
