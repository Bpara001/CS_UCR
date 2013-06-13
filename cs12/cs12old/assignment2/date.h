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

// date.h interface file

#ifndef __DATE_H__
#define __DATE_H__

#include <string>
using namespace std;

class Date
{
private:
  int day;
  int month;
  string month_name;
  int year;

public:
  // Default c'tor: creates date 1/1/1900
  Date();

  // mm, dd, year c'tor - e.g. 3, 1, 2010 => March 1st, 2010
  // if any of the arguments are invalid (e.g. 15 for month, or 32 for day)
  // then the constructor must construct a valid Date close to the argument
  // provided - e.g. in above example the Date would be corrected to
  // 12/31/2010; 
  // In case of such invalid input, the constructor must also issue a 
  // warning to the console: e.g.
  // "Invalid date values: Date corrected to 12/31/2010"
  Date(int m, int d, int y);

  // month, day, year c'tor - e.g. December, 15, 2012 => Dec 15th, 2012
  // If the c'tor is unable to recognize the string argument as a 
  // valid month name, then it will issue a console error message:
  // "Invalid month name: the Date was set to 1/1/1900". 
  // (this is a not a good way to handle a c'tor errors, 
  // but until you learn about exceptions it's the best we can do)
  Date(string mn, int d, int y);

  //EXTRA CREDIT: add a number of days to one date to get another:
  Date add_days(int) const;

  // function to output a Date in the format 3/1/2010
  void print_numeric() const;

  // function to output a Date in the format March 1, 2010
  void print_alpha() const;

private:
  // These are "helper functions":
  // member functions that will never be needed by a user of the class - 
  // they are needed by the interface functions (public member functions)
  // to test for validity of arguments and get correct dates


  // test for leap year (year % 4 == 0) => ly; 
  // except 
  // (year % 100 == 0) => NOT ly; except (year % 400 == 0) => ly)
  bool is_leap(int) const;

  // returns number of days allowed in a given month
  // e.g. days_per_month(9) returns 30
  // it must correctly calculate February's days for leap and non-leap years
  // and therefore it also needs the year as a param.
  int days_per_month(int m, int y) const;

  // returns name of a given month
  // e.g. name(12) returns the string "December"
  string name(int m) const;

  // returns number of a given named month:
  // e.g. number("March") returns 3
  int number(string mn) const;
};

#endif // __DATE_H__
