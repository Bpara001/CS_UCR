// Course:              CS 12
// Assignment #:        2
// ========================================================================
//! \file button.h
//! \brief Delaration of the button class.

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include "instinct.h"

//! \class Button
//! \brief A clickable button with a label.
class Button
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
  void draw() const;

  //! \brief Test to see if the button has been clicked.
  //! 
  //! Only visible buttons are can be clicked.
  //! \param click The point corresponding to the mouse click to test.
  //! \return Whether the Button has been clicked.
  bool is_clicked( const Point & click ) const;

  //! \brief Determine whether the Button is set as shown.
  //! \return Whether the button is shown.
  bool is_shown() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  //! \brief Make the Button visible in the drawing window when drawn.
  //! \return void.
  void show();

  //! \brief Make the Button invisible in the drawing area when drawn.
  //! \return void.
  void hide();

  //! \brief Move the Button by a displacement.
  //! \param x_displace The distance to move the Button in the x-direction.
  //! \param y_displace The distance to move the Button in the y-direction.
  //! \return void.
  void move( double x_displace, double y_displace );
  
  //! \brief Move the upper left corner of the Button to a position.
  //! \param loc The location to move the Button to.
  //! \return void.
  void move_to( const Point & loc );

  //! \brief Center the button about a point.
  //! \param loc The location about which to center the Button.
  //! \return void.
  void center( const Point & loc );
  
 private:
  bool shown;		//!< Whether the Button is currently shown.
  std::string label;	//!< The text label inside the Button.
  Point label_pos;	//!< The position where the label should be drawn
  Rect border;          //!< The border of the button  
 
};

#endif // __BUTTON_H__
