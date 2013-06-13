// Course: CS 10 quarter 1 , 2009
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 002
// Lab Section: 026
// TA: (i dont know yet?)
//
// Assignment:  lab 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.#include<iostream>

#include <iostream>
using namespace std;
int main()
{
    cout << "Enter your full name!(First, Middle Initinal, Last)";
    string first;
    string middle;
    string last;
    cin >> first >> middle >> last;

    cout << endl;
    cout << "Here are possible Emails for your name " << endl;
    cout << first.substr(0,1) + last << endl;
    cout << first + last.substr(0,1) << endl;
    cout << first.substr(0,1) + middle.substr(0,1)
            + last.substr(0,1) << "8" << endl;
    cout << first + last.substr(0,1) << "4" << endl;


    return 0;
}

