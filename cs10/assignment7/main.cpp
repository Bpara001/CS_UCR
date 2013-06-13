// Course: CS 10 quarter 1 , 2009
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
// Assignment: Assignment 7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include "instinct.h"
using namespace std;

///////////////////////////PADDLE MOVE FUCTION////////////////////////////
void paddle_move(Rect &pad, double movement, double left_wall,
double right_wall,string w, string z)
{
//Leftside
if (win.is_key_down(w))
  {          
    pad.move(-movement,0) ;
    if( pad.get_lower_left().get_x() <= left_wall)
      {
      double leftside = left_wall- pad.get_lower_left().get_x();
      pad.move(leftside,0);
      }	  
  }
//Rightside
if (win.is_key_down(z))
  {	
  pad.move(movement,0) ;
      if( pad.get_lower_left().get_x()+pad.get_width() >= right_wall)
      {
      double rightside=pad.get_lower_left().get_x()+pad.get_width()-right_wall;
      pad.move(-rightside,0);
      }		
  }			
}

/////////////////////////PADDLE COLLISION FUCTION///////////////////////
void paddle_col(Rect paddle,Circle& c,double &xmove, double &ymove)
{
    double h = paddle.get_height();
    double w = paddle.get_width();

//Bounces off of top of the paddle
        if(c.get_center().get_x() -1 >= paddle.get_lower_left().get_x() &&
           c.get_center().get_x() +1 <= paddle.get_lower_left().get_x() + w &&
           c.get_center().get_y() -1 <= paddle.get_lower_left().get_y() + h)
        {
          ymove *= -1;
        }
//Bounces off the left side of the paddle
        if(c.get_center().get_x() +1 >= paddle.get_lower_left().get_x()
           && c.get_center().get_y() -1 >= paddle.get_lower_left().get_y()
           && c.get_center().get_y() +1 <= paddle.get_lower_left().get_y() + h)
       {
         xmove *= -1;
         ymove *= -1;
       }
//Bounces off the right side of the paddle
        if(c.get_center().get_x() -1 >= paddle.get_lower_left().get_x() + w
           && c.get_center().get_y() -1 >= paddle.get_lower_left().get_y()
           && c.get_center().get_y() +1 <= paddle.get_lower_left().get_y() + h)
       {
         xmove *= -1;
         ymove *= -1;
       }
}

///////////////////////////WALL COLLISION FUCTION////////////////////////
void wall_col(Circle &c,double topwall, double leftwall, double rightwall,
double &xmove, double &ymove)
{
//Gets xpoint of circle.
      Point moving1 = c.get_center();
      double xpoint = moving1.get_x();

//Makes the ball bounce top, right, and left walls.
      if(c.get_center().get_y() > topwall)
        {
          ymove *= -1;
        }
      if(xpoint > rightwall)
        {
          xmove *= -1;
        }
      if(xpoint < leftwall)
        {
          xmove *= -1;
        }
        c.move(xmove,ymove);
}

/////////////////////////BOTTOM WALL THROUGH FUCTION//////////////////////
void bottom_fall(Circle& c, double bottomwall, double &xmove,
double& ymove, double initialx, double initialy, Point starting, int& bcount,
Message& output)
{
//If ball falls through, respanws ball, decreases ball count for player
     if(c.get_center().get_y() < bottomwall)
     {
     c.set_center(starting);
     xmove = .25;
     ymove = -.5;
     bcount = bcount -1;
     win << output;
     }
}

//////////////////////////////////////////////////////////////////////////
/////////                      MAIN FUCTION                     //////////
//////////////////////////////////////////////////////////////////////////
int instinct_main()
{
//Sets timer and animation
  const int FRAME_PERIOD = 20;
  Timer tmr;
  tmr.start();

//Sets variables & constants
  double xmove_p2 = .25;
  double ymove_p2 = -.5;
  double xmove_p1 = .4;
  double ymove_p1 = -.8;
  win.coord(0,0,100,100);
  Circle c = Circle(Point(25,50),1,RED,true);
  Circle c2 = Circle(Point(75,50),1,RED,true);
  Rect paddle_p1 = Rect(Point(25,3),6,3,BLACK,true);
  Rect paddle_p2 = Rect(Point(75,3),10,3,BLACK,true);
  int balls_left_p1 = 6;
  int balls_left_p2 = 6;
  double pad_move = .5;

//Loop only true until esc is pressed
    while (! win.is_key_down("esc"))
    {
//Declares variables
      Line mid_wall = Line(Point(50,0),Point(50,100));  
      Message balls_num_p1 = Message(Point(14,97),balls_left_p1);
      Message balls_num_p2 = Message(Point(94,97),balls_left_p2);

//Calls padde move fuction
      paddle_move(paddle_p1,pad_move,0,50,"a","d");
      paddle_move(paddle_p2,pad_move,50,100,"left","right");

//Outputs circle, paddle, ball counts, and mid-line
      win << c << c2 << Message(Point(80,97),"Balls - " )
          << Message(Point(1,97),"Balls - " )
          << paddle_p1 << paddle_p2 << balls_num_p1 << mid_wall
          << balls_num_p2;
      win.output_buffer();
      wait_for (FRAME_PERIOD - tmr.get_time() );
      tmr.reset();
      win.clear_buffer();

//Calls fall through
      bottom_fall(c, 0, xmove_p1, ymove_p1, 1, 1, Point(25,50), balls_left_p1,
      balls_num_p1);
      bottom_fall(c2, 0, xmove_p2, ymove_p2, 1, 1, Point(75,50), balls_left_p2,
      balls_num_p2);

//Calls wall collision
      wall_col(c2, 99, 51, 99, xmove_p2, ymove_p2);
      wall_col(c, 99, 1, 49, xmove_p1, ymove_p1);

//Calls paddle collision
      paddle_col(paddle_p2, c2, xmove_p2, ymove_p2);
      paddle_col(paddle_p1, c, xmove_p1, ymove_p1);

//Outputs "Game Over" for loser, and the of the game.
    if (balls_left_p1 == 0)
        {
        win << Message(Point(75 - LETTER_WIDTH * 5,50),"Player 2 wins")
            << Message(Point(25 - LETTER_WIDTH * 5,50),"Game Over.")
            << mid_wall;
        win.output_buffer();
        return 0;
        }
    if (balls_left_p2 == 0)
        {
        win << Message(Point(25 - LETTER_WIDTH * 5,50),"Player 1 wins")
            << Message(Point(75 - LETTER_WIDTH * 5,50),"Game Over.")
            << mid_wall;
        win.output_buffer();
        return 0;
         }
    }
    return 0;
}
