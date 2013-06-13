//Put inclusion guard here
#ifndef __RATIONAL_H__
#define __RATIONAL_H__
//Put needed includes here
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//This is still outside the class
int gcd( int a, int b );

//Put Rational class here, containing only function *declarations*
class Rational
{

private:
  int numerator;
  int denominator;

public:

Rational();

Rational(int y);

Rational(int y,int z);

int  get_numer() const;

int  get_denom() const;

Rational add( const Rational & val ) const;

Rational subtract( const Rational & val ) const;

Rational multiply( const Rational & val ) const;

Rational divide( const Rational & val ) const;

void print( const Rational & val ) const;

};



//end the inclusion guard
#endif
