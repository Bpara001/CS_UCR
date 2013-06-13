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
#include "employee.h"

Employee::Employee()
:name(""), salary(0)
{
}

Employee::Employee(string name, double salary)
:name(name),salary(salary)
{
}

string Employee::get_name() const
{
    return name;
}
double Employee::get_salary() const
{
    return salary;
}
void Employee::print() const
{
    cout <<"Name: " << name << "\nSalary: $" << salary << endl;
}

void Employee::set_salary(double s)
{
    this->salary = s;
}
void Employee::raise_salary(int precent)
{
    double raise_value = (precent / 100) * salary;
    this->salary += raise_value;
}
void Employee::set_name(string n)
{
    this->name = n;
}

Employee::~Employee()
{
}
