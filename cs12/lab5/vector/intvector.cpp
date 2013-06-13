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
// Assignment: lab5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "intvector.h"
#include <iostream>
using namespace std;

//Default constructor initializes size and capacity to 0.
IntVector::IntVector()
:size(0),capacity(0),data(NULL)
{
}

// Parameterized constuctor initializes BOTH size and capacity to 's',
// and creates an array accordingly.
// All the elements in the array should be initialized to 0.
IntVector::IntVector(unsigned int s)
:size(s), capacity(s), data(new int[size])
{
    for(unsigned int i = 0; i < s; i++)
    {
        data[i] = 0;
    }

}

//Do we need a destructor?
IntVector::~IntVector()
{
    delete data;
}

//returns size
unsigned IntVector::get_size() const
{
    return size;
}

// Returns the value of the element at index.
// You should also handle the cases where the index is not valid
// (index out of bounds)
int IntVector::get(unsigned index) const
{
    if(index > size)
    {
        cout << "Index not valid" << endl;
        return -1;
    }
    else
    {
        return data[index];
    }

}

	// Sets the element at index to value.
	// You should also handle the cases where the index is not valid
	// (index out of bounds)
void IntVector::set(unsigned index, int value)
{
    if(index > size)
    {
        cout << "size not valid" << endl;
    }

    else
    {
        data[index] = value;
    }

}

	// Adds value at the end of vector.
	// push_back function should call resize
	// when size == capacity in order to double the capacity.
void IntVector::push_back(int value)
{

    if(size == capacity)
    {
        resize(1);
    }
    else
    {
        size++;
    }

    data[size - 1] = value;
}

	// Removes the element at the end of the vector and returns its value.
	// (Do you need to remove/delete anything)?
	// What happens if the array is empty?
int IntVector::pop_back()
{
    if(size == 0)
    {
        cout << "array is empty" << endl;
    }

    int temp = data[size -1];
    size--;

    return temp;
}

	// Doubles the capacity of the vector, preserving existing data.
	// Invoked by push_back when needed
void IntVector::resize(int s)
{
    int sz = size+s;
    capacity = sz* 2;
    int* temp = new int[capacity];

    for(unsigned int i = 0; i < size; ++i)
    {
        temp[i] = data[i];
    }
    size = sz;
    delete []data;
    data = temp;
}

	// Prints the elements in your vector, separated by spaces
void IntVector::print() const
{
    for(int unsigned i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
}

	// Searches the data and returns the index of first instance of value,
	// if none exists, returns -1.
int IntVector::find(int value) const
{
    for(int unsigned i = 0; i < size; i++)
    {
        if(value == data[i])
        {
            return i;
        }
    }
    return -1;

}
