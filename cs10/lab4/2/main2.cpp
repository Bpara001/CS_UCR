#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{


Circle a = Circle(Point(5,5),.9,BLACK);
Circle b = Circle(Point(3,5),.9,BLUE);
Circle c = Circle(Point(7,5),.9,RED);
Circle d = Circle(Point(4,4),.9,YELLOW);
Circle e = Circle(Point(6,4),.9,GREEN);


win << a << b << c << d << e;

win.output_buffer();
return 0;
}
