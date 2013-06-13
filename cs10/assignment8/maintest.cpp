 
// Course: CS 10 <fall 09>
//

//
// Lecture Section: <002>
// Lab Section: <026>
// TA: Muzaffer Akbay
//
// Assignment <Programming Assignment 8>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.

#include "instinct.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>


/////////////////////////////RANDOM/////////////////////////////////


int random(int lower,int higher)
{
  int rand_num;
  rand_num = rand()%((higher-lower+1)+lower);
  return rand_num;
}

///////////////////////////////////////////////////////////////////////////////
// This function is what moves the paddle in a certain direction             //
// The function asks for the Rectangle of the paddle, and the amount you     /
// want the paddle moved. The left sides x coordinate and the right sides    /
// x coordinate. Asks for the specific keys that you want to use to have     //
// the paddle move left or right                                             //
///////////////////////////////////////////////////////////////////////////////

void move(Rect& paddle, double movement, double left_side,
          double right_side,string key1, string key2)
{

  if(win.is_key_down(key1) &&
     (paddle.get_lower_left().get_x() >=
      left_side))
    {
      paddle.move(-movement, 0);

      if(paddle.get_lower_left().get_x() <=
         left_side)
        {
          double side1 = (left_side- paddle.get_lower_left().get_x()) ;
          paddle.move(side1,0);
        }

    }

  if(win.is_key_down(key2)
     && (paddle.get_lower_left().get_x()+paddle.get_width() <=
         right_side))
    {
      paddle.move(movement, 0);

      if((paddle.get_lower_left().get_x()+paddle.get_width()) >=
         right_side)
        {
          double side2 = ((paddle.get_lower_left().get_x()+
                           paddle.get_width())-right_side) ;
          paddle.move(-side2,0);
        }


    }
}


///////////////////////////////////////////////////////////////////////////////
//  Checks the wall collision of the top, left side and right side of the    //
//  player(s) window.If the ball hits either of the sides it will bounce off//
//////////////////////////////////////////////////////////////////////////////
void wall_collision (Circle& ball, double top_y, double left_x ,
                     double right_x, double& x_move, double& y_move)
{
  // when ball hits wall bounces on it
  Point currentstate = ball.get_center();
  double radius = ball.get_radius();
  double left_wall = left_x+radius;
  double right_wall =  right_x - radius;
  double top_wall = top_y-radius;

  // barrier, ball won't go past the edge of the coordinates.
  if (currentstate.get_x() < left_wall)
    {

      x_move *= -1;

    }

  if (currentstate.get_x() > right_wall)
    {

      x_move *= -1;
    }

  if (currentstate.get_y() > top_wall)
    {

      y_move *= -1;

    }
}

///////////////////////////////////////////////////////////////////////////////
//  When the ball goes of the screen, the ball will reset in the middle of   //
//  the screen and the ball count of the player will go down by one          //
///////////////////////////////////////////////////////////////////////////////

void bottom_wall_fall (Circle& ball, double bottom_y, double& x_move,
                       double& y_move, double initial_x, double initial_y,
                       Point start, int& ball_count, Message& ballcount)

{
  Point currentstate = ball.get_center();
  double radius = ball.get_radius();
  double bottom_wall = bottom_y-radius;

  // Point start = where ball will be reoutputted into center of screen

  if (currentstate.get_y() < bottom_wall )
    {

      if(x_move < 0)
        {
              x_move*=-1;
        }

      ball_count -= 1;
      ball.set_center(start);
      ballcount.set_text(ball_count);
    }

  win << ballcount;
}

///////////////////////////////////////////////////////////////////////////////
//                           CREATE BRICKS FUNCTION                          //
//  This function creates bricks using the vector brick  and the starting    //
//  point that the bricks will start, the height, lenth, of the desired brick//
// and the the horizontal and vertical gap between bricks.                   //
//              WARNING :THIS FUNCTION DOES NOT OUTPUT THE BRICKS            //
///////////////////////////////////////////////////////////////////////////////

void create_bricks(vector<Rect> &  brick , Point start,int rows, int column,
                    double width, double height, double hor_gap,
                   double vert_gap)

{

  for (int i = 0; i < rows; ++i)

    {
      Color color = (Color)random(0,14);
      while(color == DARK_BLUE | color==PINK |color == RED)
        {
          color=(Color)random(0,14);
        }

      Rect rect (start,width,height,color,true);
      rect.move (0,i*(vert_gap+height));

      for (int i = 0; i < column; ++i)
        {

          brick.push_back(rect);
          rect.move(hor_gap+width,0);

        }

    }

}

///////////////////////////////////////////////////////////////////////////////
//                           DRAW BRICKS FUNCTION                            //
//  This function draws the bricks that  works with the brick vector and the //
//  create bricks function to display them to teh screen                     //
///////////////////////////////////////////////////////////////////////////////

void draw_bricks (vector<Rect> & brick)
{
  for (int i =0; i <brick.size(); ++i )
    {
      win << brick[i];
    }
}


///////////////////////////////////////////////////////////////////////////////
//               BRICKS AND PADDLE COLLSION DETECTION FUNCTION               //
// This function is what checks to see if the paddle.rect gets hit on either //
//the top, left side and the right side. For the  top it will bounce         //
// differently depending on where it gets hit. From the cenetr of the        //
// paddle to the left   if hit should bounce up towards the left side.If its //
// hit from the middle to the right of paddle the ball  will bounce of       //
// towards the right.If the ball hits either the left or  right side  the    //
// the ball will change the velocity x and y velocity. This function         //
// will return true if a collsion happened and will use that bool to tell    //
// the the vector brick that the ball was hit and will be removed from the   //
// vector                                                                    //
///////////////////////////////////////////////////////////////////////////////

bool rect_collision (Rect rect , Circle& ball , double& x_move,
                       double& y_move)
{
  double radius = ball.get_radius();
  double h_ = rect.get_height();
  double w_ = rect.get_width();
  double y_ =  rect.get_lower_left().get_y();



///// Checks bottome colision

 if(	ball.get_center().get_y() + radius > y_
        & ball.get_center().get_y() + radius < y_  + radius * 2
        & ball.get_center().get_x() + radius >= rect.get_lower_left().get_x() - 1
        & ball.get_center().get_x() + radius <= rect.get_lower_left().get_x() + w_ + 2)

   {
     y_move*=-1;

     if(ball.get_center().get_y()>=rect.get_lower_left().get_y())
        {
          double moove = (ball.get_center().get_y()-
                          rect.get_lower_left().get_y());

            ball.move( 0,moove*2);
            y_move *=-1;

        }

       return true;
   }



 /////// checks to see if the ball hits the top of the bar and depending
 /////// on where it hits the top it will bounce differently
 if (

ball.get_center().get_y() + radius >= y_ + h_ &

ball.get_center().get_y() + radius < y_ + h_ + radius * 2 &

ball.get_center().get_x() + radius >=  rect.get_lower_left().get_x() - 1 &

ball.get_center().get_x() + radius <= rect.get_lower_left().get_x() + w_ )
   {
      y_move*=-1;
      return true;

   }

 ///////////////
 /// when ball hits left or right side ball will bounce off
 ///////////////

 ////////// checks the left side

 if( ball.get_center().get_x() >= rect.get_lower_left().get_x()-radius-1
     && ball.get_center().get_x() <= rect.get_lower_left().get_x()
     && ball.get_center().get_y() >= rect.get_lower_left().get_y()
     && ball.get_center().get_y() <= rect.get_lower_left().get_y()+h_-radius
     && y_move < 0 && x_move > 0)
   {
     x_move *=-1;
     y_move*=-1;
     return true;
   }

 ///////// checks the right side
 if( ball.get_center().get_x() <= rect.get_lower_left().get_x()+w_+radius+1
     && ball.get_center().get_x() >= rect.get_lower_left().get_x()+w_
     &&  ball.get_center().get_y() >= rect.get_lower_left().get_y()
     && ball.get_center().get_y() <= rect.get_lower_left().get_y()+h_+radius
     && y_move <0 && x_move <0)
   {
     x_move *=-1;
     y_move*=-1;
     return true;
   }


 return false;
}

///////////////////////////////////////////////////////////////////////////////
//                           BRICK COLLISION  FUNCTION                       //
//  This function works with the "RECT COLLISION FUNCTION", it uses the bool //
//  given from the the "RECT COLLISION FUNCTION" and if true then this       //
//  function will erase the brick that was hit from the vector BYE BYE BRICK //
///////////////////////////////////////////////////////////////////////////////


 void brick_collision (vector <Rect>& brick, Circle& ball, double& x_vel,
                    double& y_vel)
  {
    for (int i = 0; i <brick.size() ; ++i)

    {

      if (rect_collision(brick[i],ball,x_vel,y_vel)== true )
        {
          brick.erase(brick.begin()+i);
        }

    }


  }



///////////////////////////////////////////////////////////////////////////////
//                              MAIN FUNCTION                                //
///////////////////////////////////////////////////////////////////////////////

int instinct_main()
{


  // Coordinates
  const int LL_X = -100;
  const int LL_Y = -100;
  const int UR_X = 100;
  const int UR_Y = 100;
  win.coord(LL_X,LL_Y,UR_X,UR_Y );

  // BACKGROUND
  win.set_background_color(DARK_BLUE);

  // radius/velocity/ point of circle(ball)/message
  const int RADIUS = 3;

  // x_vel and y_vel = x velocity and y velocity
  double x_vel = .7;
  double y_vel = -.8;

  // values for point
  const  double X = 0;
  const double Y = 0;
  Point circle (X,Y);

  ///  width, height, x and y of bar
  double x_ = -19;
  double y_ = -90;
  double w_ = 38;
  double h_ = 9;
  Point ba_r(x_,y_);
  Rect bar(ba_r,w_,h_,BLACK,true);

 // TIME
  //time_ = time
  const int TIME_ = 20;
  Timer tmr;
  tmr.start();
  srand(time(0));

  /// BOUNDARIES
  int left_bottom = -UR_X +RADIUS;
  int right_top = UR_X - RADIUS;



// Nunmber of ball allowed before game over.
  int ball_count = 6;

  //////////////////////////
  ///        MESSAGES     //
  //////////////////////////

// m_x = message's x.  m_x = message's y
  const double m_x = -29;
  const double m_y = 96;
  Point message (m_x, m_y);
  Circle ball = Circle(circle,RADIUS,DARK_GREEN,true);

// message of ball
  // 6 = number of letter of balls +1( accounting for space between balls and
  // numer of ball left)
  int balls_ = 6;
  double mess_ball = m_x+(LETTER_WIDTH*balls_);
  double new_mess_ball_y = m_y -( LETTER_HEIGHT*2);
  Point mess_balls = Point (m_x,new_mess_ball_y);
  Point mess_count = Point(mess_ball,new_mess_ball_y);
  Message ball__count = Message(mess_count, ball_count,PINK);

  //// Message game over

  // LETTER_WIDTH = 3.6 , LETTER_HEIGHT = 3.96
  // the Number of letters in game
  // +1(accounts for space bewteen game and over) = 5
  int game_1 = 5;
  double mess_width = 0-(LETTER_WIDTH*game_1);
  int over_y = 10;

  /// Message that tells who won
  int comp_wins = 7; // 7 is the middle space of COMPUTER WINS
  int hum_wins = 4; // 4 is the middle space of YOU WIN
  double win_1x = 0-(LETTER_WIDTH *comp_wins);
  int win_y = -10;
  double win_2x = 0-(LETTER_WIDTH*hum_wins);

  Message comp_win = Message(Point(win_1x,win_y),"COMPUTER WINS",CYAN);
  Message human_win = Message(Point(win_2x,win_y), "YOU WIN",CYAN);

//// for thanks you
  int thank = 9; // the middle space of THANKS FOR PLAYING!
  double thanks_x = 0-(LETTER_WIDTH*thank);

  ///////////////////
  //     PADDLE    //
  //////////////////

  //paddle movement
  double paddle_move = 3;

////// deals with making and creating rectamgles
  double width  = 22;
  double height = 7;
  double start_x = -92;
  double start_y = 43;
  Point start (start_x,start_y);
  int columns = 8;
  int rows = 6;
  Color color ;
  double hor_gap = 1.5 ;
  double vert_gap = 1.5 ;

  vector <Rect> bricks;

  /// calls function create brickse
  create_bricks( bricks ,start ,rows, columns,
               width,  height,hor_gap ,vert_gap);


  // While statement that checks the balls and the paddle/bar and resets ball
  // if esc is pressed terminates program
  while (! win.is_key_down("esc") &&  ball_count >0 && bricks.size() >=1 )

    {
      //// Outputs bar, ball, messages, ball count and moves bar
      win.clear_buffer();
      win  << bar << ball;
      ball.move(x_vel,y_vel);
      draw_bricks (bricks);
      win << Message ( message,"Press esc to exit",ORANGE);
      win << Message (mess_balls, "Balls", PINK);
      win << ball__count;

      win.output_buffer();

      wait_for(TIME_-tmr.get_time() );
      tmr.reset();

      // Paddle movement

      move(bar,paddle_move,LL_X,UR_X, "left", "right");

      ///collision

      //  paddle_collision ( bar , ball , x_vel, y_vel);

      brick_collision(bricks,ball,x_vel,y_vel);
      rect_collision(bar,ball,x_vel,y_vel);
      wall_collision ( ball,  UR_Y,  LL_X, UR_X,  x_vel,  y_vel) ;


      bottom_wall_fall ( ball,  LL_X ,  x_vel, y_vel,  x_vel,  y_vel,
                         circle,  ball_count, ball__count) ;


      ball.move((x_vel), (y_vel));

    }

  win.clear_buffer();


  if (ball_count == 0 || win.is_key_down("esc"))
    {
      win << comp_win ;
      win.output_buffer();
    }
  else
    {
      win << human_win;
      win.output_buffer();
    }

  ///// MESSAGE THAT AKS IF YOU WNAT TO PLAY AGAIN

string  redo =
    win.get_string("Pres 1 to PLAY AGAIN or Press 2 to quit",CYAN);

  if(redo =="1")
    {
      instinct_main();

    }

  else
    {
      win.clear_buffer();

      Message thanks = Message (Point(thanks_x,0),"THANKS FOR PLAYING!",CYAN);

    //Message saying game over when person presses "2" to quit
      win << Message(Point(mess_width,over_y),"GAME OVER!",YELLOW);
      win << thanks;
    }
  win.output_buffer();

  return 0;
}

