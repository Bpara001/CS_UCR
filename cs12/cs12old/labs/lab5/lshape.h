//class Shape header file

#ifndef __LSHAPE_H__
#define __LSHAPE_H__

#include "instinct.h"

//base class
class LShape
{
public:
    LShape();
    LShape(Point);
    Point get_center() const;
    virtual double area() const = 0;
    virtual void plot() const = 0;
    virtual LShape * make_shape(Point) const = 0;
    virtual ~LShape();
private:
    Point center;
};
  
#endif
