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
// Assignment: Programming Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================


//Implementation of the button class.
#include "button.h"

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  //! \brief Default constructor for the Button class.
  Button::Button()
  :shown(true),label(" "),label_pos(Point(0,0)),border(Rect(Point(0,0),0,0))
  {
  }

  //! \brief Constructor for the Button class.
  //! \param ll_corner The position of the lower left corner of the Button.
  //! \param label The label written inside the Button.

  Button::Button( const Point & ll_corner, const std::string & label )
  :shown(true),label(label),
  //Claculates the position of the text inside the box
  label_pos(ll_corner.get_x()+ LETTER_WIDTH/2,
            ll_corner.get_y()+LETTER_HEIGHT/2),
  //Calculates the height and width of the rectangle
  border(Rect(ll_corner, label.length()*LETTER_WIDTH + LETTER_WIDTH,
         LETTER_HEIGHT*2))
  {
  }

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the Button in the drawing area.
  //! \return void.
  void Button::draw() const
  {
      if(shown == true)
      {
          win << border << Message(label_pos,label);
      }
  }


  //! \brief Test to see if the button has been clicked.
  //!
  //! Only visible buttons are can be clicked.
  //! \param click The point corresponding to the mouse click to test.
  //! \return Whether the Button has been clicked.
  bool Button::is_clicked( const Point & click ) const
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

  //! \brief Determine whether the Button is set as shown.
  //! \return Whether the button is shown.
  bool Button::is_shown() const
  {
      if(shown == true)
      {
          return true;
      }
      else return false;
  }

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Make the Button visible in the drawing window when drawn.
  //! \return void.
  void Button::show()
  {
      shown = true;
  }

  //! \brief Make the Button invisible in the drawing area when drawn.
  //! \return void.
  void Button::hide()
  {
      shown = false;
  }

  //! \brief Move the Button by a displacement.
  //! \param x_displace The distance to move the Button in the x-direction.
  //! \param y_displace The distance to move the Button in the y-direction.
  //! \return void.
  void Button::move( double x_displace, double y_displace )
  {
      label_pos = Point(label_pos.get_x() + x_displace,
                        label_pos.get_y() + y_displace);

      border = Rect(Point(border.get_lower_left().get_x() + x_displace,
                    border.get_lower_left().get_y() + y_displace),
                    border.get_width(),border.get_height());


  }

  //! \brief Move the upper left corner of the Button to a position.
  //! \param loc The location to move the Button to.
  //! \return void.
  void Button::move_to( const Point & loc )
  {
      move(loc.get_x() - label_pos.get_x(),loc.get_y() - label_pos.get_y());
  }

  //! \brief Center the button about a point.
  //! \param loc The location about which to center the Button.
  //! \return void.
  void Button::center( const Point & loc )
  {
      move_to(Point(loc.get_x() - border.get_width() /2,
      loc.get_y() - border.get_height() /2 ));
  }
