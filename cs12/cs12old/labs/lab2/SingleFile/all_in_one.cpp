// Put needed includes here
#include <iostream>
#include <vector>
#include <cmath>

// Tell the program to use the standard namespace
using namespace std;

// Greatest common denominator function
// Returns  the gcd of a and b as an int.
// You can use this to reduce your fractions.
// make this a global function (i.e. *separate* from the class)
int gcd( int a, int b )
{
  int c = a % b;
  while( c != 0 )
    {
      a = b;
      b = c;
      c = a % b;
    }
  return b;
}

//Put Rational class here
class Rational
{

private:
  int numerator;
  int denominator;

public:
 
 Rational()
  {
    numerator=1;
    denominator =1;
  }

 Rational(int y)
  {
    numerator=y;
    denominator =1;
  }

 
 Rational(int y,int z)
  {
  
    numerator=y;
    denominator=z;
  }
  
 int  get_numer() const
  {
    return numerator;
  }

  int  get_denom() const
  {
    return denominator;
  }


//.These are the arithmetic functions for the rational class
// they are invoked as follows:
// to add rationals x to rational y, and store result in rational z:
// z = y.add( x ) 
// where y is the *implicit* parameter, and x is the *explicit* parameter

// These functions will go *inside* the class.


Rational add( const Rational & val ) const
{
  int a= (numerator*val.denominator + denominator*val.numerator);
    
  int b = (denominator*val.denominator);
 
  return Rational(a,b);
}

 

Rational subtract( const Rational & val ) const
{
 int a= (numerator*val.denominator - denominator*val.numerator);
    
  int b = (denominator*val.denominator);
 
  return Rational(a,b);
}

Rational multiply( const Rational & val ) const
{
  int a= (numerator*val.numerator);
    
  int b = (denominator*val.denominator);
 
  return Rational(a,b);
}

Rational divide( const Rational & val ) const
{
  int a= (numerator*val.denominator );
    
  int b = (denominator*val.numerator);
 
  return Rational(a,b);
}


// This function will output a Rational object to console.
// It should also go *inside* the rational class.
void print( const Rational & val ) const
{
  if (val.denominator == 1)
  {
    cout <<val.numerator<<endl;
  }
  else 
    {
      cout <<val.numerator<< "/" << val.denominator << endl;
    }
}

};


//Write a simple main to test your class here.

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
