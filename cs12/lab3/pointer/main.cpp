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
// Assignment: lab 3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================
#include <iostream>
using namespace std;

int main()
{

  int i = 1;
  double d = 2.5;
  string s = "hello";

  int* i_pt = &i;
  double* d_pt = &d;
  string* s_pt = &s;


  cout <<"value: " << i << " address: " << i_pt << endl;
  cout <<"value: " << d << " address: " << d_pt << endl;
  cout <<"value: " << s << " address: " << s_pt << endl;

  double* dptr4 = NULL;
  cout << "NULL value: " << dptr4 << endl;

  dptr4 = new double;
  *dptr4 = 3.00;
  cout << "New value: " << *dptr4 << endl;
  delete dptr4;
  dptr4 = NULL;











  return 0;
}
