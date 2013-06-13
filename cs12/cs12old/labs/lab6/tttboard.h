// Course:              CS 12
// Assignment #:        7 Solutions
// ========================================================================
//! \file ttt_board.h
//! \brief Delaration of the TttBoard class.

#ifndef __TTTBOARD_H__
#define __TTTBOARD_H__

#include "ccc_win.h"
#include "tttcell.h"
#include "clickable.h"

//! \class TttBoard
//! \brief The Board for a game of tic-tac-toe.
class TttBoard : public Clickable
{
 public:
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Default constructor for the TttBoard class.
  TttBoard();

  //! \brief Constructor for the TttBoard class.
  //! \param ul_corner The upper left hand corner of the board.
  //! \param size The height and width of the board.
  TttBoard( const Point & ul_corner, const double size );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the TttBoard in the drawing area.
  //! \return Void.
  virtual void draw() const;

  //! \brief Move the object by a displacement.
  //! \param x_displace The distance to move the object in the x-direction.
  //! \param y_displace The distance to move the object in the y-direction.
  //! \return void.
  virtual void move( const double x_displace, const double y_displace );

  //! \brief Test to see if the board has been won.
  //! \return Whether the board has been won.
  bool isWon() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Reset the TttBoard so that all cells are empty.
  //! \return Void.
  void reset();

  //! \brief Attempt to fill the cell that is clicked with an X or O.
  //!
  //! An attempt may fail if the click is not on a cell, or the
  //! cell has already been chosen.
  //! \param click The area clicked on which may be inside a cell.
  //! \param fill The character ( X or O ) to assign to the cell.
  //! \return Whether the choice was successfully made.
  bool makeChoice( const Point & click, const char fill );

 private:
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                      Private Members                       ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Draw the grid lines for the board.
  //! \return Void.
  void drawGridLines() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                       Private Data                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  double size;          //!< The height and width of the board.
  Point pos;            //!< the position of the board.>

  TttCell ttt_cells[9]; //!< The cells of the board.
};

#endif // __TTTBOARD_H__
