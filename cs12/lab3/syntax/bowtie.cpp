// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// Assignment: lab 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
// This program draws a bowtie shape in the graphic area it should look
// something like this   |\/|
//                       |/\|

//need includes
#include "instinct.h"
using namespace std;

//must be named  rename to intstinct
int instinct_main()
{
    win.coord(-10, 10, 10, -10);
    win.set_title("CS12 - Lab3: Syntax Errors");


    //Points variables were not declared properly
    Point p1 = Point(-1,1);
    Point p2 = Point(1,-1);
    Point p3 = Point(1,1);
    Point p4 = Point(-1,-1);

    //Delete semicolons inbetween, line syntax, operator
    win << Line( p1, p2 ) << Line( p2, p3 ) << Line( p3, p4 )
     << Line( p4, p1 );

    win.output_buffer();

    //Delete semicolon at end, need to end program

    return 0;
}
