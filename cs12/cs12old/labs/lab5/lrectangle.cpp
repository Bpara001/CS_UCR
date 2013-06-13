//rectangle implementation file

#include "lrectangle.h"
#include "instinct.h"

LRectangle::LRectangle()
{
  height = 0;
  width = 0;
}

//calls Shape constructor to set center Point
LRectangle::LRectangle(Point c, double h, double w) 
  : LShape(c), height(h), width(w)
{
}

double LRectangle::area() const
{
  return height * width;
}

void LRectangle::plot() const
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


// dynamically allocates a LRectangle of default size at point passed in
LShape * LRectangle::make_shape(Point center) const
{
  return new LRectangle(center, 0.5, 1);
}

LRectangle::~LRectangle()
{

}
