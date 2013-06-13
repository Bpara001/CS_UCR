//rectangle header file

#ifndef __LRECTANGLE_H__
#define __LRECTANGLE_H__

#include "lshape.h"
#include "instinct.h"

class LRectangle : public LShape
{
public:
    LRectangle();
    LRectangle(Point, double, double);
    virtual double area() const;
    virtual void plot() const;
    virtual LShape * make_shape(Point) const;
    virtual ~LRectangle();
private:
    double height;
    double width;
};

#endif
