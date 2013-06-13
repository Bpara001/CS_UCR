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
// Assignment: Programming Assignment 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================


// included files
#include "instinct.h"



// Creates a rectangle with a label inside
void draw_button( const Point & lower_left, const std::string label )
{
   //Retrieves x & y points of the click, and the length of the string
   double xpoint = lower_left.get_x();
   double ypoint = lower_left.get_y();
   int s_length = label.length();

   //Calculates the height and width of the rectangle
   double width = s_length * LETTER_WIDTH + LETTER_WIDTH;
   double height = LETTER_HEIGHT * 2;

   //Claculates the position of the text inside the box
   Message input = Message(Point(xpoint + LETTER_WIDTH/2,
                                 ypoint + LETTER_HEIGHT/2), label);

   //Outputs the rectangle and label onto the screen
   win << Rect(lower_left, width, height) << input;

}

// The Test Harness
int instinct_main()
{
    win.coord(0, 0, 100, 100);
    win.set_title("CS12 - Assignment 1");
    string input = "";

    //Keeps prompting the user until they type quit
    while(true)
    {

       //Gets the input of the user and clears buffer after mouse click
       Point pos = win.get_mouse("Click on the lowerleft corner of the button");
       string input = win.get_string("Name the label of the button");
       win.clear_buffer();

       //Calls the drawbutton function, outputs everything
       draw_button(pos,input);
       win.output_buffer();

       //Kills program if quit is typed
       if(input == "quit")
       {
          return 0;
       }

    }
    return 0;
}
