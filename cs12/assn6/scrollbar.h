// Course:              CS 12
// Assignment #:        Textviewer
// ========================================================================
//! \file button.h
//! \brief Delaration of the Scrollbar class.

#ifndef __SCROLLBAR_H__
#define __SCROLLBAR_H__

#include "clickable.h"
#include "instinct.h"

//! \class Scrollbar
//! \brief A clickable scrollbar with 2 clickable "buttons" to scroll with
class Scrollbar : public Clickable
{
public:
    //Scrollbars can be horizontal or vertical (only vertical implemented)
    enum Orientation { VERTICAL, HORIZONTAL };
private:
    //! \class ScrollbarArrow
    //! \brief The clickable arrows of the Scrollbar class
    class ScrollbarArrow : public Clickable
    {
    public:
        //Arrows can point up, down, left, or right (only up/down implemented)
        enum Direction { UP, DOWN, LEFT, RIGHT };
        ScrollbarArrow();
        ScrollbarArrow( const Point& ll_corner, const double& size );
        virtual void draw() const;
        virtual void move( double x_displace, double y_displace );
        Direction direction;
    };

    ScrollbarArrow first;
    ScrollbarArrow second;
    Orientation orientation;
    
public:
    
    
    Scrollbar();
    Scrollbar( const Point & ll_corner, const double & height,
               const double & width );
    virtual void draw() const;
    virtual void move( double x_displace, double y_displace );
    ScrollbarArrow get_first() const;
    ScrollbarArrow get_second() const;


    
};

#endif
