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

#ifndef __STACKQUEUE_H__
#define __STACKQUEUE_H__

#include "StackNode.H"
using namespace std;

class StackQueue
{
private:
	StackNode *front;
	StackNode *rear;
	int size;

public:
	//defualt constructor
	StackQueue()
	:front(NULL),rear(NULL),size(0)
	{
	}

	//constructor with initial value
	StackQueue(StringStack stack)
	:front(NULL),rear(NULL),size(0)
	{
		enqueue(stack);
	}

	//!copy constructor; big three
	StackQueue(const StackQueue& q)
	:front(q.front),rear(q.rear),size(q.size)
	{
		for(StackNode * i = front; i != NULL; i = i->next)
			enqueue(i->data);
	}

	//!deconstructor; big three
	~StackQueue()
	{
		while(front)
			dequeue();
	}

	//!removes the element at the front of the queue; pop_front()
	void dequeue()
	{
		if(!is_empty())
		{
			StackNode * temp = front;
			front = front->next;
			delete temp;
			temp = NULL;
			size--;
		}
		else
			cout <<"ERROR; cannot QUEUE::dequeue; queue is empty" << endl;
	}

	//!inserts an object at the end of the queue; push_back(string x)
	void enqueue(const StringStack& x)
	{
		StackNode * temp = new StackNode(x);


		if(!is_empty())
		{
			rear->next = temp;
			rear = temp;
			size++;
		}
		else
			front = temp;
			rear = temp;
		size++;
	}


	//!returns a Boolean indicating whether no elements are stored
	bool is_empty() const
	{
		if(front == NULL)
			return true;
		else
			return false;

	}

	//!returns the element at the front without removing it
	StringStack get_front()
	{
		if(is_empty())
		{
			cout << "ERROR; cannot QUEUE::get_front, queue is empty" << endl;
			exit(1);
		}
		else
			return front->data;
	}

	//!returns the number of elements stored
	int get_size() const
	{
		return size;
	}

	//!overload = operator; big Three
	StackQueue& operator =(const StackQueue& q)
	{
	if(this != &q)
		{
		while(front)
			dequeue();
		for(StackNode* i= q.front; i != NULL; i = i->next)
			enqueue(i->data);
		}
	return *this;
	}

};
#endif

