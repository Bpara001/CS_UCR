#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{
	Point center = win.get_mouse("Click the center of the object");
	double length = win.get_int("Input the length of the square");
	
	double xpoint1 = center.get_x();
	double ypoint1 = center.get_y();
	double xpoint2 = xpoint1 - (length/2);
	double ypoint2 = ypoint1 - (length/2);
	Point p1 = Point(xpoint2,ypoint2);

	win << Message(Point(xpoint1,ypoint1),length);
	win  << Rect(p1,length,length);
	win  << Circle(center,length/2);

	win.output_buffer();
	return 0;
}


