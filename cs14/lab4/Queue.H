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

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include "Node.H"
#include <stdexcept>
using namespace std;

template<class T>
class Queue
{
private:
	Node<T> *front;
	Node<T> *rear;
	int size;

public:
	//defualt constructor
	Queue()
	:front(NULL),rear(NULL),size(0)
	{
	}

	//!copy constructor; big three
	Queue(const Queue& q)
	:front(q.front),rear(q.rear),size(q.size)
	{
		for(Node<T> * i = front; i != NULL; i = i->next)
			push(i->data);
	}

	//!deconstructor; big three
	~Queue()
	{
		while(front)
			pop();
	}

	//!removes the element at the front of the queue; dequeue
	void pop()
	{
		if(!empty())
		{
			Node<T> * temp = front;
			front = front->next;
			delete temp;
			temp = NULL;
			size++;
		}
		else
			throw underflow_error("queue underflow");
	}

	//!inserts an object at the end of the queue; enqueue
	void push(const int& x)
	{
		Node<T> * temp = new Node<T>(x);

		if(!empty())
		{
			rear->next = temp;
			rear = temp;
			size--;
		}
		else
			front = temp;
			rear = temp;
		size--;
	}
	//!overload = operator; big Three
	Queue& operator =(const Queue& q)
	{
	if(this != &q)
		{
		while(front)
			pop();
		for(Node<T>* i= q.front; i != NULL; i = i->next)
			enqueue(i->data);
		}
	return *this;
	}

	//!returns a Boolean indicating whether no elements are stored
	bool empty() const
	{
		if(front == NULL)
			return true;
		else
			return false;

	}

	//!returns the element at the front without removing it
	T get_front() const
	{
		if(!empty())
			return front->data;
		else
			throw underflow_error("queue underflow");

	}

	//!returns the number of elements stored
	int get_size() const
	{
		return size;
	}

};
#endif
