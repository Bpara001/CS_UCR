// Course:              CS 12
// Assignment #:        Clickable Solutions
// ========================================================================
//! \file clickable.h
//! \brief Delaration of the abstract base class Clickable.

#ifndef __CLICKABLE_H__
#define __CLICKABLE_H__

#include "instinct.h"

//! \class Clickable.
//! \brief An abstract base class for a clickable object.
class Clickable
{
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 public:
  //! \brief Default constructor for the Clickable class.
  Clickable();

  //! \brief Constructor for the Clickable class.
  //! \param ul_corner The position of the upper left corner of the object.
  //! \param height The height of the object.
  //! \param width The width of the object.
  Clickable( const Point & ll_corner, double height, double width );

  //! \brief Destructor for the Clickable class.
  virtual ~Clickable();
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the object in the drawing area.
  //! \return void.
  virtual void draw() const = 0;

  //! \brief Test to see if the object has been clicked.
  //! 
  //! Only visible objects can be clicked.
  //! \param click The point corresponding to the mouse click to test.
  //! \return Whether the object has been clicked.
  bool is_clicked( const Point & click ) const;

  //! \brief Test to see if the object is currently shown.
  //! \return Whether the object is currently shown.
  bool is_shown() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  //! \brief Make the object visible in the drawing window when drawn.
  //! \return void.
  virtual void show();

  //! \brief Make the object invisible in the drawing area when drawn.
  //! \return void.
  virtual void hide();

  //! \brief Move the object by a displacement.
  //! \param x_displace The distance to move the object in the x-direction.
  //! \param y_displace The distance to move the object in the y-direction.
  //! \return void.
  virtual void move( double x_displace, double y_displace ) = 0;
  
  //! \brief Move the upper left corner of the object to a position.
  //! \param loc The location to move the object to.
  //! \return void.
  void move_to( const Point & loc );

  //! \brief Center the object about a point.
  //! \param loc The location about which to center the object.
  //! \return void.
  void center( const Point & loc );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                 Private Members and Data                   ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 private:
  bool shown;		//!< Whether the object is currently shown.

 protected:   
  Rect border;        //!< The border of the object
  };

#endif // __CLICKABLE_H__
