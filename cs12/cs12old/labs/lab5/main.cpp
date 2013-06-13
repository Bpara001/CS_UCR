//driver program

#include "instinct.h"
#include "lshape.h"
#include "lrectangle.h"
#include "lsquare.h"

#include <vector>

using namespace std;

int instinct_main()
{
  //set window to convenient coordinates
  win.coord(-1, 5, 5, -1);
  win.set_title("CS12 - Lab 5");

  /*****draw icons for choosing a shape**********************************/

  //rectangle
  LSquare(Point(0, 0), 1).plot();
  LRectangle icon_rectangle = LRectangle(Point(0, 0), 0.4, 0.8);
  icon_rectangle.plot();

  //square
  LSquare(Point(0, 1), 1).plot();
  LSquare icon_square = LSquare(Point(0, 1), 0.6);
  icon_square.plot();

  //quit
  LSquare(Point(0, 2), 1).plot();
  win << Message(Point(-0.2, 1.9), "Quit");

  win.output_buffer();

  //declare vector for storing all shapes
  vector<LShape *> shapes;

  Point click = win.get_mouse("Choose shape");

  //loop until quit box clicked filling vector with pointers to Shapes
  while (click.get_x() < -0.5 or click.get_x() > 0.5 or
	 click.get_y() < 1.5 or click.get_y() > 2.5)
    {
      //rectangle
      if (click.get_x() >= -0.5 and click.get_x() <= 0.5 and
	  click.get_y() >= -0.5 and click.get_y() <= 0.5)
	{
	  Point p = win.get_mouse("click on location");
	  
	  /***you should add a rectangle to shapes vector using make_shape***/

          
          //display the shape you added
	}
      //square
      else if (click.get_x() >= -0.5 and click.get_x() <= 0.5 and
	       click.get_y() >= 0.5 and click.get_y() <= 1.5)
	{
	  Point p = win.get_mouse("click on location");
	 
	  /***you should add a square to shapes vector using make_shape***/

	}

        click = win.get_mouse("Choose next shape or quit");
    }

  //clear screen before final output of all shapes and total area
  win.clear_buffer();

  /***you need to calculate and output total area and output all shapes***/
  

  return 0;
}
