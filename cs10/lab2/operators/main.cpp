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
// Assignment: lab2 exercise1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.#include<iostream>

#include <iostream>
using namespace std;

int main()
{
  cout << "Input the first number!";
  int number1;
  cin >> number1;
 
  cout << "Input the second number!";
  int number2;
  cin >> number2;

  int addition = number1 + number2;
  int mult = number1 * number2;
  const double div = number1 / number2;
  
  cout << number1 << "+" << number2 << "=" << addition << "\n";
  cout << number1 << "*" << number2 << "=" << mult << "\n";
  cout << number1 << "/" << number2 << "=" << div << "\n";
  

  
  return 0;
}
