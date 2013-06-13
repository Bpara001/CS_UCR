#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{

	win.coord(89.7,0,107.9,10);

	Point point1 = win.get_mouse("Click to tune the radio");
	double xpoint1 = point1.get_x();

	win << Message(Point(89.7,10 - LETTER_HEIGHT * 2),xpoint1);

	win.output_buffer();
	return 0;
}


