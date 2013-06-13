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
// Assignment: LAB 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "music_collection.h"

using namespace std;

int main()
{
  //create a few Tune objects to use later on;
  Music_collection A = Music_collection(10);


  //add a few tunes to A;
  A.add_tune(Tune("tune #1"));
  A.add_tune(Tune("tune #2"));
  A.add_tune(Tune("tune #3"));

  Music_collection B(A);
  //change a Tune in B using set_tune function;
  B.set_tune(0,Tune("tune #1_changed"));

  Music_collection C;
  C = B;

  //add a Tune to B;
  B.add_tune(Tune("tune #4"));

  //change a Tune in C using set_tune function;
  C.set_tune(1,Tune("tune #2_changed"));

  //print A,B,C;
  cout << "Music_collection A: " << A << endl;
  cout << "Music_collection B: " << B << endl;
  cout << "Music_collection C: " << C << endl;

    return 0;
}
