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
// Assignment: lab2 exercise3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.#include<iostream>

#include <iostream>
using namespace std;

int main()
{
  cout << "Input account balance: ";
  double balance;
  cin >> balance;
 
  cout << "Input interest rate: ";
  double rate;
  cin >> rate;
  
  cout << "Input number of years: ";
  double years;
  cin >> years;

  const double rate2 = rate * .01;
  const double subtotal = balance * rate2;
  const double total = subtotal * years;
  
  cout << "Interest Rate after 2 years: " << total << "\n";
  

  
  return 0;
}
