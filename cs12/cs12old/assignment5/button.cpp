// Course: CS 12 quarter 2 , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 001
// Lab Section: 021
// TA: Denise Duma
//
// Assignment: Programming Assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.


// button.cpp
#include "button.h"

  // \brief Default constructor for the Button class.
Button::Button()
:  Clickable(),label(""),label_pos(Point(50,50))
{
}

  // \brief Constructor for the Button class.
  // \param ll_corner The position of the lower left corner of the Button.
  // \param label The label written inside the Button.
Button::Button( const Point & ll_corner, const std::string & label )
:Clickable(ll_corner,label.length() * LETTER_WIDTH + LETTER_WIDTH,
           LETTER_HEIGHT + LETTER_HEIGHT),
label_pos (Point(ll_corner.get_x() + (LETTER_WIDTH/2),
                 ll_corner.get_y() + (LETTER_HEIGHT /2)))
{
   this->label=label;
}

  // \brief Draw the Button in the drawing area.
  // \return void.
void Button::draw() const
{
  if(is_shown()==true)
   {
   Clickable::draw();
   win << Message(label_pos,label);
   }
}

  // \brief Move the Button by a displacement.
  // \param x_displace The distance to move the Button in the x-direction.
  // \param y_displace The distance to move the Button in the y-direction.
  // \return void.
void Button::move( double x_displace, double y_displace )
{


   label_pos.move(x_displace,y_displace);
   border.move(x_displace,y_displace);

}



