// Course:              CS 12
// Assignment #:        1 Solutions
// ========================================================================
//! \file global_const.h
//! \brief Delaration and definition of constants which are to be used in the
//!        drawing area.

#ifndef __GLOBAL_CONST_H__
#define __GLOBAL_CONST_H__

#include "ccc_shap.h"

const double WINDOW_WIDTH = 100;	
//!< The width of the window

const double WINDOW_HEIGHT = 100;	
//!< The height of the window

const Point UPPER_LEFT = Point( 0, 0 );	
//!< The upper left coordinate of the drawing area

const Point LOWER_RIGHT = Point( UPPER_LEFT.get_x() + WINDOW_WIDTH, 
				 UPPER_LEFT.get_y() + WINDOW_HEIGHT );
//!< The lower right corner of the drawing area

const double LETTER_WIDTH = ( WINDOW_WIDTH / 53.0 );
//!< The width of a letter in the drawing area

const double LETTER_HEIGHT = ( WINDOW_HEIGHT / 44.0 );
//!< The height of a letter in the drawing area

const int LINES_PER_PAGE = 30;	
//!< The number of line per page when formatting text

const int CHARS_PER_LINE = 48;
//!< The number of characters per line when formatting text

const double LINE_HEIGHT = ( 80.0 / LINES_PER_PAGE );  
//!< The height of a line when formatting text

#endif // __GLOBAL_CONST_H__
