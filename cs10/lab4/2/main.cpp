#include "instinct.h"

int instinct_main()
{

  Circle c = Circle(Point(2,6),1,BLUE);
  win << c;
c.move (1.25,-1);
  c.set_color(YELLOW);
win << c;
 c.move(1.25,1);
 c.set_color(BLACK);
 win << c;
 c.move (1.25,-1);
 c.set_color(GREEN);
 win << c;
 c.move (1.25,1);
 c.set_color(RED);
 win << c;
win.output_buffer();
return 0;
}
