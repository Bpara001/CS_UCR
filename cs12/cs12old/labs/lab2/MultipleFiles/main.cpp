#include <iostream>
#include "rational.h"

using namespace std;


//Tell program to use standard namespace


//Copy your main from all_in_one.cpp and put it here
int main()
{

  Rational r1 = Rational(1,2);
  Rational r2 = Rational(3,4);

  Rational a = r1.add(r2);
  Rational b = r1.subtract(r2);
  Rational c = r1.multiply(r2);
  Rational d = r1.divide(r2);
  Rational e = r1.add(r1);

  cout <<"a: ";
  r1. print(r1);

 cout <<"b: ";
  r2. print(r2);

 cout <<"a+b: ";
  a.print(a);

 cout <<"a-b: ";
  b.print(b);

 cout <<"a*b: ";
  c.print(c);

 cout <<"a/b: ";
  d.print(d);

 cout <<"a+a: ";
  e.print(e);


 return 0;
}
