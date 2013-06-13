// Course: CS 10 quarter 1 , 2009
//
// First Name: Chris
// Last Name: Wong
// Login id: 860-923-521
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 02
// Lab Section: 026
// TA: Muzaffer Akbay
//
// Assignment: Assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{
    //Sets timer, declares variables, sets initial speed.
    const int FRAME_PERIOD = 20;
    Timer tmr;
    tmr.start();
    double xmove;
    double ymove;
    win.coord(0,0,100,100);
    Circle circle_center = Circle(Point(50,50),2,BLACK,true);
    xmove = .25;
    ymove = .5;
      
    //loop only true until esc is pressed
       while (! win.is_key_down("esc"))
    { 
        //makes the ball move in animated fashion
        Point moving1 = circle_center.get_center();
        double xpoint = moving1.get_x();
        double ypoint = moving1.get_y();  
        win << circle_center;
        win.output_buffer();
        wait_for (FRAME_PERIOD - tmr.get_time() );
        tmr.reset();
        win.clear_buffer();
      
        //makes the ball 'bounce off walls
        if( ypoint > 98)
        { ymove *= -1;}
        if(ypoint < 2)
        {ymove *= -1;}
        if(xpoint > 98)
        {xmove *= -1;}
        if(xpoint < 2)
        {xmove *= -1;}
        circle_center.move(xmove,ymove);

        //key inputs to make the ball faster/slower
        if(win.is_key_down("s"))
        {ymove *= .99;
        xmove *= .99;
        circle_center.set_color(BLUE);}
        if(win.is_key_down("f"))
        {ymove *= 1.01;
        xmove *= 1.01;
        circle_center.set_color(RED);}
    }
    return 0;
}
