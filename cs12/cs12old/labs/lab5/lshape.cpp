//Shape implementation file

#include "lshape.h"

LShape::LShape()
  : center( Point(0,0) )
{
}

LShape::LShape(Point center)
  : center( center )
{
}

Point LShape::get_center() const
{
  return center;
}

LShape::~LShape()
{
}
