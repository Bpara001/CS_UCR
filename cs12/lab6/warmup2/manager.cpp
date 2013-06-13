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
#include "manager.h"
using namespace std;

Manager::Manager()
:Employee("",0),department("")
{
}

Manager::Manager(string name, double salary, string department)
:Employee(name,salary), department(department)
{
}

string Manager::get_dep()
{
    return department;
}

void Manager::print() const
{
    this->Employee::print();
    cout << "Department: " << department << endl;
}

void Manager::set_dep(string d)
{
    this->department = d;
}

Manager::~Manager()
{
}
