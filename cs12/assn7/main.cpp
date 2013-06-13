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
// Assignment: Programming Assignment 7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#include "instinct.h"
#include <cmath>

using namespace std;

//FUNCTION, CREATRES A SNOWFLAKE at START
void create_snowflake(Point start,double n, double line_length)
{
    const double pi = 3.14159265;
    const int line_decrement = 3;
    const double min_line_length = .5;
    double length = line_length / (pow(line_decrement,n));

    //BASE CASE
    if(line_length < min_line_length)
    {
        return;
    }

    //RECURSIVE FOR LOOP, rotates x6 lines and duplicates
    for(int i = 1; i < 7; i++)
    {

        double angle = (i*pi)/line_decrement;
        Point end = Point((((cos(angle)) * length) + start.get_x()),
                    (((sin(angle)) * length)) + start.get_y());
        win << Line(start,end,BLUE);
        n = i - (i - 1);
        create_snowflake(end,n,length);
    }
}

//TEST HARNESS
int instinct_main()
{
    win.coord(0,0,100,100);
    string choice;

    //PROMPTS USER FOR CENTER AND LENGTH of SNOWFLAKE, ENDS IF USER QUITS
    while(true)
    {
        Point click = win.get_mouse("Click for the center of the snowflake");
        double l = win.get_double("Enter length between 1 to 40 (rec: 25): ");

        if(l >= 1 && l <= 40)
        {
            create_snowflake(click,0,l);
            win.output_buffer();
            choice = win.get_string("Create another snowflake?( y / n ): ");
        }
        else
        {
            choice = win.get_string("Invlaid length, try again? ( y / n): ");
        }

        if(choice != "y")
        {
            return 0;
        }
        win.clear_buffer();
    }
    return 0;
}
