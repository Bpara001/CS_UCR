// Course: CS 10 <fall quarter, 2009>
//
// First Name: Chris
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 02
// Lab Section: 026
// TA: Muzaffer Akbay
//
// Assignment: lab7_ex1a
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include "instinct.h"

int instinct_main()
{
  // width, height, and center of button
  const double WIDTH = 2.0;
  const double HEIGHT = 1.0;
  const Point CENTER = Point( 5, 5 );
  double mousex;
  double mousey;

  // create BLUE rectangle with BLACK border in center of window.
  Point quit_pt = CENTER;
  quit_pt.move( -WIDTH / 2, -HEIGHT / 2 );
  Rect quit_button = Rect( quit_pt, WIDTH, HEIGHT, BLUE, true );
  Rect quit_border = Rect( quit_pt, WIDTH, HEIGHT );

  // create WHITE label for rectangle.
  Point quit_message_pt = CENTER;
  quit_message_pt.move( -2 * LETTER_WIDTH, -0.5 * LETTER_HEIGHT );
  Message quit_message = Message( quit_message_pt, "QUIT", WHITE );

  // output QUIT button
  win << quit_button << quit_message << quit_border;
  win.output_buffer();

  // Output circles wherever the user clicks until user clicks inside
  // the QUIT button.
  while (mousex < 4 or  mousex > 6 or mousey < 4.5 or mousey > 5.5)
  {Point mouse_click = win.get_mouse("Click somewhere. Click the quit button to exit");
    mousex = mouse_click.get_x();
    mousey = mouse_click.get_y();

        if(mousex < 4 or  mousex > 6 or mousey < 4.5 or mousey > 5.5)
        {win << Circle(Point(mouse_click),1);
        win.output_buffer();}

   // Clear window and output GOODBYE! message in exact center of the window.
        else
        {win.clear_buffer();
        win << Message(Point(CENTER),"GOODBYE!");
        win.output_buffer();}
   }



  return 0;
}
