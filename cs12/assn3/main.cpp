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
// Assignment: Programming Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

//main for assignment 3

#include "instinct.h"
#include "button.h"
using namespace std;

//Test harness
int instinct_main()
{
    //Sets win coordinates, buttons, and quit_count
    win.coord(0,0,100,100);
    Button toggle = Button( Point(75,90),"Show / Hide");
    Button main = Button(Point(35,40),"Noname BUTTON");
    int quit_count = 0;

    //allows the user to keep clicking until main button is clicked 2 times
    while(quit_count < 2)
    {
        toggle.draw();
        main.draw();
        win.output_buffer();

        Point click = win.get_mouse("Click!");
        win.clear_buffer();

        //Determines wheather to movie button, hide button, or transform button
        if(toggle.is_clicked(click) == true)
        {
            if(main.is_shown() == true)
            {
                main.hide();
            }
            else
            {
                main.show();
            }
        }
        else if(main.is_clicked(click) == true)
        {
            main = Button(click,"Click to QUIT");
            quit_count++;
        }
        if(main.is_shown() == true)
        {
            main.center(click);
        }
    }
    return 0;
}
