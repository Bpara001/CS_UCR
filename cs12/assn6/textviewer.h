
//!CHRISTOPHER WONG AND CHRISTOPHER DOHI ARE WORKING TOGETHER ON THIS ASSN.
///////////////////////////////////////
// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// First Name(partner): Christopher
// Last Name(partner): Dohi
// Login id(partner): dohic
// email address(partner): cdohi001@student.ucr.edu
// Student id: 860 932 007
// Lecture Section: 002
// Lab Section: 024
// TA: Nkenge
//
// Assignment: assn6
//
// WE hereby certify that the code in this file
// is ENTIRELY our own original work.
//! BOTH STUDENTS COLLBORATED TOGETHER FOR EACH FUNCTION AND IMPLEMENTATION
//! WE BOTH SAT INFRONT OF ONE COMPUTER CODING EACH LINE BY LINE TOGETHER
//========================================================================
//The interface of the textviewer class
#ifndef _TEXTVIEWER_H_
#define _TEXTVIEWER_H_
#include "instinct.h"
#include "button.h"
#include "scrollbar.h"
#include <string>
#include <vector>

const unsigned int LINE_LENGTH = 48;
const unsigned int PAGE_LENGTH = 30;
const Point STARTING_LINE(5,97);
const Point PREV_POSITION(5,5);
const Point NEXT_POSITION(15,5);
const Point DONE_POSITION(30,5);
const double SCROLLBAR_HEIGHT = 100;
const double SCROLLBAR_WIDTH = 5.4;
const Point SCROLLBAR_POSITION(100 - SCROLLBAR_WIDTH,0);

class TextViewer
{
public:
    //! \brief Default constructor for the TextViewer Class.
    TextViewer();

    //! \brief Constructor for the TextViewer Class.
    //! \param filename The name of the file to view.
    TextViewer( const std::string & filename );

    //! \brief Set the name of the file to view.
    //! \param filename The name of the file to view.
    //! \return Void.
    void setFile( const std::string & filename );

    //! \brief View the contents of the file.
    //! \return Void.
    void view();


    private:
    //! \brief Read in the contents of the file.
    //! \return Void.
    void readTextFromFile();

    //! \brief Display a page in the window
    //! \return Void.
    void outputPage();

    //! \brief Display the next page in the window.
    //! \return Void.
    void showNextPage();

    //! \brief Display the previous page in the window. If doing so would
    //         set the top of the page to be less than 0, set the top of the
    //         page index to 0.
    //! \return Void.
    void showPrevPage();

    //! \brief Scroll up one line in the window
    //! \return Void
    void scrollUp();

    //! \brief Scroll down one line in the window
    //! \return Void
    void scrollDown();

    //! \brief Check to see if there is room to scroll up one line
    //! \return Whether the current top of the page is the beginning of the
    //          text
    bool canScrollUp();

    //! \brief Check to see if there is room to scroll down one line
    //! \return Whether the current top of the page is the end of the text
    bool canScrollDown();

    //! \brief Check to see if there is room to go to the next page
    bool canPageNext();

    //! \brief Check to see if there is room to go to the pervious page
    bool canPagePrev();


    //private member variables

    bool viewer_fail_status;         //!< Whether the viewer has failed to open
                                     //   the file or not.
    std::string filename;	     //!< The name of the file.
    std::vector<std::string> text;   //!< The text from the file

    Button next;		     //!< A button for getting the next page.
    Button prev;                     //!< A button for getting the previous
                                     //   page.
    Button done;	             //!< A button to stop viewing the text.
    Scrollbar scrollbar;             //!< A scrollbar to move up/down one line
                                     //   at a time
    unsigned int line_num;  //!Where the line is on the top of the page

};
#endif
