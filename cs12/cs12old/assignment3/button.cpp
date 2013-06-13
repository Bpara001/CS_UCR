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
// Assignment: Programming Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.

//~~~~~~Implementation of the button class.

#include <iostream>
#include "button.h"
#include "instinct.h"
using namespace std;


  //~~~~~CONSTRUCTORS AND DECONSTRUCTORS~~~~~~

  // brief Default constructor for the Button class.
  Button::Button()
  {
      shown = true;
      label = " ";
      label_pos = Point(0,0);
      border = Rect(Point(0,0),0,0);
  }

  // brief Constructor for the Button class.
  // param ll_corner The position of the lower left corner of the Button.
  // param label The label written inside the Button.
  Button::Button( const Point & ll_corner, const std::string & label_s )
  {
      int string_length = label_s.length();
      double xpoint = ll_corner.get_x();
      double ypoint = ll_corner.get_y();
      double message_x = xpoint + LETTER_WIDTH/2;
      double message_y = ypoint + LETTER_HEIGHT/2;
      double box_w = string_length * LETTER_WIDTH + LETTER_WIDTH;
      double box_h = LETTER_HEIGHT * 2;

      label_pos = Point(message_x,message_y);
      border = Rect(ll_corner,box_w,box_h);
      label = label_s;
      shown = true;

      //win << border << Message(label_pos,label_s);
      //win.output_buffer();
  }

  // ~~~~~ACCESSORS~~~~~

  // brief Draw the Button in the drawing area.
  // return void.
  void Button::draw() const
  {
      if (shown == true)
      {
        win << border << Message(label_pos,label);
      }
  }

  // brief Test to see if the button has been clicked.
  // Only visible buttons are can be clicked.
  // param click The point corresponding to the mouse click to test.
  // return Whether the Button has been clicked.
  bool Button::is_clicked( const Point & click ) const
  {
      double xclick = click.get_x();
      double yclick = click.get_y();
      Point lowerleft = border.get_lower_left();
      double x_ll = lowerleft.get_x();
      double y_ll = lowerleft.get_y();
      double height = border.get_height();
      double width = border.get_width();

      if(yclick > y_ll && yclick < y_ll + height && xclick > x_ll
         && xclick < x_ll + width)
        {
             return true;
        }
       else return false;
  }

  // brief Determine whether the Button is set as shown.
  // return Whether the button is shown.
  bool Button::is_shown() const
  {
      if (shown == true)
      {
          return true;
      }
      else
      {
          return false;
      }
  }


  // ~~~~~MUTATORS~~~~~

  // brief Make the Button visible in the drawing window when drawn.
  // return void.
  void Button::show()
  {
      shown = true;
  }

  // brief Make the Button invisible in the drawing area when drawn.
  // return void.
  void Button::hide()
  {
      shown = false;
  }

  // brief Move the Button by a displacement.
  // param x_displace The distance to move the Button in the x-direction.
  // param y_displace The distance to move the Button in the y-direction.
  // return void.
  void Button::move( double x_displace, double y_displace )
  {
      Point ll_corner = border.get_lower_left();
      double message_x = label_pos.get_x() + x_displace;
      double message_y = label_pos.get_y() + y_displace;
      double xpoint = ll_corner.get_x() + x_displace;
      double ypoint = ll_corner.get_y() + y_displace;

      border=Rect(Point(xpoint,ypoint),border.get_width(),border.get_height());
      label_pos = Point(message_x,message_y);
  }

  // brief Move the upper left corner of the Button to a position.
  // param loc The location to move the Button to.
  // return void.
  void Button::move_to( const Point & loc )
  {
      Point ll_corner = border.get_lower_left();
      double x_displace = loc.get_x() - ll_corner.get_x();
      double y_displace = loc.get_y() - ll_corner.get_y();
      double message_x = label_pos.get_x() + x_displace;
      double message_y = label_pos.get_y() + y_displace - border.get_height();
      double xpoint = ll_corner.get_x() + x_displace;
      double ypoint = ll_corner.get_y() + y_displace - border.get_height();

      border=Rect(Point(xpoint,ypoint),border.get_width(),border.get_height());
      label_pos = Point(message_x,message_y);

  }

  // brief Center the button about a point.
  // param loc The location about which to center the Button.
  // return void.
  void Button::center( const Point & loc )
  {
      Point ll_corner = border.get_lower_left();
      double x_displace = loc.get_x() - ll_corner.get_x();
      double y_displace = loc.get_y() - ll_corner.get_y();
      double message_x = label_pos.get_x() + x_displace- border.get_width()/2;
      double message_y = label_pos.get_y() + y_displace - border.get_height()/2;
      double xpoint = ll_corner.get_x() + x_displace - border.get_width()/2;
      double ypoint = ll_corner.get_y() + y_displace - border.get_height()/2;

      border=Rect(Point(xpoint,ypoint),border.get_width(),border.get_height());
      label_pos = Point(message_x,message_y);;
  }

