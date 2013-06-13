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


#include "intvector.h"
#include <iostream>
using namespace std;

int main()
{



IntVector integers = IntVector(5);


for(int i = 0; i < 5; i++)
{
    integers.set(i, i * 10);
}


cout << endl;
cout <<"====== prints array =====" << endl;
integers.print();
cout << endl;

cout <<"===== use pushback & add another element & display size =====" << endl;
integers.push_back(1);
//integers.set(5,50);
integers.print();
cout << endl;
cout << "size: " << integers.get_size() << endl;

cout <<"==== use popback & display size ====" << endl;
integers.pop_back();
integers.print();
cout << endl;
cout << "size: " << integers.get_size() << endl;
cout << endl;


    return 0;
}
