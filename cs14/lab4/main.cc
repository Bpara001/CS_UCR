// FILE: palindrome.cpp
// Adapted from www.cs.ucr.edu/~main/chapter8/pal.cxx
// Program to test whether an input line is a palindrome. Spaces,
// punctuation, and the difference between upper- and lowercase are ignored.

#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <fstream>    // Provides ifstream
#include "Stack.H"
#include "Queue.H"
using namespace std;

int main()
{

  Queue<char> q;
  try{

	  q.pop();
  }
  catch(underflow_error& e)
  {cerr << e.what() << endl;}
  catch(...)
  {cerr << "Whoops\n" << endl;}


  return 0;

}
