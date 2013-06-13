/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn5

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

//Dijkstra.H
#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include "Containers.H"

//! Data Structure that Contains:current,previous(pr),distance(d),and edges
class Dijkstra
{
public:

	Containers current;
	int pr;
	int d;
	vector<Containers> edge;

	//Default Constructor
	Dijkstra()
	:pr(-1),d(999999),edge()
	 {
		current.set(-1,-1);
	 }

};

#endif


