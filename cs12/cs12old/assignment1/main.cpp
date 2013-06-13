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
// Assignment: Programming Assignment 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.#include<iostream>


// included files
#include "instinct.h"
#include <iostream>


//This function draws the rectangle and outputs the string inside the button
void draw_button( const Point & lower_left, const std::string label )
{
//Variables and logic for creating the button
    int string_length = label.length();
    double xpoint = lower_left.get_x();
    double ypoint = lower_left.get_y();
    double message_x = xpoint + LETTER_WIDTH/2;
    double message_y = ypoint + LETTER_HEIGHT/2;
    double box_w = string_length * LETTER_WIDTH + LETTER_WIDTH;
    double box_h = LETTER_HEIGHT * 2;
    Rect R = Rect(lower_left,box_w,box_h);
//Outputs the rectangle and string, making a 'button'
    Message label_message = Message(Point(message_x,message_y),label);
    win << R << label_message;
    win.output_buffer();
}

//Main function, prompts user for click and string, then runs draw_button
int instinct_main()
{
    win.coord(0, 0, 100, 100);
    win.set_title("CS12 - Assignment 1");
    string button_name;
    Point button_loc;
//The DO while loop
    do
    {
    button_loc = win.get_mouse("Click the position of the button");
    win.clear_buffer();
    button_name = win.get_string("Name the button (type 'quit' to exit)");
    draw_button(button_loc,button_name);
    win.output_buffer();
    }
    while(button_name != "quit");
    return 0;
}
