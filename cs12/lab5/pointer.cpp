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
// Assignment: lab5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================


#include <iostream>

using namespace std;

int main()
{

int integer = 10;

int *p1;
int *p2 = NULL;
int *p3 = &integer;
int *p4 = new int();
int *p5 = p1;

cout << endl;
cout <<"Random: " << *p1 << endl;
cout <<"NULL: " <<  p2 << endl;
cout <<"variable: " << *p3 << endl;
cout <<"New: " << *p4 << endl;
cout <<"copy: " << *p5 << endl;
cout << endl;

//delete p1; NOT NEW POINTER, segfault
//delete p2; NOT NEW POINTER, segfault
//delete p3; NOT NEW POINTER, segfault
delete p4;
p4 = NULL;
//delete p5; NOT NEW POINTER, segfualt

    return 0;
}
