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
// Assignment: Lab 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================


#include "instinct.h"


void draw_cube(const Point& loc,double size)
{
double xpoint = loc.get_x();
double ypoint = loc.get_y();
double h_size = size / 2;

Line l1 = Line(loc,Point((xpoint+size),(ypoint+h_size)));
Line l2 = Line(loc,Point((xpoint-size),(ypoint+h_size)));
Line l3 = Line(loc,Point(xpoint,(ypoint-size)));
Line l4 = Line(Point((xpoint),(ypoint-size)),
		Point((xpoint+size),(ypoint-h_size)));
Line l5 = Line(Point((xpoint),(ypoint-size)),
		Point((xpoint-size),(ypoint-h_size)));
Line l6 = Line(Point((xpoint-size),(ypoint-h_size)),
		Point((xpoint-size),(ypoint+h_size)));
Line l7 = Line(Point((xpoint+size),(ypoint-h_size)),
		Point((xpoint+size),(ypoint+h_size)));
Line l8 = Line(Point((xpoint-size),(ypoint+h_size)),
		Point((xpoint),(ypoint+size)));
Line l9 = Line(Point((xpoint+size),(ypoint+h_size)),
		Point((xpoint),(ypoint+size)));

win << l1 << l2 << l3 << l4 << l5 << l6 << l7 << l8 << l9;

}




int instinct_main()
{
    win.coord(0,0,100, 100);
    win.set_title("CS12 - Lab 1: 3d-Cube");
    draw_cube(Point(25,50),10);
    draw_cube(Point(45,65),10);
    draw_cube(Point(65,80),10);


    win.output_buffer();


    
    return 0;
}
