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
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "employee.h"
using namespace std;

class Manager: public Employee
{
    private:
    string department;

    public:

    Manager();
    Manager(string name, double salary, string department);
    string get_dep();
    void virtual print() const;
    void set_dep(string d);
    virtual ~Manager();

};
#endif
