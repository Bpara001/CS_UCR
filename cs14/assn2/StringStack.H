/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn2

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

#ifndef __STRINGSTACK_H__
#define __STRINGSTACK_H__

#include <iostream>
using namespace std;

class StringStack
{
private:

public:
	int top;
	int max_size;
	string data[30];

	//! Default Constructor
	StringStack()
	:top(-1),max_size(30)
	{
	}

	//! Constructor with initial value
	StringStack(string str)
	:top(0),max_size(30)
	{
		push(str);
	}

	//! Adds a new element x at the top of the stack.
	void push(const string& x)
	{
		if(top < max_size)
		{
			top++;
			data[top] = x;
		}
		else
			cout << "ERROR; cannot STACK::push " << x <<"; stack is empty" <<endl;
	}

	//! Returns a reference to the next(top) element in the stack,
	//! if the stack is not already empty
	string& get_top()
	{
		if(is_empty())
		{
			cout << "ERROR; cannot STACK::get_top; stack is empty" << endl;
			exit(1);
		}
		else
			return data[top];
	}
	//! Removes the element on top of the stack, reducing the stack's size by 1
	//! if the stack is not already empty.
	void pop()
	{
		if(top != -1)
			top--;
		else
			cout << "ERROR; cannot STACK::pop; stack is empty" << endl;
	}

	//! Tests whether the stack size is zero.
	//! Primarily used to ensure that a pop(), top() operation is not performed
	//! on an empty instance of a stack.
	//! Returns true if the stack is empty, false otherwise.
	bool is_empty() const
	{
		if(top == -1)
			return true;
		else
			return false;
	}

	//!Prints the StringStack until it is empty
	void print()
	{
		int count = 1;
		while(!is_empty())
		{

			cout << get_top() << " ";
			pop();
			if(count % 20 == 0)
				cout << endl;
			count++;
		}
	}

	//!Returns a stack in the reverse order,
	//also pops the current stack until it is empty
	StringStack copy_reverse()
	{
		StringStack copy;
		while(!is_empty())
		{
			copy.push(get_top());
			pop();
		}
		return copy;
	}

};
#endif

