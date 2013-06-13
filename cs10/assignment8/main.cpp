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
// Assignment: Assignment 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include <iostream>
#include "instinct.h"
#include <vector>
#include <iomanip>
using namespace std;

///////////////////////////PADDLE MOVE FUCTION////////////////////////////
void paddle_move(Rect &pad, double movement, double left_wall,
double right_wall, string w, string z)
{
//Moves to the Left, also makes sure doesnt move out of left side
    if (win.is_key_down(w))
    {
    pad.move(-movement,0) ;
    if( pad.get_lower_left().get_x() <= left_wall)
        {
        double leftside = left_wall- pad.get_lower_left().get_x();
        pad.move(leftside,0);
        }
    }
//Moves to the Right, also makes sure doesnt move out of the right side
if (win.is_key_down(z))
    {
    pad.move(movement,0);
    if( pad.get_lower_left().get_x()+pad.get_width() >= right_wall)
        {
        double rightside=pad.get_lower_left().get_x()+pad.get_width()-right_wall;
        pad.move(-rightside,0);
        }
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
         xmove = .75;
         ymove = -1.25;
         bcount = bcount -1;
         win << output;
     }
}

//////////////////////////INITIALIZE BRICK FUCTION////////////////////////
void initialize_b(vector<Rect> & brick,Point starting, int rows, int columns,
double width, double height, double h_gap, double v_gap, Color color)
{

  for (int i = 0; i < rows; ++i)
    {
      Rect rect (starting,width,height,color,true);
      rect.move (0,i*(v_gap + height));

      for (int i = 0; i < columns; ++i)
        {
          brick.push_back(rect);
          rect.move(h_gap + width,0);
        }
    }

}

////////////////////////////DRAW BRICK FUNCTION///////////////////////////
void draw_bricks (const vector<Rect> & brick)
{
    for (int i =0; i <brick.size(); ++i )
    {
      win << brick[i];
    }
}

/////////////////////////RECTANGLE COLLISION FUCTION//////////////////////
bool rect_col(Rect rect, Circle &c, double &xmove, double &ymove)

{
    double h = rect.get_height();
    double w = rect.get_width();
    double r = c.get_radius();
    Point center = c.get_center();
    Point ll = rect.get_lower_left();

//Checks the bottom
    if(center.get_y() + r < ll.get_y()
    && center.get_y() + r > ll.get_y() -.4)
    {
        if(center.get_x() > ll.get_x()
        && center.get_x() < ll.get_x() +w)
        {
            ymove *= -1;
            return true;
        }
    }
//Checks the Top
    if(center.get_y() -r > ll.get_y() + h
    && center.get_y() -r < ll.get_y() +.4 + h)
    {
        if(center.get_x() > ll.get_x()
           && center.get_x() < ll.get_x() +w)
        {
            ymove *= -1;
            return true;
        }
    }
//Checks the Left side
    if(center.get_x() >= ll.get_x() -r - 1
    && center.get_x() <= ll.get_x()
    && center.get_y() >= ll.get_y()
    && center.get_y() <= ll.get_y() +h -r
    && ymove < 0 && xmove > 0)
    {
        xmove *=-1;
        ymove *=-1;
        return true;
    }
//Checks the Right side
    if(center.get_x() <= ll.get_x() +w +r +1
    && center.get_x() >= ll.get_x()+w
    && center.get_y() >= ll.get_y()
    && center.get_y() <= ll.get_y() + h + r
    && ymove <0 && xmove <0)
   {
        xmove *=-1;
        ymove *=-1;
        return true;
   }
    return false;
}

///////////////////////////CHECK BRICKS COLLOISION////////////////////////
void brick_col (vector<Rect> & brick, Circle & c, double & xmove, double & ymove)
{

  for (int i = 0; i < brick.size(); ++i)
    {
        if (rect_col(brick[i],c,xmove,ymove) == true)
        {
            brick.erase(brick.begin()+i);
        }
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

//Sets variables and such
    double xmove_p1 = .55;
    double ymove_p1 = -.8;
    win.coord(0,0,100,100);
    Circle c = Circle(Point(50,50),1,RED,true);
    Rect paddle_p1 = Rect(Point(50,3),10,2,BLACK,true);
    int balls_left_p1 = 6;
    double pad_move = 2;
    Message endgame1 = Message(Point(50 - LETTER_WIDTH * 5,50),"Game Over.");
    vector <Rect> brick;
    Point start(2,80);
    int columns = 8;
    int rows = 6;
    double h_gap = 2;
    double v_gap = 2;
    double width = 10;
    double height = 3;

//Calls initialize_bricks fuction, does not output bricks!
    initialize_b(brick, start, rows, columns, width, height,h_gap, v_gap,
    BLUE);

//Loop only true until esc is pressed
    while (! win.is_key_down("esc"))
    {
//Declares variables
      Message balls_num_p1 = Message(Point(94,0),balls_left_p1);

//Outputs circle, paddle, ball counts, and mid-line
      win << c << Message(Point(80,0),"Balls - " )
          << paddle_p1 << balls_num_p1;
      draw_bricks(brick);
      win.output_buffer();
      wait_for (FRAME_PERIOD - tmr.get_time() );
      tmr.reset();
      win.clear_buffer();

//Calls padde move fuction
      paddle_move(paddle_p1,pad_move,0,100,"left","right");

//Calls fall through
      bottom_fall(c, 0, xmove_p1, ymove_p1, 1, 1, Point(50,50), balls_left_p1,
      balls_num_p1);

//Calls wall collision
      wall_col(c, 99, 1, 99, xmove_p1, ymove_p1);

//Calls paddle & brick collision
      brick_col(brick,c,xmove_p1,ymove_p1);
      rect_col(paddle_p1,c,xmove_p1,ymove_p1);
 
//Outputs winner, messages, also ends the game and asks user to play again
    if (balls_left_p1 == 0)
    {
        win.clear_buffer();
        string redo = win.get_string(
       "\n\n\nYou LOSE. Computer WINS. \n\nPress 1 to play again,"
       " or press any other key to quit!");
        if (redo == "1")
        {
            instinct_main();
        }
        else
        {
            win.clear_buffer();
            win << endgame1;
            win.output_buffer();
            return 0;
         }
    }
    if(brick.size() == 0)
    {
        win.clear_buffer();
        string redo = win.get_string(
       "\n\n\nYou WIN! Compuer LOSES!\n\nPress 1 to play again,"
       " or press any other key to quit!");
        if (redo == "1")
        {
            instinct_main();
        }
        else
        {
            win.clear_buffer();
            win << endgame1;
            win.output_buffer();
            return 0;
         }
    }
  }
    return 0;
}
