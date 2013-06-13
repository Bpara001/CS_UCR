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



// date.h interface file

#ifndef __DATE_H__
#define __DATE_H__

#include <string>
using namespace std;

/*! \class Date
    \brief a simplistic date class
    stores the month by both name and number,
    as well as day and year as numbers
*/

class Date
{
private:
  int day;
  int month;
  string month_name;
  int year;

 public:
  /*!
    \brief Default c'tor: creates date 1/1/1900
  */
  Date();


  /*!
    \brief (month number, day number, year) c'tor

    e.g. (3, 1, 2010) means March 1st, 2010
    If any of the arguments are invalid (e.g. 15 for month, or 32 for day)
    then the constructor MUST construct a valid Date close to the argument
    provided - e.g. Date(15, 32, 2010) would be corrected to 12/31/2010;
    In case of such invalid input, the constructor must ALSO issue a
    warning to the console: e.g.
    "Invalid date values: Date corrected to 12/31/2010"
    @param m = month number (int)
    @param d = day number (int)
    @param y = year (int)
  */
  Date(int m, int d, int y);


  /*!
    \brief (month name, day number, year) c'tor

    e.g. ("December", 15, 2012) means December 15th, 2012
    If the c'tor is unable to recognize the string argument as a
    valid month name, then it will create the default date object (1/1/1900),
    and issue a console error message:
    "Invalid month name: the Date was set to 1/1/1900".
    It would be nice to recognize that
    "december" or "Dec" or "dec" all  mean "December", etc.
    but this is NOT required.
    @param m_name = month name (string)
    @param d = day (int)
    @param y = year (int)
  */
  Date(string m_name, int d, int y);


  /*
    EXTRA CREDIT:
    add a number of days to one date to get another date
    Make sure that the resulting date is still valid!!
    @param d = days to be added to initial Date (implicit param)
    @return Date = adjusted date
  */
  // Date add_days(int d) const;


  /*!
    \brief function to print a Date to the console in the format 3/1/2010
  */
  void print_numeric() const;


  /*!
    function to print a Date to the console in the format March 1, 2010
  */
  void print_alpha() const;


 private:
  /*!
    These are "helper functions":
    member functions that will never be needed by a user of the class -
    they are needed by the interface functions (public member functions)
    to test for validity of arguments and get correct dates
    i.e. to help in the construction of a valid date
    Make sure ALL your helper functions recognize and deal with
    invalid input - e.g. negative months, or invslid month names.
  */

  /*!
    \brief  test for leap year:

    if (year % 4 == 0) then year is leap year
    UNLESS
    if (year % 100 == 0)then year is NOT leap year
    BUT if (year % 400 == 0) then year IS leap year
    so the years 1700, 1800 and 1900 are NOT leap years.
    but the years 1600 and 2000 ARE leap years
    See Wikipedia for more details
    @param y = year
    @return bool = is leap year
  */
  bool is_leap(int y) const;


  /*!
    \brief returns number of days in a given month

    e.g. days_per_month(9, 2010) returns 30 because September has 30 days
    *It must correctly calculate February's days for leap and non-leap years*
    and therefore it also needs the year as a param.
    @param m = month number
    @param y = year
    @return int = number of days in given month in given year
  */
  int days_per_month(int m, int y) const;


  /*
    \brief returns name of a given month

    e.g. name(12) returns the string "December"
    QUESTION: what should it return if if given an invalid number?
    @param m = month number
    @return string = name of month
  */
  string name(int m) const;


  /*
    \brief returns number of a given named month:

    e.g. number("March") returns 3
    QUESTION: what should it return if if given an invalid name?
    @param m_name = month name
    @return int = month number
  */
  int number(string m_name) const;
};


#endif // __DATE_H__
