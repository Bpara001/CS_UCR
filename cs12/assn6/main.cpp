

//!CHRISTOPHER WONG AND CHRISTOPHER DOHI ARE WORKING TOGETHER ON THIS ASSN.
///////////////////////////////////////
// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// First Name(partner): Christopher
// Last Name(partner): Dohi
// Login id(partner): dohic
// email address(partner): cdohi001@student.ucr.edu
// Student id: 860 932 007
// Lecture Section: 002
// Lab Section: 024
// TA: Nkenge
//
// Assignment: assn6
//
// WE hereby certify that the code in this file
// is ENTIRELY our own original work.
//! BOTH STUDENTS COLLBORATED TOGETHER FOR EACH FUNCTION AND IMPLEMENTATION
//! WE BOTH SAT INFRONT OF ONE COMPUTER CODING EACH LINE BY LINE TOGETHER
//========================================================================


#include "textviewer.h"
#include "instinct.h"

using namespace std;

int instinct_main()
{
  win.coord(0,0,100,100);

  TextViewer file("text_files/hamlet_act1_scene1.txt");
  file.view();

  file.setFile("text_files/dec_independence.txt");
  file.view();

  file.setFile("non_existent.txt");
  file.view();

  return 0;
}
