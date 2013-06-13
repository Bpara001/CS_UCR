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

//rectangle implementation file

#include "jrectangle.h"
#include "instinct.h"

JRectangle::JRectangle()
{
  height = 0;
  width = 0;
}

//calls Shape constructor to set center Point
JRectangle::JRectangle(Point c, double h, double w)
  : JShape(c), height(h), width(w)
{
}

double JRectangle::area() const
{
  return height * width;
}

void JRectangle::plot() const
{
  //corners are 1/2 width and 1/2 height from center
  double horiz_displacement = width / 2.0;
  double vert_displacement = height / 2.0;

  //calculate 3 corners
  Point upper_left = get_center();
  upper_left.move(-horiz_displacement, -vert_displacement);
  Point lower_left = get_center();
  lower_left.move(-horiz_displacement, vert_displacement);
  Point lower_right = get_center();
  lower_right.move(horiz_displacement, vert_displacement);

  //construct and output left vertical and lower horizontal lines
  Line vert = Line(lower_left, upper_left);
  Line horiz = Line(lower_left, lower_right);
  win << vert << horiz;

  //move lines and output right vertical and upper horizontal lines
  vert.move(width, 0);
  horiz.move(0, -height);
  win << vert << horiz;

  win.output_buffer();
}


// dynamically allocates a JRectangle of default size at point passed in
JShape * JRectangle::make_shape(Point center) const
{
  return new JRectangle(center, 0.5, 1);
}

JRectangle::~JRectangle()
{

}
