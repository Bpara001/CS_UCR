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
  cout << "Input US dollars: ";
  double usd;
  cin >> usd;

  const double euros = usd * .74;
  const double yen = usd * 99.4;
  const double rand = usd * 9.07;
  const double rupees = usd * 49.90;
  const double pesos  = usd * 13.83;
  
  cout << "Euros: " << euros << "\n";
  cout << "Yen: " << yen << "\n";
  cout << "Rand: " << rand << "\n";
  cout << "Rupees: " << rupees << "\n";
  cout << "Pesos: " << pesos << "\n";
  
  return 0;
}
