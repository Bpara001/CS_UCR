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
// Assignment: LAB 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "music_collection.h"
using namespace std;



// default value of max is a conservative 100
Music_collection::Music_collection()
:number(0),max(100),collection(NULL)
{
}

// sets max to n
Music_collection::Music_collection(int n )
:number(0),max(n), collection(new Tune[max])
{
}

// overloaded copy constructor
Music_collection::Music_collection( const Music_collection& m)
: number(m.number), max(m.max), collection(new Tune[max])
{

    for(int i = 0; i < max; i++)
    {
        this->collection[i] = m.collection[i];
    }
}

// returns true if add was successful, false if not enough room to add
bool Music_collection::add_tune( const Tune& t )
{
    if(number < max)
    {
        collection[number] = t;
        number++;
        return true;
    }
    else
    {
        return false;
    }

}

// sets the Tune at position index in collection to t, returns true if index<number
bool Music_collection::set_tune( int index, const Tune& t )
{
    if(index < max)
    {
        collection[index] = t;
        return true;
    }
    else
    {
        return false;
    }
}

// overloaded assignment operator
Music_collection& Music_collection::operator=( const Music_collection& m )
{
    if(this == &m) return *this;

    delete [] this->collection;

    this->max = m.max;
    this->number = m.number;
    this->collection = new Tune[max];

    for(int i = 0; i < max; i++)
    {
        this->collection[i] = m.collection[i];
    }

    return *this;
}
// Destructor
Music_collection::~Music_collection()
{
    delete [] collection;
}

// overloaded stream insertion operator
ostream& operator << (ostream& out, const Music_collection& m )
{
    for(int i = 0; i < m.number; i++)
    {
        out << m.collection[i].get_title() << ", ";
    }
    return out;

}

