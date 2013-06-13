// This program draws a bowtie shape in the graphic area it should look
// something like this   |\/|
//                       |/\|

#include "instinct.h"

int instinct_main()
{
    win.coord(-10, 10, 10, -10);
    win.set_title("CS12 - Lab3: Syntax Errors");
    
    Point p1 = Point( -1, 1 );
    Point p2 = Point( 1, -1 );
    Point p3 = Point( 1, 1 );
    Point p4 = Point( -1, -1 );

         
    win << Line( p1, p2 ) << Line( p2, p3 ) << Line( p3, p4 )
    << Line( p4, p1 );

    win.output_buffer();
    return 0;
}
