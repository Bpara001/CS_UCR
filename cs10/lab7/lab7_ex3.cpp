// Course: CS 10 <fall quarter, 2009>
//
// First Name: Chris
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
//
// Lecture Section: 02
// Lab Section: 026
// TA: Muzaffer Akbay
//
// Assignment: lab7_ex3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================

#include "instinct.h"
#include <iostream>

int random(int lower,int higher)
{
  int rand_num;
  rand_num = rand()%((higher-lower+1)+lower);
  return rand_num;
}

int instinct_main ()

{ 
  win.coord(-5,-5,15,15);

  srand(time(0));

  int num_circle = random(40,100); 

  for (int i = 0; i < num_circle; ++i)
    {
     
      Circle circl_e = Circle(Point(random(0,10),random(0,10)),random(1,5));
    
      for (int i = 0; i <num_circle; ++i)
	  {
	    win << circl_e;
	  }
	  win.output_buffer();
}


  return 0;
}




