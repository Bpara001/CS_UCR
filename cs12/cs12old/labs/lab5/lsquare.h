//square interface file

/****DO NOT EDIT THIS FILE****/

#ifndef __LSQUARE_H__
#define __LSQUARE_H__

#include "lrectangle.h"

class LSquare : public LRectangle
{
 public:
  LSquare();
  LSquare(Point, double);
  virtual LShape * make_shape(Point) const;
};

#endif
