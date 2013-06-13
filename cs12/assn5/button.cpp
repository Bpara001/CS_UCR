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
// button.cpp
#include "button.h"

Button::Button()
:Clickable(Point(0,0),0,0),label(""),label_pos(Point(0,0))
{
}

Button::Button(const Point &ll_corner, const std::string &label)
:Clickable(ll_corner, label.length()*LETTER_WIDTH + LETTER_WIDTH,
         LETTER_HEIGHT*2),
label(label),
label_pos(ll_corner.get_x()+ LETTER_WIDTH/2,
            ll_corner.get_y()+LETTER_HEIGHT/2)
{
}

//! \brief Draw the Button in the drawing area.
void Button::draw() const
{
    Clickable::draw();
    if(is_shown() == true)
    {
        win << Message(label_pos,label);
    }

}

//! \brief Move the Button by a given x, y displacement.
void Button::move( double x_displace, double y_displace )
{
    label_pos.move(x_displace,y_displace);
    border.move(x_displace,y_displace);
}


