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
// Assignment: LAB 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================





//driver program

#include "instinct.h"
#include "jshape.h"
#include "jrectangle.h"
#include "jsquare.h"
#include "jtriangle.h"
#include <vector>

using namespace std;

int instinct_main()
{
  //set window to convenient coordinates
  win.coord(0, 0, 10, 10);
  win.set_title("CS12 - Lab 5");
    double total_area = 0;

  /*****draw icons for choosing a shape**********************************/

  //rectangle
  JSquare(Point(1, 6), 1).plot();
  JRectangle icon_rectangle = JRectangle(Point(1, 6.0), 0.4, 0.8);
  icon_rectangle.plot();

  //square
  JSquare(Point(1, 5), 1).plot();
  JSquare icon_square = JSquare(Point(1, 5.0), 0.6);
  icon_square.plot();

  //triangle
  JSquare(Point(1,4),1).plot();
  JTriangle icon_triangle = JTriangle(Point(1,4),0.5,0.7);
  icon_triangle.plot();

  //quit
  JSquare(Point(1,3), 1).plot();
  win << Message(Point(.75, 3.00), "Quit");

  win.output_buffer();

  //declare vector for storing all shapes
  vector<JShape *> shapes;

  Point click = win.get_mouse("Choose shape");

  //loop until quit box clicked filling vector with pointers to Shapes
  while (click.get_x() < .5 or click.get_x() > 1.5 or
	 click.get_y() < 2.5 or click.get_y() > 3.5)
    {
      //rectangle
      if (click.get_x() >= .5 and click.get_x() <= 1.5 and
	  click.get_y() >= 5.5 and click.get_y() <= 6.5)
	{
	  Point p = win.get_mouse("click on location");

	  /***you should add a rectangle to shapes vector using make_shape***/
	shapes.push_back(new JRectangle(p,0.4,0.8));
	total_area += icon_rectangle.area();
	for(unsigned int i = 0; i < shapes.size(); i++)
        {
            shapes[i]->plot();
        }

	}
      //square
      else if (click.get_x() >= 0.5 and click.get_x() <= 1.5 and
	       click.get_y() >= 4.5 and click.get_y() <= 5.5)
	{
	  Point p = win.get_mouse("click on location");

	  /***you should add a square to shapes vector using make_shape***/
	  shapes.push_back(new JSquare(p,0.6));
	  total_area += icon_square.area();
	  for(unsigned int i = 0; i < shapes.size(); i++)
        {
        shapes[i]->plot();
        }

	}

     //triangle
      else if (click.get_x() >= .5 and click.get_x() <= 1.5 and
	       click.get_y() >= 3.5 and click.get_y() <= 4.5)
	       {

        Point p = win.get_mouse("click on location");

	  /***you should add a triangle to shapes vector using make_shape***/
	  shapes.push_back(new JTriangle(p,0.5,0.7));
	  total_area += icon_triangle.area();
	  for(unsigned int i = 0; i < shapes.size(); i++)
        {
        shapes[i]->plot();
        }

	       }
        click = win.get_mouse("Choose next shape or quit");
    }

  //clear screen before final output of all shapes and total area
  win.clear_buffer();

    win << Message(Point(.25,9.7),"Total Area: ");
    win << Message(Point(2.25,9.7), total_area);
    for(unsigned int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->plot();
    }
  /***you need to calculate and output total area and output all shapes***/




  return 0;
}
