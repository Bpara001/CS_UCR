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
// Assignment: Programming Assignment 2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.

#include <iostream>
#include "date.h"

using namespace std;

///////////////////////////// THE TEST HARNESS////////////////////////////////
//Automatically inputs several dates to test the date.cpp!
int main()
{
//This will test a normal date output
    string date1m = "January";
    int date1d = 22;
    int date1y = 2008;

 //This will test a leap year date output
    int date2m = 2;
    int date2d = 29;
    int date2y = 2008;

  //This will test another leap year date
    int date3m = 2;
    int date3d = 29;
    int date3y = 2100;

//This will test a non leap year date and see if it compensates
    int date4m = 2;
    int date4d = 29;
    int date4y = 2009;

 //This will test negative month number
    int date5m = -4;
    int date5d = 16;
    int date5y = 2009;

//This will test a >12 month number
    int date6m = 14;
    int date6d = 16;
    int date6y = 2009;

//This will test the output with no compensation
    int date7m = 10;
    int date7d = 1;
    int date7y = 2009;

//This will test the output with d compensation
    int date8m = 7;
    int date8d = 32;
    int date8y = 2009;

//This outputs everything into the console
    cout << date1m << ", " << date1d << " " << date1y << endl;
    Date calulation1 = Date(date1m,date1d,date1y);
    calulation1.print_alpha();
    cout << endl;

    cout << date2m << "/" << date2d << "/" << date2y << endl;
    Date calulation2 = Date(date2m,date2d,date2y);
    calulation2.print_numeric();
    cout << endl;

    cout << date3m << "/" << date3d << "/" << date3y << endl;
    Date calulation3 = Date(date3m,date3d,date3y);
    calulation3.print_numeric();
    cout << endl;

    cout << date4m << "/" << date4d << "/" << date4y << endl;
    Date calulation4 = Date(date4m,date4d,date4y);
    calulation4.print_numeric();
    cout << endl;

    cout << date5m << "/" << date5d << "/" << date5y << endl;
    Date calulation5 = Date(date5m,date5d,date5y);
    calulation5.print_numeric();
    cout << endl;

    cout << date6m << "/" << date6d << "/" << date6y << endl;
    Date calulation6 = Date(date6m,date6d,date6y);
    calulation6.print_numeric();
    cout << endl;

    cout << date7m << "/" << date7d << "/" << date7y << endl;
    Date calulation7 = Date(date6m,date7d,date7y);
    calulation7.print_numeric();
    cout << endl;

    cout << date8m << "/" << date8d << "/" << date8y << endl;
    Date calulation8 = Date(date8m,date8d,date8y);
    calulation8.print_numeric();
    cout << endl;



    return 0;
}

