#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{

	Point square_lowerleft = win.get_mouse("Click to Place the base of the house");
	double square_xpoint1 = square_lowerleft.get_x();
	double square_ypoint1 = square_lowerleft.get_y();
	double square_xpoint2 = square_xpoint1 - (3/2);
	double square_ypoint2 = square_ypoint1 - (1.5/2);
	Point square_center = Point(square_xpoint2,square_ypoint2);
	win << Rect(square_center,3,1.5);
	win.output_buffer();


	Point triangle_p1 = win.get_mouse("Construct the roof by placing three corners,\n click to place the first corner!");
	Point triangle_p2 = win.get_mouse("Click to place the second corner!");
	Point triangle_p3 = win.get_mouse("Click to place the third corner!");
	win << Triangle(triangle_p1,triangle_p2,triangle_p3);
	win.output_buffer();



	Point circle1_center = win.get_mouse("Place a window1");
	win << Circle(circle1_center,.3);
	win.output_buffer();

	Point circle2_center = win.get_mouse("Place another window!");
	win << Circle(circle2_center,.3);
	win.output_buffer();

	Point door_lowerleft = win.get_mouse("Place a Door!");
	double door_xpoint1 = door_lowerleft.get_x();
	double door_ypoint1 = door_lowerleft.get_y();
	double door_xpoint2 = door_xpoint1 - (.4/2);
	double door_ypoint2 = door_ypoint1 - (.8/2);
	Point door_center = Point(door_xpoint2,door_ypoint2);
	win << Rect(door_center,.4,.8);
	win.output_buffer();


return 0;
}
