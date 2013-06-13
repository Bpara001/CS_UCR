/* Course: CS 141

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Assignment: assn3

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

//Vertex.H
#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <list>
#include <vector>
#include "Containers.H"

using namespace std;

//Creates a Vertex for the Graph
class Vertex {
public:

	Containers data;
	vector<Containers> neighbors;

	//Default Constructor
	Vertex()
	:data()
	{
	}

	//Constructor with 2 values
	Vertex(int max_a, int max_b )
	:data(max_a,max_b)
	 {
	 }

	//Constructor with 4 values
	Vertex(int max_a, int max_b, int a, int b )
	:data(max_a,max_b,a,b)
	 {
	 }

	//DeConstructor
	~Vertex()
	{
	}
};

#endif
