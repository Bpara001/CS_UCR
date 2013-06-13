#include "rational.h"
#include <iostream>
using namespace std;

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

 Rational ::Rational()
  {
    numerator=1;
    denominator =1;
  }

 Rational ::Rational(int y)
  {
    numerator=y;
    denominator =1;
  }


 Rational ::Rational(int y,int z)
  {

    numerator=y;
    denominator=z;
  }

 int  Rational:: get_numer() const
  {
    return numerator;
  }

  int  Rational:: get_denom() const
  {
    return denominator;
  }


//.These are the arithmetic functions for the rational class
// they are invoked as follows:
// to add rationals x to rational y, and store result in rational z:
// z = y.add( x )
// where y is the *implicit* parameter, and x is the *explicit* parameter

// These functions will go *inside* the class.


Rational Rational::add( const Rational & val ) const
{
  int a= (numerator*val.get_denom() + denominator*val.get_numer());

  int b = (denominator*val.get_denom());

  return Rational(a,b);
}



Rational Rational::subtract( const Rational & val ) const
{
  int a= (numerator*val.get_denom() - denominator*val.get_numer());

  int b = (denominator*val.get_denom());

  return Rational(a,b);
}

Rational Rational::multiply( const Rational & val ) const
{
  int a= (numerator*val.get_numer());

  int b = (denominator*val.get_denom());

  return Rational(a,b);
}

Rational Rational::divide( const Rational & val ) const
{
  int a= (numerator*val.get_denom());

  int b = (denominator*val.get_numer());

  return Rational(a,b);
}


// This function will output a Rational object to console.
// It should also go *inside* the rational class.
void Rational::print( const Rational & val ) const
{
  if (val.get_numer() == val.get_denom() )
  {
    cout << 1 <<endl;
  }
  else
    {
      cout <<val.get_numer()<< "/" << val.get_denom() << endl;
    }
}

