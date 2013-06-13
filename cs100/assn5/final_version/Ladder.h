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
///CLASS NAME: Ladder                                                   ///
///PURPOSE: -create a giant graph starting at the start word.           ///
///         -finds the shortest word ladder from start to end           ///
///         -does not create graph until print() function is called     ///
///REQUIRES: -STL Queue                                                 ///
///          -Vertex.h                                                  ///
///          -Dictionary.h                                              ///
///////////////////////////////////////////////////////////////////////////

#ifndef __Ladder_H__
#define __Ladder_H__

#include <queue>
#include "Vertex.h"
#include "Dictionary.h"

class Ladder
{

private:
Dictionary dict;
queue<Vertex> pq;
vector<string> used;
vector<string> totalused;
bool flag;
int magic_offset;       //counter for how many sets


//!Private helper function, determines if string is present in a vector
bool vector_contains(const string &s, const vector<string> &v)
    {
        for(unsigned int i = 0; i < v.size(); i++)
            if(v[i] == s)
                return true;
        return false;
    }


//!Private logic function, find adj word
void  set_adj(Vertex &node,  const Dictionary &dict)
{
    string s = node.content;
    string word;
	for (unsigned int i =0; i < s.length(); i++)
	{
		word = s;
		//checks each char in word
		for (char ch = 'a'; ch <= 'z'; ch++)
		{
			word = word.replace(i,1,1,ch);
			//if neigboring word is found, add to adjecent list (children)
			if(dict.contains(word) && word != s &&
               find(used.begin(),used.end(),word) == used.end())
			{
			    node.children.push_back(Vertex(word));
			    node.children.back().parent = &node;
			    used.push_back(word);           // add word to used list
			}
		}
	}
}

//!Private logic function, create a HUGE GRAPH to find word ladder
void search
(const Dictionary &dict,const string &start,Vertex node)
{
    //dequeue a node and examine it
    pq.pop();
    set_adj(node,dict);

    //if queue is empty, return
    if(node.children.size() == 0 && pq.empty()) return;

    //enqueue succesors
    for(unsigned int i = 0; i < node.children.size(); i++) pq.push(node.children[i]);

    //if queue is not empty, repeat above step
    search(dict,start,pq.front());
}

//!Private helper funtion: create a graph of the string
void find_search(const string &a)
{
    used.clear();
    Vertex root = Vertex(a);         //set the root node
    pq.push(root);
    search(dict,a,root);

    if(!used.empty())
        magic_offset++;

//	exit(1);

    for(unsigned int i = 0; i < used.size(); i++)
        if(!vector_contains(used[i],totalused))
            totalused.push_back(used[i]);
}

public:
//!Constructor, defualt
Ladder()
{}

//!Constructor with 1 argument
Ladder(const Dictionary &d)
:dict(d),magic_offset(0)
{}


//!Member: print size of the largest set of words
//!        in which no two members have a word ladder between them
void print()
{
    cout << "Loading... Please wait(1-20seconds)" << endl;
    for(int i = 0; i < dict.size(); i++)
    if(!vector_contains(dict.data[i],totalused))
        find_search(dict.data[i]);
    cout << "\n" << "largest set size: "<<
        dict.size() - (totalused.size() - magic_offset) <<endl;
}

};

#endif
