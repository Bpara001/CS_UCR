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

int main()
{

Employee Will_Usher = Employee("Will_Usher",8500);
Employee Sarah_Flores = Employee("Sarah_Flores",7250);
Employee Julia_Zaw = Employee("Julia_Zaw", 6650);
Manager David_Wu= Manager("David_Wu",16500,"Wong's Resturant");

cout <<"=================================================" << endl;
cout <<"Employee list for Wong's Restuarnt" << endl;

cout <<"MANAGER:: " << endl;
David_Wu.print();
cout <<"\nEMPLOYEE:: " << endl;
Will_Usher.print();
cout <<"\nEMPLOYEE:: " << endl;
Sarah_Flores.print();
cout <<"\nEMPLOYEE:: " << endl;
Julia_Zaw.print();

cout <<"==========================================" << endl;

}
