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
// ========================================================================

//! \file button.h
//! \brief Delaration of the button class.

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include "instinct.h"
#include "clickable.h"

//! \class Button
//! \brief A clickable button with a label.
class Button : public Clickable
{
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 public:
  //! \brief Default constructor for the Button class.
  Button();

  //! \brief Constructor for the Button class.
  //! \param ll_corner The position of the lower left corner of the Button.
  //! \param label The label written inside the Button.
  Button( const Point & ll_corner, const std::string & label );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the Button in the drawing area.
  //! \return void.
  virtual void draw() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  //! \brief Move the Button by a displacement.
  //! \param x_displace The distance to move the Button in the x-direction.
  //! \param y_displace The distance to move the Button in the y-direction.
  //! \return void.
  virtual void move( double x_displace, double y_displace );
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                 Private Members and Data                   ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 private:
  std::string label;	//!< The text label inside the Button.
  Point label_pos;	//!< The position where the label should be drawn.
};

#endif // __BUTTON_H__