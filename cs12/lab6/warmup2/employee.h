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
// Assignment: LAB 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
using namespace std;

class Employee
{
    private:
    string name;
    double salary;

    public:
    Employee();
    Employee(string name, double salary);

    string get_name() const;
    double get_salary() const;
    virtual void print() const;

    void set_salary(double s);
    void raise_salary(int precent);
    void set_name(string n);

    virtual ~Employee();

};
#endif
