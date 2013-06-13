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

//Containers.H
#include <iostream>
#ifndef __CONTAINERS_H__
#define __CONTAINERS_H__

using namespace std;

//!Creates two separate containers with one int value each;
//!Contains distance(cost) and method for solving the problem
class Containers
{
private:

	int A;
	int B;
	int A_max;
	int B_max;
	int distance;
	string method;

public:

	//////////////////////////////////////////////////////////////////
	///////////////////////// CONSTRUCTORS ///////////////////////////
	//////////////////////////////////////////////////////////////////

	//Default Constructor
	Containers()
	:A(0),B(0),A_max(0),B_max(0),distance(999999),method("")
	{
	}

	//Constructor with initial capacity values
	Containers(int max1, int max2)
	:A(0),B(0),A_max(max1),B_max(max2),distance(999999),method("")
	{
	}

	//Constructor with initial capacity values and initial values
	Containers(int max1, int max2,int a, int b)
	:A(a),B(b),A_max(max1),B_max(max2),distance(999999)
	{
	}

	//Constructor with initial capacity values and initial values
	Containers(int max1, int max2,int a, int b,int d)
	:A(a),B(b),A_max(max1),B_max(max2),distance(d)
	{
	}

	//////////////////////////////////////////////////////////////////
	//////////////////// MEMEBER FUNCTIONS ///////////////////////////
	//////////////////////////////////////////////////////////////////

	//Fills container A
	void fillA()
	{
		A = A_max;
	}

	//Fills Container B
	void fillB()
	{
		B = B_max;
	}

	//Empties Container A
	void emptyA()
	{
		A = 0;
	}

	//Empties Container B
	void emptyB()
	{
		B = 0;
	}

	//Pours A into B, B cannot exceed its capacity, any leftover will remain in A
	void pAB()
	{
		int temp1 = (A+B);
		if(temp1 > B_max)
		{
			int temp2 = temp1 - B_max;
			A = temp2;
			B = B_max;
		}
		else
		{
			A = 0;
			B = temp1;
		}
	}

	//Pours B into A, A cannot exceed its capacity, any leftover will remain in B,
	void pBA()
	{
		int temp1 = (A+B);
		if(temp1 > A_max)
		{
			int temp2 = temp1-A_max;
			B = temp2;
			A = A_max;
		}
		else
		{
			B = 0;
			A = temp1;
		}
	}

	//Empties both A and B
	void empty()
	{
		A = 0;
		B = 0;
	}

	//Set A and B values
	void set(int a, int b)
	{
		A = a;
		B = b;
	}

	//Set A,B,distance, and method values
	void set(int a, int b, int d, string m)
	{
		A = a;
		B = b;
		distance = d;
		method = m;
	}

	//Set the method of the Container
	void set_m(string m)
	{
		method = m;
	}

	//////////////////////////////////////////////////////////////////
	//////////////////// ACCESSOR FUNCTIONS ///////////////////////////
	//////////////////////////////////////////////////////////////////

	//Prints the contents of A and B into the console
	void print()
	{
		cout << "Contents: [A->" << A << ", B->" << B <<  "]";
		if(distance != 0)
			cout << " "<< distance;
		cout << endl;
	}

	//Returns weather the Containers are both empty
	bool is_empty()
	{
		return (A == 0 && B == 0);
	}

	//Returns Container A contents
	int get_A() const
	{
		return A;
	}

	//Returns Container B contents
	int get_B() const
	{
		return B;
	}

	//Returns Container A capacity
	int get_A_max() const
	{
		return A_max;
	}

	//Returns Container B capacity
	int get_B_max() const
	{
		return B_max;
	}

	//Returns Container distance
	int get_d() const
	{
		return distance;
	}

	//Returns Container method
	string get_m() const
	{
		return method;
	}

	//Determines if the compared container is identical
	bool is_same(Containers other)
	{
		return (other.get_A() == A && other.get_B() == B);
	}
};
#endif
