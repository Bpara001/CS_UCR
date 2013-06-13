#include <iostream>
#include "instinct.h"
using namespace std;

int instinct_main()
{
    Point point1 = win.get_mouse("Click for the first point");
    win << point1;
    Point point2 = win.get_mouse("Click for the second point");
    win << point2;
	
    double xpoint1 = point1.get_x();
    double ypoint1 = point1.get_y();
    double xpoint2 = point2.get_x();
    double ypoint2 = point2.get_y();
    double length1;
    double height1;

    if (xpoint1 == xpoint2)
    { win << Message(Point(0,0),"Error! You just made a horizontal line!");
    }

    else if (ypoint1 == ypoint2)
    { win << Message(Point(0,0),"Error! You just made a vertical Line!");
    }

    else if (ypoint1 < ypoint2)
    {   length1 = xpoint2 - xpoint1;
        height1 = ypoint2 - ypoint2;
        win << Rect(Point(xpoint1,ypoint1),length1,height1);
    }

    else if ( ypoint1 > ypoint2)
    {
        length1 = xpoint2 - xpoint1;
        height1 = ypoint1 - ypoint2;
        win << Rect(Point(xpoint1,ypoint2),length1,height1);
    }
    else
    { win << Message(Point(0,0),"You just made a bad error lol");
    }

    win.output_buffer();
    return 0;
}


