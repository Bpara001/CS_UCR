// Course:              CS 12
// Assignment #:        7 Solutions
// ========================================================================
//! \file ttt_cell.h
//! \brief implementation of the TttCell class
#ifndef __TTTCELL_H__
#define __TTTCELL_H__

#include "ccc_win.h"
#include "clickable.h"

//! \class TttCell
//! \brief A cell for the game tic-tac-toe
class TttCell : public Clickable
{
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 public:
  //! \brief Default constructor for the TttCell class.
  TttCell();

  //! \brief Constructor for the TttCell class.
  //! \param ul_corner The upper left hand corner of the cell.
  //! \param size The height and width of the cell.
  TttCell( const Point & ul_corner, const double size );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the TttCell in the drawing area.
  //! \return Void.
  virtual void draw() const;

  //! \brief Move the object by a displacement.
  //! \param x_displace The distance to move the object in the x-direction.
  //! \param y_displace The distance to move the object in the y-direction.
  //! \return void.
  virtual void move( const double x_displace, const double y_displace );

  //! \brief Test to see if the cell is empty.
  //! \return Whether the TttCell is empty.
  bool isEmpty() const;

  //! \brief Test to see if the cell contains an X.
  //! \return Whether the TttCell contains an X.
  bool isX() const;

  //! \brief Test to see if the cell contains an O.
  //! \return Whether the TttCell contains an O.
  bool isO() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Reset the TttCell to be empty.
  //! \return Void.
  void reset();
  
  //! \brief Set the cell to contain an X
  //! \return Void.
  void setAsX();

  //! \brief Set the cell to contain an O
  //! \return Void.
  void setAsO();

 private:
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                      Private Members                       ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw an X shape in the cell.
  //! \return Void.
  void drawX() const;

  //! \brief Draw an O shape in the cell.
  //! \return Void.
  void drawO() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                       Private Data                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  double size;		//!< The height and width of the cell.
  char contents;	//!< What the cell contains ' ' means empty.
};

#endif // __TTTCELL_H__
