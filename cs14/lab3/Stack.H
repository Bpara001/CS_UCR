#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Stack
{
private:

int top;
int max_size;
T stack[100];

public:

//! Default Constructor
Stack()
:top(-1),max_size(10)
{
}


//! Adds a new element x at the top of the stack.
void push(const T& x)
{
	assert(top < max_size);
	top++;
	stack[top] = x;
}

//! Returns a reference to the next(top) element in the stack,
//! if the stack is not already empty
T& get_top()
{
	assert(!empty());
	return stack[top];
}

//! Removes the element on top of the stack, reducing the stack's size by 1
//! if the stack is not already empty.
void pop()
{
	assert(top != -1);
	top--;
}

//! Tests whether the stack size is zero.
//! Primarily used to ensure that a pop(), top() operation is not performed
//! on an empty instance of a stack.
//! Returns true if the stack is empty, false otherwise.
bool empty() const
{
	if(top == -1)
		return true;
	else
		return false;

}

};
#endif
