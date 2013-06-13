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
// Assignment: Programming Assignment 2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#include "date.h"
#include <iostream>
using namespace std;

//The test harness
int main()
{
   //Loop allows the user to input dates into the program to test if the algothriums work
   while(true)
   {
      cout << "===========================================" << endl;
      cout << "Choose the format for input:" << endl
            << "Enter '1' for numerical input (e.g. 1/1/1900)" << endl
            << "Enter '2' for string input (e.g. January 1, 1990)" << endl;
      int choice1;
      cin >> choice1;

  //Loop if the user to chooses to input by month number
      if(choice1 == 1)
      {
         cout << "===========================================" << endl;
         cout << "Enter the month number: " << endl;
         int date_m;
         cin >> date_m;
         cout << "Enter the day number: " << endl;
         int date_d;
         cin >> date_d;
         cout << "Enter the year number: " << endl;
         int date_y;
         cin >> date_y;
         cout << "===========================================" << endl;
         cout <<"ORGINAL: "<< date_m << "/" << date_d << "/" << date_y << endl;
         Date calulation = Date(date_m,date_d,date_y);
         calulation.print_numeric();
      }
  //Loop if the user chooses to input y month name
      else if(choice1 == 2)
      {
         cout << "===========================================" << endl;
         cout << "Enter the month name: " << endl;
         string date_m;
         cin >> date_m;
         cout << "Enter the day number: " << endl;
         int date_d;
         cin >> date_d;
         cout << "Enter the year number: " << endl;
         int date_y;
         cin >> date_y;
         cout << "===========================================" << endl;
         cout <<"ORGINAL: " << date_m << " " << date_d << "," << date_y << endl;
         Date calulation = Date(date_m,date_d,date_y);
         calulation.print_alpha();
      }
  //Outputs error if invalid input is given
      else
      {
         cout << "===========================================" << endl;
         cout <<"ERROR. Invalid Input" << endl;
      }
  //Prompts the user if they would like to quit
      cout << "===========================================" << endl;
      cout << "Input another date?(Enter 'y' or 'n')" << endl;
      string choice2;
      cin >> choice2;
      if(choice2 =="n")
      {
         return 0;
      }
   }

 }
