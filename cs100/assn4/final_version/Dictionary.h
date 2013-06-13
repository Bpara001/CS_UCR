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
///CLASS NAME: Dictionary                                               ///
///PURPOSE: -create a vector with handy member & accessor functions     ///
///         -extra functions made for word ladder purprose              ///
///REQUIRES: -STL algorithm                                             ///
///          -No user made classes                                      ///
///////////////////////////////////////////////////////////////////////////

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <iostream>
#include <algorithm>
using namespace std;


class Dictionary
{
private:
vector<string> dict;

public:


//!Constructor: defualt, no arguments
Dictionary()
{}

//!Constructor: 1 argument
Dictionary(const vector<string> &v)
:dict(v)
{}

//!Member: fill dictionary with user input
void read()
{
    string s;
    while(cin.peek() != EOF)        //until input is NULL, add to dictionary
    {
        cin >> s;
        dict.push_back(s);
    }
}

//!Member: erase all contents of dictionary
void clear()
{
    dict.clear();
}

//!Accessor: print out the dictionary
void print() const
{
    cout << "Contains: ";
    for(int i =0; i < dict.size(); i++)
        cout << dict[i] << ", ";
}


//!Accessor: return if string is in dictionary vector
bool contains(const string &s)
{
    //using a binary search, check to see if element is in dictionary
    return (binary_search(dict.begin(),dict.end(),s));
}


};

#endif

