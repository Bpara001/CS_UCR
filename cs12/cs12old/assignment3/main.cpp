// Course: CS 12 quarter 2 , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 001
// Lab Section: 021
// TA: Denise Duma
//
// Assignment: Programming Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.


//~~~~~~MAIN FOR ASSIGNMENT 2~~~~~~
#include <iostream>
#include "button.h"
#include "instinct.h"
using namespace std;

int instinct_main()
{

//Uses the button Class to create Buttons!! Also sets count for loop + win cord
    win.coord(0,0,100,100);
    Message message_1 = Message(Point(2,97),"Click the screen");
    Button show_button = Button(Point(75,95),"Show / Hide");
    Button main_button = Button(Point(45,50),"THE BUTTON");
    int count = 0;

//First defualt output of everything
    win << message_1;
    main_button.draw();
    show_button.draw();
    win.output_buffer();

//Loop for the test harness to work!!!
//Goes through phase 1 and phase 2!!
    while( count < 2)
    {
//Gets the click of the user
        Point click = win.get_mouse(" ");

//Initiates "Phase 2" of the loop
        if(main_button.is_clicked(click) == true  &&
           main_button.is_shown() == true)
        {
            count ++;
            main_button = Button(Point(click),"Click to QUIT");
            main_button.show();
        }
//Shows main button if show button is clicked!
        if(show_button.is_clicked(click) == true)
        {
            if(main_button.is_shown() == true)
             {
                main_button.hide();
             }
            else if(main_button.is_shown() == false)
             {
               main_button.show();
             }

        }

//Moves the main button if show button was not clicked!
        if(show_button.is_clicked(click) == false)
        {
            main_button.center(click);
        }
        
//Sets the new location of main button, clears window!

        win.clear_buffer();

//Outputs everything!!
        show_button.draw();
        main_button.draw();
        win << message_1;
        win.output_buffer();
    }

//Terminates the program
    return 0;
}
