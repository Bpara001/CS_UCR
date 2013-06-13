

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
//=============================================================================
//Your implementation of the textviewer class
#include "textviewer.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//! \brief Default constructor for the TextViewer Class.
TextViewer::TextViewer()
:viewer_fail_status(true),filename(""),line_num(0)

{
    text[0];
    next = Button();
    prev = Button();
    done = Button();
    scrollbar = Scrollbar();
}

//! \brief Constructor for the TextViewer Class.
//! \param filename The name of the file to view.
TextViewer::TextViewer( const std::string & filename )
:filename(filename),line_num(0)
{
    next = Button(NEXT_POSITION, "next");
    prev = Button(PREV_POSITION, "prev");
    done = Button(DONE_POSITION, "done");
    scrollbar = Scrollbar(SCROLLBAR_POSITION, SCROLLBAR_HEIGHT,
    SCROLLBAR_WIDTH);
}

//! \brief Set the name of the file to view.
//! \param filename The name of the file to view.
//! \return Void.
void TextViewer::setFile( const std::string & filename )
{
    text.clear();
    this->filename = filename;
    line_num = 0;
}

//! \brief View the contents of the file.
//! \return Void.
void TextViewer::view()
{
    readTextFromFile();
    Point click;
    line_num = 0;

    while(true)
    {

        if(!viewer_fail_status)
        {
        win.clear_buffer();
        }

        if(next.is_clicked(click) && canPageNext())
        {
            showNextPage();
        }
        if(prev.is_clicked(click) && canPagePrev())
        {
            showPrevPage();
        }
        if(done.is_clicked(click))
        {
            return;
            text.clear();
        }
        if (scrollbar.get_first().is_clicked(click) && !canScrollUp())
        {
                scrollUp();
        }
        if (scrollbar.get_second().is_clicked(click) && !canScrollDown())
        {
            scrollDown();
        }

        if(canPageNext() && !viewer_fail_status)
        {
            next.draw();
        }

        if(canPagePrev() && !viewer_fail_status)
        {
            prev.draw();
        }

        if(!viewer_fail_status)
        {
        outputPage();
        done.draw();
        scrollbar.draw();
        win.output_buffer();
        click = win.get_mouse("");
        }
    }
}

//private
//! \brief Read in the contents of the file.
//! \return Void.
void TextViewer::readTextFromFile()
{

  ifstream infile(filename.c_str());
  string str = "";
  string str_temp = "";
  if (!infile)
    {

    win <<Message(Point(5,50),
        "Error: " + filename + " could not be opened.");
    win.output_buffer();
    viewer_fail_status=true;
    }


    while(infile)
    {
        getline(infile,str);
        while(str.length()>= LINE_LENGTH)
        {
            str_temp = str.substr(0,str.rfind(" ",LINE_LENGTH));
            if(str_temp .substr(0,1) == " ")
            {
                str_temp = str_temp .substr(1,str.length());
            }
            text.push_back(str_temp );
            str =  str.substr(str.rfind(" ",LINE_LENGTH));
        }

        if(str.length()<LINE_LENGTH)
        {
            if(str.substr(0,1) == " ")
            {
                str = str.substr(1,str.length());
            }
            text.push_back(str);
        }

        line_num++;
    }

    infile.close();
}

//! \brief Display a page in the window
//! \return Void.
void TextViewer::outputPage()
{
    for(int unsigned i = line_num; i < (PAGE_LENGTH + line_num )
    && i < text.size(); i++)
    {
        int k = i - line_num;
        double xpoint = STARTING_LINE.get_x();
        double ypoint = STARTING_LINE.get_y() - ((LETTER_HEIGHT*1.5) * k);

        win << Message(Point(xpoint,ypoint),text[i]);
    }

}

//! \brief Display the next page in the window.
//! \return Void.
void TextViewer::showNextPage()
{
    line_num += PAGE_LENGTH;
    outputPage();

}

//! \brief Display the previous page in the window.
//! \return Void.
void TextViewer::showPrevPage()
{
    line_num -= PAGE_LENGTH;
    outputPage();

}

//! \brief Scroll up one line in the window
//! \return Void
void TextViewer::scrollUp()
{
    line_num--;
    outputPage();
}

//! \brief Scroll down one line in the window
//! \return Void
void TextViewer::scrollDown()
{
    line_num++;
    outputPage();
}

//! \brief Check to see if there is room to scroll up one line
//! \return Whether the current top of the page is the beginning of the
//          text
bool TextViewer::canScrollUp()
{
    return line_num == 0;
}

//! \brief Check to see if there is room to scroll down one line
//! \return Whether the current top of the page is the end of the text
bool TextViewer::canScrollDown()
{
    return line_num == (unsigned int)text.size() -1;
}

//! \brief Check to see if there is room to go to the next page
bool TextViewer::canPageNext()
{
    return line_num < (unsigned int)text.size() - 30;
}

//! \brief Check to see if there is room to go to the pervious page
bool TextViewer::canPagePrev()
{
    return line_num >= 30;
}
