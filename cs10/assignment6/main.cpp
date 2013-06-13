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
// Assignment: Assignment 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include "instinct.h"
using namespace std;

//move function
Rect paddle1 (Rect pad, double movement, double left_wall, double right_wall,
string w, string z)
{
//leftside
if (win.is_key_down(w))
  {          
    pad.move(-movement,0) ;
    if( pad.get_lower_left().get_x() <= left_wall)
      {
      double leftside = left_wall- pad.get_lower_left().get_x();
      pad.move(leftside,0);
      }	  
  }
//rightside
if (win.is_key_down(z))
  {	
  pad.move(movement,0) ;
      if( pad.get_lower_left().get_x()+pad.get_width() >= right_wall)
      {
      double rightside = pad.get_lower_left().get_x()+pad.get_width()-right_wall;
      pad.move(-rightside,0);
      }		
  }
  return pad;			
}
//main function
int instinct_main()
{
//sets timer, declares variables, sets initial speed.
const int FRAME_PERIOD = 20;
Timer tmr;
tmr.start();
double xmove = .25;
double ymove = -.5;
win.coord(0,0,100,100);
Circle c = Circle(Point(50,50),1,RED,true);
Rect paddle = Rect(Point(41,3),15,3,BLACK,true);
int balls_left = 6;
double pad_move = 1;


//loop only true until esc is pressed & they have lives remaining
    while (! win.is_key_down("esc") && balls_left >= 1)
    {
//makes the ball move in animated fashion & outputs everything
    Point moving1 = c.get_center();
    double xpoint = moving1.get_x();
    double ypoint = moving1.get_y();
    paddle = paddle1(paddle,pad_move,0,100,"left","right");   
    win << c << Message(Point(80,97),"Balls - " )
    << Message(Point(1,97),"Press the ESC key to exit")
    << Message(Point(94,97), balls_left)<< paddle; 	       
    win.output_buffer();
    wait_for (FRAME_PERIOD - tmr.get_time() );
    tmr.reset();
    win.clear_buffer();
//Decreases ball count by 1 everytime it hits bottom, also resets ball
    if(ypoint < 0)
        {
        c.set_center(Point(50,50));
        xmove = .25;
        ymove = -.5;
        balls_left = balls_left -1;
        }       
//makes the ball bounce off walls, but falls through the bottom wall
   if( ypoint > 99)
        { ymove *= -1;}
        if(xpoint > 99)
        {xmove *= -1;}
        if(xpoint < 1)
        {xmove *= -1;}
        c.move(xmove,ymove);   
//Bounces off of top of the paddle
    if(c.get_center().get_x() -1 >= paddle.get_lower_left().get_x() &&
    c.get_center().get_x() +1 <= paddle.get_lower_left().get_x() + 15 &&
    c.get_center().get_y() -1 <= paddle.get_lower_left().get_y() + 3)
        {ymove *= -1;}
//Bounces off the left side of the paddle
    if(c.get_center().get_x() +1 >= paddle.get_lower_left().get_x()
    && c.get_center().get_y() -1 >= paddle.get_lower_left().get_y()
    && c.get_center().get_y() +1 <= paddle.get_lower_left().get_y() + 3)
       {xmove *= -1;
       ymove *= -1;}
//Bounces off the right side of the paddle
    if(c.get_center().get_x() -1 >= paddle.get_lower_left().get_x() + 15
    && c.get_center().get_y() -1 >= paddle.get_lower_left().get_y()
    && c.get_center().get_y() +1 <= paddle.get_lower_left().get_y() + 3)
       {xmove *= -1;
       ymove *= -1;}
}
//Outputs "Game Over".
win << Message(Point(50 - LETTER_WIDTH * 5,50),"Game Over.");
win.output_buffer();

return 0;
}
