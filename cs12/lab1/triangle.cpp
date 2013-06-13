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

void draw_triangle( const Point &loc, const double size )
{
    // Define our own unit of size which is relative to the size that is 
    // specified for the triangle.  The choice to divide by 8 is arbitrary
    // and means that we are drawing on an 8 x 8 unit grid
    double unit = ( size / 8.0 );
    double xpoint = loc.get_x();
    double ypoint = loc.get_y();

    // draw the triangle in terms of units on an 8 x 8 unit grid
    win << Triangle(Point((xpoint-unit),(ypoint - unit)),
                    Point((xpoint + unit),(ypoint - unit)),
                    Point((xpoint),(ypoint + unit)));
    

    // output the buffer
    win.output_buffer();
    
}

int instinct_main()
{
    win.coord(0, 0, 8, 8);
    win.set_title("CS12 - Lab 1: Triangle");

    // loop starting at 4 and going to 20 in increments of 4 drawing a
    // triangle and then waiting for a mouse click from the user.
    for( int i = 4; i <=20; i+=4 )
    {
        // call the function to draw the triangle at the center of the 
        // drawing window
       draw_triangle(Point(4,4),i);
    
        
        // get a mouse click from the user
       win.get_mouse("click!!!");

        // clear the buffer
        win.clear_buffer();
    }

    return 0;
}
