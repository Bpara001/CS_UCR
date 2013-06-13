//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn4
// Lab section: 022
// TA: Busra Celikkaya
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

///////////////////////////////////////////////////////////////////////////
///CLASS NAME: PQueue                                                   ///
///PURPOSE: -creates a heap-based priority queue of Vertexs             ///
///REQUIRES: -STL list                                                  ///
///          -Vertx.h                                                   ///
///////////////////////////////////////////////////////////////////////////




#ifndef __PQueue_H__
#define __PQueue_H__

#include "Vertex.h"
#include <list>

class PQueue
{

private:

list<Vertex> pq;

public:

//! Defualt Constructor
PQueue()
{}

//!Member: pop queue
void pop()
{
    pq.pop_front();
}

//!Member: push into queue
void push(Vertex v)
{
    pq.push_back(v);
}

//!Member: Clear the queue
void clear()
{
    pq.clear();
}

//!Acessor: get front value
Vertex front()
{
    return pq.front();
}

//!Acessor: Determine if queue is empty
bool empty()
{
    return pq.empty();
}

//!Acessor: return pq size
int size()
{
    return pq.size();
}


};



#endif
