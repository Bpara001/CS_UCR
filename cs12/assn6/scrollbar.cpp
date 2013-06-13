
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
// Assignment: assn6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#include "scrollbar.h"

Scrollbar::Scrollbar()
{
    orientation = VERTICAL;
}
Scrollbar::Scrollbar( const Point & ll_corner, const double & height,
                      const double & width )
    : Clickable(ll_corner, height, width)
{
    orientation = VERTICAL;
    first = ScrollbarArrow(Point(ll_corner.get_x(),
                                 ll_corner.get_y() + height - width), width);
    first.direction = ScrollbarArrow::UP;
    second = ScrollbarArrow(Point(ll_corner.get_x(),ll_corner.get_y()), width);
    second.direction = ScrollbarArrow::DOWN;
    first.show();
    second.show();
}
void Scrollbar::draw() const
{
    if( is_shown() )
    {
        Clickable::draw();
        first.draw();
        second.draw();
        win.output_buffer();
    }
}
void Scrollbar::move( double x_displace, double y_displace )
{
    Clickable::move(x_displace, y_displace);
    first.move(x_displace, y_displace);
    second.move(x_displace, y_displace);
}

Scrollbar::ScrollbarArrow Scrollbar::get_first() const
{
    return first;
}

Scrollbar::ScrollbarArrow Scrollbar::get_second() const
{
    return second;
}


Scrollbar::ScrollbarArrow::ScrollbarArrow()
{

}
Scrollbar::ScrollbarArrow::ScrollbarArrow( const Point& ll_corner,
                                           const double& size )
    : Clickable(ll_corner, size, size)
{

}
void Scrollbar::ScrollbarArrow::draw() const
{
    if( is_shown() )
    {
        Clickable::draw();
        if( direction == UP )
        {
            win << Triangle(Point(border.get_lower_left().get_x()
                                  + border.get_width()*.5,
                                  border.get_lower_left().get_y()
                                  + border.get_height()),
                            border.get_lower_left(),
                            Point(border.get_lower_left().get_x()
                                  + border.get_width(),
                                  border.get_lower_left().get_y()));
        }
        else if( direction == DOWN )
        {
            win << Triangle(Point(border.get_lower_left().get_x()
                                  + border.get_width()*.5,
                                  border.get_lower_left().get_y()),
                            Point(border.get_lower_left().get_x(),
                                  border.get_lower_left().get_y()
                                  + border.get_height()),
                            Point(border.get_lower_left().get_x()
                                  + border.get_width(),
                                  border.get_lower_left().get_y()
                                  + border.get_height()));
        }
        win.output_buffer();
    }
}
void Scrollbar::ScrollbarArrow::move( double x_displace, double y_displace )
{
    Clickable::move(x_displace, y_displace);
}
