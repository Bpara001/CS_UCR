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
// Assignment: Lab 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "instinct.h"

// Check to see whether the Point, click, was inside the bounds of the
// Rectangle, box.
bool inside( const Point& click, const Rect& box )
{
   double xbox = box.get_lower_left().get_x();
   double ybox = box.get_lower_left().get_y();
   double w = box.get_width();
   double h = box.get_height();
   double xclick = click.get_x();
   double yclick = click.get_y();

   if(xclick > xbox &&
      xclick < xbox + w &&
      yclick > ybox &&
      yclick < ybox + h)
   {
      return true;
   }
   else return false;

}

int instinct_main()
{
    win.coord(0, 0, 80, 80);
    win.set_title("CS12 - Lab 1: Box");

    // Create the Rectangle
    Rect rectangle = Rect(Point(30,30),30,20);
    win << rectangle;
    win.output_buffer();

    // Allow the user to click five times before the program ends.
    for( int i = 5; i > 0; i-- )
    {

       Point click = win.get_mouse("click somewhere");
       win.clear_buffer();

       bool q = inside(click,rectangle);

       if(q == true)
       {
       win << Circle(click,2) << rectangle <<
             Message(Point(10,10),"Inside",RED);
      }
       else
       {
           win << Circle(click,2) << rectangle <<
             Message(Point(10,10),"Outside",RED);
       }
       win.output_buffer();



        
    }

    return 0;
}
