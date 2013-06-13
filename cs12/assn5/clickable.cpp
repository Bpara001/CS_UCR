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
// Assignment: Programming Assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
// clickable.cpp
#include "clickable.h"

Clickable::Clickable()
:shown(true),border(Point(0,0),0,0)
{
}

Clickable::Clickable(const Point &ll_corner, double width, double height)
:shown(true),border(ll_corner,width,height)
{
}

Clickable::~Clickable()
{
}

//! \brief Draw the object in the drawing area.

void Clickable::draw() const
{
    if(shown == true)
    {
        win << border;
    }
}

//! \brief Test to see if the object has been clicked.
bool Clickable::is_clicked( const Point &click ) const
{
    double xbox = border.get_lower_left().get_x();
    double ybox = border.get_lower_left().get_y();
    double w = border.get_width();
    double h = border.get_height();
    double xclick = click.get_x();
    double yclick = click.get_y();

    if(xclick > xbox && xclick < xbox+w && yclick > ybox && yclick < ybox+h)
    {
        return true;
    }
    else return false;
}

//! \brief Test to see if the object is currently shown.
bool Clickable::is_shown() const
{
    if(shown == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//! \brief Make the object visible in the drawing window when drawn.
void Clickable::show()
{
    shown = true;
}

//! \brief Make the object invisible in the drawing area when drawn.
void Clickable::hide()
{
    shown = false;
}

//! \brief Move the object by a displacement.
/*
void Clickable::move( double x_displace, double y_displace )
{
border = Rect(Point(border.get_lower_left().get_x() + x_displace,
                    border.get_lower_left().get_y() + y_displace),
                    border.get_width(),border.get_height());

                    //border.move(x_displace,y_displace
}
*/

//! \brief Move the lower left corner of the object to a position.
void Clickable::move_to( const Point &loc )
{
    move(loc.get_x() - border.get_lower_left().get_x(),
    loc.get_y() - border.get_lower_left().get_y());
}

//! \brief Center the object about a point.
void Clickable::center( const Point &loc )
{
    move_to(Point(loc.get_x() - border.get_width() /2,
    loc.get_y() - border.get_height() /2 ));
}





