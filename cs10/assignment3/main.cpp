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
// TA:Muzaffer Akbay
//
// Assignment: Assignment 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Getting inputs of name and income.
    cout << "Enter the person's name (Last,First): " << endl;
    string name;
    cin >> name;
    int comma_pos = name.find(",");

    cout << "Enter January's income: " << endl;
    double january_income;
    cin >> january_income;

    cout << "Enter Feburary's income: " << endl;
    double feburary_income;
    cin >> feburary_income;

    cout <<"Enter March's income: " << endl;
    double march_income;
    cin >> march_income;

    // Calculating total gross, tax and net income.
    double total_gross = january_income + feburary_income + march_income;
    double total_tax = total_gross * .15;
    double total_net = total_gross - total_tax;


    // The output.
    cout << "\n";
    cout << "Quarterly statement of earnings";
    cout << "\n";
    cout << "\n";
    cout << left << "First: "  << setw(19) << name.substr(comma_pos + 1)
            <<"Last: " << name.substr(0,comma_pos);
    cout << endl;
    cout <<"========================================================" << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(25) << "January's income"<< " "
            << setw(25) << "Feburary's income" << " "
            << setw(25) << "March's income" << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(25) << january_income << " "
            << setw(25) << feburary_income << " "
            << setw(25) << march_income << endl;
    cout <<"========================================================" << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Total gross income "<< " "
            << setw(25) << "Income tax " << " "
            << setw(25) << "Total net income " << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(25) << total_gross << " "
            << setw(25) << total_tax << " "
            << setw(25) << total_net << endl;


return 0;
}

