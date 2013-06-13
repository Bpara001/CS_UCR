// Course: CS 10 quarter 1 , 2009
//
// First Name: Chris
// Last Name: Wong
// Login id: 860-923-521
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 02
// Lab Section: 026
// TA: Muzaffer Akbay
//
// Assignment: Assignment 4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================


#include "instinct.h"


int instinct_main()
{
    //getting inputs
    const int simon_number = win.get_int("Input number of votes for Simon");
    const int ellen_number = win.get_int("Input number of votes for Ellen");
    const int randy_number = win.get_int("Input number of votes for Randy");
    const int kara_number = win.get_int("Input number of votes for Kara");
    int max_number = simon_number + ellen_number + randy_number + kara_number;
    
     //creates the dimensions of the window
     win.coord(0,0,max_number * 1.5,max_number);

     //calculates the rectangle dimensions
     Point simon_pt = Point(LETTER_WIDTH *4,max_number *.8);
     Point ellen_pt = Point(LETTER_WIDTH *4,max_number *.65);
     Point randy_pt = Point(LETTER_WIDTH *4,max_number *.5);
     Point kara_pt = Point(LETTER_WIDTH *4,max_number *.35);

     //creates retangles
     win << Rect(simon_pt,simon_number,LETTER_HEIGHT * 5,RED,true) <<
            Message(Point(max_number/10 + simon_number + LETTER_WIDTH,
            max_number *.8 + LETTER_HEIGHT * 3),"Simon");
     win << Rect(ellen_pt,ellen_number,LETTER_HEIGHT * 5,PURPLE,true) <<
            Message(Point(max_number/10 + ellen_number + LETTER_WIDTH,
            max_number *.65 + LETTER_HEIGHT * 3),"Ellen");
     win << Rect(randy_pt,randy_number,LETTER_HEIGHT * 5,GREEN,true) <<
            Message(Point(max_number/10 + randy_number + LETTER_WIDTH,
            max_number *.5 + LETTER_HEIGHT * 3),"Randy");
     win << Rect(kara_pt,kara_number,LETTER_HEIGHT * 5,BLUE,true)<<
            Message(Point(max_number/10 + kara_number + LETTER_WIDTH,
            max_number *.35 + LETTER_HEIGHT * 3),"Kara");

    win.output_buffer();
    return 0;
}

