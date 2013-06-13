// Course:              CS 12
// Assignment #:        5 Solutions
// ========================================================================
//! \file clickable.h
//! \brief Delaration of the abstract base class Clickable.

#ifndef __CLICKABLE_H__
#define __CLICKABLE_H__

#include "ccc_shap.h"

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
  Clickable( const Point &ul_corner, const double height,
	     const double width );

  //! \brief Constructor for the Clickable class.
  //! \param ul_corner The position of the upper left corner of the object.
  //! \param ur_corner The position of the upper right corner of the object.
  //! \param lr_corner The position of the lower right corner of the object.
  //! \param ll_corner The position of the lower left corner of the object.
  Clickable( const Point &ul_corner, const Point &ur_corner,
	     const Point &lr_corner, const Point &ll_corner );

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
  bool isClicked( const Point &click ) const;

  //! \brief Test to see if the object is currently shown.
  //! \return Whether the object is currently shown.
  bool isShown() const;

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
  virtual void move( const double x_displace, const double y_displace ) = 0;
  
  //! \brief Move the upper left corner of the object to a position.
  //! \param loc The location to move the object to.
  //! \return void.
  void moveTo( const Point &loc );

  //! \brief Center the object about a point.
  //! \param loc The location about which to center the object.
  //! \return void.
  void center( const Point &loc );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                 Private Members and Data                   ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 protected:
  bool shown;		//!< Whether the object is currently shown.

  Point ul_corner;	//!< The upper left corner of the object.
  Point ur_corner;	//!< The upper right corner of the object.
  Point lr_corner;	//!< The lower right corner of the object.
  Point ll_corner;	//!< The lower left corner of the object.
};

#endif // __CLICKABLE_H__
