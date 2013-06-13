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
// Assignment: lab2 exercise2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.#include<iostream>

#include <iostream>
using namespace std;

int main()
{
  cout << "Input your age!";
  double age;
  cin >> age;
 
  double number1 = 220;
  const double percent1 = 0.60; 
  const double percent2 = 0.75;

  double subtotal = number1 - age;

  double higher = subtotal * percent2;
  double lower = subtotal * percent1;
  
  cout << "Your target heart rate is between " << lower << " and " << higher << " bpm" << "\n";
  
  

  
  return 0;
}
