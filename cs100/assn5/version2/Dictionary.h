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
///          -fstream                                                   ///
///          -No user made classes                                      ///
///////////////////////////////////////////////////////////////////////////

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


class Dictionary
{
private:


public:
vector<string> data;

//!Constructor: defualt, no arguments
Dictionary()
{}

//!Constructor: 1 argument
Dictionary(const string &filename)
{
    //create a file stream, shove contents of file into a vector
    ifstream file;
    file.open(filename.c_str());


    //make sure file is valid
    if(file.fail())
    {
        cerr <<"cannot open \""<<file<<" \"; file does not exist" << endl;
        exit(1);
    }

    //check each char at a time, shove string into vector
    char c;
    string s;
    while (!file.eof())
    {
        c = file.get();
        if (c == L'\t' || c == L'\n' || c == L'\r' || c == L' ')
        {
                data.push_back(s);
                s.clear();
                c = file.get();
        }
        s.push_back(c);
    }
}

//!Member: fill dictionary with user input
void read()
{
    string s;
    while(cin.peek() != EOF)        //until input is NULL, add to dictionary
    {
        cin >> s;
        data.push_back(s);
    }
}

//!Member: erase all contents of dictionary
void clear()
{
    data.clear();
}

//!Accessor: print out the dictionary
void print() const
{
    cout << "Contains: ";
    for(int i =0; i < data.size(); i++)
        cout << "[" << i << "]" << data[i] << ", ";
}


//!Accessor: return if string is in dictionary vector
bool contains(const string &s) const
{
    //using a binary search, check to see if element is in dictionary
    return (binary_search(data.begin(),data.end(),s));
}

//!Accessor: return the size of the dictionary
int size()
{
    return data.size();
}


};

#endif

