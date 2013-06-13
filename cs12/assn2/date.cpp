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



// date.cpp - implementation file

#include <iostream>
using namespace std;

#include "date.h"

// Default c'tor: creates date 1/1/1900
  Date::Date()
  :day(1),month(1),month_name("January"),year(1900)
  {
  }

  // mm, dd, year c'tor - e.g. 3, 1, 2010 => March 1st, 2010
  // if any of the arguments are invalid (e.g. 15 for month, or 32 for day)
  // then the constructor must construct a valid Date close to the argument
  Date::Date(int m, int d, int y)
  :day(d),month(m),month_name(name(m)),year(y)
  {


     if(m > 12)
     {
        month = 12;
     }
     if(m < 1)
     {
        month = 1;
     }
     if(y < 1)
     {
        year = 1;
     }
     if(d < 1)
     {
        day = 1;
     }
     if(d > days_per_month(month,year))
     {
        day = days_per_month(month,year);
     }

  }

  // month, day, year c'tor - e.g. December, 15, 2012 => Dec 15th, 2012
  Date::Date(string mn, int d, int y)
  :day(d),month(number(mn)),month_name("mn"),year(y)
  {
     if(mn != "January" && mn != "Feburary" && mn != "March" &&mn != "Apirl" &&
        mn != "May" && mn != "June" && mn != "July" && mn != "August" &&
        mn != "September" && mn != "October" && mn != "November" &&
        mn != "December")
     {
        cout <<" Invalid Month: date has been set to 1/1/1990" << endl;
        month = 1;
        month_name = "January";
        day = 1;
        year = 1900;
     }
     else
     {
     Date(month,d,y);
     }

  }

  //EXTRA CREDIT: add a number of days to one date to get another:
  //void Date::add_days(int n) const



  // function to output a Date in the format 3/1/2010
  void Date::print_numeric() const
  {
     cout <<"CORRECTED: " << month <<"/"<< day <<"/" << year << endl;
  }

  // function to output a Date in the format March 1, 2010
  void Date::print_alpha() const
  {
     cout<<"CORRECTED: " << name(month) <<" " << day <<", " << year << endl;
  }

  // These are "helper functions":


  // test for leap year (year % 4 == 0) => ly;
  bool Date::is_leap(int y) const
  {
     if(y % 4 == 0)
     {
        if(y % 100 == 0)
        {
            if(y % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
     }
     else
     {
         return false;
     }


  }

  // returns number of days allowed in a given month
  int Date::days_per_month(int m, int y) const
  {

     if(m == 1)
     {
        return 31;
     }
     else if(m == 2)
     {
        if(is_leap(y) == true)
        {
           return 29;
        }
        else
        {
           return 28;
        }
     }
     else if(m == 3)
     {
        return 31;
     }
     else if(m == 4)
     {
        return 30;
     }
     else if(m == 5)
     {
        return 31;
     }
     if(m == 6)
     {
        return 30;
     }
     else if(m == 7)
     {
        return 31;
     }
     else if(m == 8)
     {
        return 31;
     }
     else if(m == 9)
     {
        return 30;
     }
     else if(m == 10 )
     {
        return 31;
     }
     else if(m == 11)
     {
        return 30;
     }
     else if(m == 12)
     {
        return 31;
     }
     return 0;
  }

  // returns name of a given month
  string Date::name(int m) const
  {
     if(m == 1)
     {
        return "January";
     }
     else if(m == 2)
     {
        return "February";
     }
     else if(m == 3)
     {
        return "March";
     }
     else if(m == 4)
     {
        return "April";
     }
     else if(m == 5)
     {
        return "May";
     }
     else if(m == 6)
     {
        return "June";
     }
     else if(m == 7)
     {
        return "July";
     }
     else if(m == 8)
     {
        return "August";
     }
     else if(m == 9)
     {
        return "September";
     }
     else if(m == 10 )
     {
        return "October";
     }
     else if(m == 11)
     {
        return "November";
     }
     else if(m == 12)
     {
        return "December";
     }
     return "";
  }

  // returns number of a given named month:
  int Date::number(string mn) const
  {
     if(mn == "January")
     {
        return 1;
     }
     else if(mn == "February")
     {
        return 2;
     }
     else if(mn == "March")
     {
        return 3;
     }
     else if(mn == "April")
     {
        return 4;
     }
     else if(mn == "May")
     {
        return 5;
     }
     else if(mn == "June")
     {
        return 6;
     }
     else if(mn == "July")
     {
        return 7;
     }
     else if(mn == "August")
     {
        return 8;
     }
     else if(mn == "September")
     {
        return 9;
     }
     else if(mn == "October")
     {
        return 10;
     }
     else if(mn == "November")
     {
        return 11;
     }
     else if(mn == "December")
     {
        return 12;
     }
     return 0;
  }

