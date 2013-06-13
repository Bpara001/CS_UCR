#include "instinct.h"

void display_h(Point ll, double size)
{
double x = ll.get_x();
double y = ll.get_y();
Line vert1 = Line(ll,Point(x,y + size));
Line horz1 = Line(Point(x,y + size / 2),Point(x + size,y + size / 2));
Line vert2 = Line(Point(x + size, y + size),Point(x + size, y));
win << vert1 << horz1 << vert2;
}

void display_o(Point ll, double size)
{
double x = ll.get_x();
double y = ll.get_y();
win << Circle(Point(x + size, y + size),size);
}

void display_l(Point ll, double size)
{
double x = ll.get_x();
double y = ll.get_y();
Line vert1 = Line(ll,Point(x,y + size));
Line horz1 = Line(ll,Point(x + size / 2, y));
win << vert1 << horz1;
}

void display_e(Point ll, double size)
{
double x = ll.get_x();
double y = ll.get_y();
Line vert1 = Line(ll,Point(x,y + size));
Line horz1 = Line(ll,Point(x + size / 2, y));
Line horz2 = Line(Point(x, y + size / 2),Point(x + size / 2, y + size / 2));
Line horz3 = Line(Point(x, y + size),Point(x + size / 2, y + size));
win << vert1 << horz1 << horz2 << horz3;
}

int instinct_main()
{

display_h(Point(1,8),1);
display_e(Point(2.5,8),1);
display_l(Point(3.5,8),1);
display_l(Point(4.5,8),1);
display_o(Point(5.5,8),.5);

display_h(Point(1,6),1);
display_o(Point(2.5,6),.5);
display_l(Point(4,6),1);
display_e(Point(5,6),1);
win.output_buffer();

return 0;
}

