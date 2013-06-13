//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn4
// Lab section: 022
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

///////////////////////////////////////////////////////////////////////////
///CLASS NAME: Vertex                                                   ///
///PURPOSE: -creates a node                                             ///
///         -contains children, one parent, and a single string value   ///
///REQUIRES: -STL iostream, STL vector                                  ///
///          -No user made classes                                      ///
///////////////////////////////////////////////////////////////////////////


#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <iostream>
#include <vector>
using namespace std;

class Vertex
{

public:
vector<Vertex> children;
Vertex *parent;
string content;
int priority;

//!Constructor: defualt, no arguments
Vertex()
:content("")
{
    parent = NULL;
}

//!Constructor: 1 argument
Vertex(const string &s)
:content(s)
{
    parent = NULL;
}

//!Constructor: 2 arguments
Vertex(const string &s,const int &n)
:content(s),priority(n)
{
    parent = NULL;
}

//!Accessor: Print all children
void print() const
{
    cout << content << ":: ";
    for(unsigned int i = 0; i < children.size(); i++)
        cout << children[i].content << ", ";
    cout << endl;
}






};

#endif
