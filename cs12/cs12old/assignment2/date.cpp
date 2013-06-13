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

#include "date.h"
#include <iostream>
using namespace std;

// Default c'tor: creates date 1/1/1900
Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
    month_name = "Janurary";

}

// mm, dd, year c'tor - e.g. 3, 1, 2010 => March 1st, 2010
// if any of the arguments are invalid (e.g. 15 for month, or 32 for day)
// then the constructor must construct a valid Date close to the argument
// provided - e.g. in above example the Date would be corrected to
// 12/31/2010;
// In case of such invalid input, the constructor must also issue a
// warning to the console: e.g.
// "Invalid date values: Date corrected to 12/31/2010"
Date::Date(int m, int d, int y)
{

    if(m < 1)
    {
        month = 1;
        m = 1;
        month_name = name(m);
        if(d > days_per_month(m,y))
        {
            day = days_per_month(m,y);
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d < 1)
        {
            day = 1;
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d <= days_per_month(m,y) && d >= 1)
            day = d;
        if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
    }

    else if(m > 12)
    {
        month = 12;
        m = 12;
        month_name = name(m);
        if(d > days_per_month(m,y))
        {
            day = days_per_month(m,y);
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d < 1)
        {
            day = 1;
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d <= days_per_month(m,y) && d >= 1)
            day = d;
        if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
    }

    else
    {
        month = m;
        month_name = name(m);
        if(d > days_per_month(m,y))
        {
            day = days_per_month(m,y);
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d < 1)
        {
            day = 1;
            if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
        }
        else if(d <= days_per_month(m,y) && d >= 1)
            day = d;
        if(y < 0)
            {
                year = 1990;
            }
            else
            {
                year = y;
            }
    }



}

// month, day, year c'tor - e.g. December, 15, 2012 => Dec 15th, 2012
// If the c'tor is unable to recognize the string argument as a
// valid month name, then it will issue a console error message:
// "Invalid month name: the Date was set to 1/1/1900".
// (this is a not a good way to handle a c'tor errors,
// but until you learn about exceptions it's the best we can do)
Date::Date(string mn, int d, int y)
{

    if (mn != "January" && mn != "Februray" &&mn != "March" && mn != " April"
        && mn != "May" && mn != "June" && mn != "July" &&mn != "August"
        && mn != "September" && mn !="October" && mn != "November"
        && mn != "December")
    {
        day = 1;
        year = 1900;
        month_name = "January";
        month = 1;
        cout << "Invalid month The date was set "<< month <<"/"
                << day << "/"<< year << endl;
    }

    else
    {
    month_name = mn;
    month = number(mn);
    day = d;
    year = y;
    int m = number(mn);
    Date(m,d,y);



    }


}

// function to output a Date in the format 3/1/2010
void Date::print_numeric() const
{
    cout <<"The correct date is: "<<  month <<"/" << day << "/"
            << year << endl;
}

// function to output a Date in the format March 1, 2010
void Date::print_alpha() const
{

    cout << "The correct date is: " << month_name <<" " << day << ", "
            << year << endl;
}

// test for leap year (year % 4 == 0) => ly;
// except
// (year % 100 == 0) => NOT ly; except (year % 400 == 0) => ly)
bool Date::is_leap(int n) const
{
    if(n % 4 == 0)
    {
        if(n % 100 == 0)
        {
            if (n % 400 == 0)
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
// e.g. days_per_month(9) returns 30
// it must correctly calculate February's days for leap and non-leap years
// and therefore it also needs the year as a param.
int Date::days_per_month(int m, int y) const
{
    if( m == 1)
    {
        return 31;
    }
    if( m == 2)
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
    if( m == 3)
    {
        return 31;
    }
    if( m == 4)
    {
        return 30;
    }
    if( m == 5)
    {
        return 31;
    }
    if( m == 6)
    {
        return 30;
    }
    if( m == 7)
    {
        return 31;
    }
    if( m == 8)
    {
        return 31;
    }
    if( m == 9)
    {
        return 30;
    }
    if( m == 10)
    {
        return 31;
    }
    if( m == 11)
    {
        return 30;
    }
    if( m == 12)
    {
        return 31;
    }
    return 0;
}

// returns name of a given month
// e.g. name(12) returns the string "December"
string Date::name(int m) const
{
    if(m == 1)
    {
        return "January";
    }
    if(m == 2)
    {
        return "Februrary";
    }
    if(m == 3)
    {
        return "March";
    }
    if(m == 4)
    {
        return "April";
    }
    if(m == 5)
    {
        return "May";
    }
    if(m == 6)
    {
        return "June";
    }
    if(m == 7)
    {
        return "July";
    }
    if(m == 8)
    {
        return "August";
    }
    if(m == 9)
    {
        return "September";
    }
    if(m == 10)
    {
        return "October";
    }
    if(m == 11)
    {
        return "November";
    }
    if(m == 12)
    {
        return "December";
    }
    return " ";
}

// returns number of a given named month:
// e.g. number("March") returns 3
int Date::number(string mn) const
{
    if(mn == "January")
    {
        return 1;
    }
    if(mn == "February")
    {
        return 2;
    }
    if(mn == "March")
    {
        return 3;
    }
    if(mn == "April")
    {
        return 4;
    }
    if(mn == "May")
    {
        return 5;
    }
    if(mn == "June")
    {
        return 6;
    }
    if(mn == "July")
    {
        return 7;
    }
    if(mn == "August")
    {
        return 8;
    }
    if(mn == "September")
    {
        return 9;
    }
    if(mn == "October")
    {
        return 10;
    }
    if(mn == "November")
    {
        return 11;
    }
    if(mn == "December")
    {
        return 12;
    }
    return 0;

}
