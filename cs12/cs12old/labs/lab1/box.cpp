#include "instinct.h"

// Check to see whether the Point, click, was inside the bounds of the
// Rectangle, box.
bool inside( const Point& click, const Rect& box )
{
   double xclick = click.get_x();
   double yclick = click.get_y();
   Point lowerleft = box.get_lower_left();
   double x_ll = lowerleft.get_x();
   double y_ll = lowerleft.get_y();
   double height = box.get_height();
   double width = box.get_width();

   if(yclick > y_ll 
&& yclick < y_ll + height 
&& xclick > x_ll 
&& xclick < x_ll + width) 
	{
	     return true;
	}
   else return false;

}

int instinct_main()
{
    win.coord(0, 0, 8, 8);
    win.set_title("CS12 - Lab 1: Box");

    // Create the Rectangle
    Rect r = Rect(Point(2,2),2,2);

    // Allow the user to click five times before the program ends.
    for( int i = 5; i > 0; i-- )
    {
        win << r;
	win.output_buffer();
        Point mouseclick = win.get_mouse("click to continue");
	if (inside(mouseclick,r) == true)
	{ 
	win.clear_buffer();
	win << r << Message(mouseclick, "Inside");
	win.output_buffer();
	} 
        else 
	{
	win.clear_buffer();
	win << r << Message(mouseclick, "Outside");
	win.output_buffer();
	}
    }

    return 0;
}
