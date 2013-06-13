#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{

     win.coord(0,0,30,30);

   int LOOP_BEGIN = 1;
   int LOOP_END = win.get_int("INput how many circles you want!1-10!");

   for (int count = 1; count <= LOOP_END; count++)
   {
      win << Circle(Point(15,15),count);
   }
	win.output_buffer();
	return 0;
}


