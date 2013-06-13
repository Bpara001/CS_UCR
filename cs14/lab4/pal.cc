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

int main( int argc, char* argv[] )
{
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <input file>" << endl;
    exit(1);
  }

  ifstream ifs(argv[1]);
  if(!ifs){
    cerr << "Input file error: " << argv[1] << " file not found." << endl;
    exit(1);
  }

  Queue<char> q;
  Stack<char> s;
  char letter;
  unsigned int mismatches = 0;  // Mismatches between queue and stack
  string p;

  while (ifs >> letter)  {
      if (isalpha(letter)) {
	p += letter;
	q.push(toupper(letter));
	s.push(toupper(letter));
      }
  }

  while ((!q.empty( )) && (!s.empty( ))) {
      if (q.get_front( ) != s.get_top( ))
	++mismatches;
      q.pop( );
      s.pop( );
  }

  if (mismatches == 0)
    cout << "\"" << p  << "\"" << endl << "IS A palindrome. Cheers!" << endl;
  else
    cout << "\"" << p  << "\"" << endl << "IS NOT a palindrome. Doh!" << endl;
  return 0;
}
