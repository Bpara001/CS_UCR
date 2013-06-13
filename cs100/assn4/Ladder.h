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
///REQUIRES: -PQueue.h                                                  ///
///          -Vertex.h                                                  ///
///          -Dictionary.h                                              ///
///////////////////////////////////////////////////////////////////////////

#ifndef __Ladder_H__
#define __Ladder_H__

#include "PQueue.h"
#include "Vertex.h"
#include "Dictionary.h"

class Ladder
{

private:

string starting;
string end;
Dictionary dict;
PQueue pq;
vector<string> used;

//!Private logic function, find adj word
void  set_adj(Vertex &node,  Dictionary &dict)
{
    string s = node.content;
    string word;
	for (int i =0; i < s.length(); i++)
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


//!Private logic function, create a HUGE GRAPH!
void calculate
(Dictionary &dict, const string &start, const string &end,Vertex node)
{
    //dequeue a node and examine it
    pq.pop();
    set_adj(node,dict);

    //if queue is empty, return
    if(node.children.size() == 0 && pq.empty())
    {
        cout <<"Word Ladder does not exist" << endl;
        exit(1);
    }


    //if element sought is found, quit search and return
    //otherwise enqueue any succesors
    for(int i = 0; i < node.children.size(); i++)
    {
        if(node.children[i].content == end)
        {
            print_family(node.children[i]);
            cout << start << "\n";
            return;
        }
        else
            pq.push(node.children[i]);
    }
    //if queue is not empty, repeat above step
    calculate(dict,start,end,pq.front());
}

//!Private funciton, print family of specfic node
void print_family(const Vertex &node)
{
    Vertex dummy = node;
    while(dummy.parent != NULL)
    {
        cout << dummy.content << "\n";
        dummy = *dummy.parent;
    }
}

public:

//!Constructor, defualt
Ladder()
{}

//!Constructor with 1 argument
Ladder(const Dictionary &d)
:dict(d)
{}

//!Constructor with 3 argument
Ladder(const Dictionary &d,const string &s, const string &e)
:dict(d),starting(s),end(e)
{}


//!Member: Find word ladder from two strings & print
void print()
{
    Vertex root = Vertex(starting);         //set the root node
    pq.push(root);                          //push root into the priority queue
    cout << "loading...\n" << endl;         //output loading screen
    calculate(dict,starting,end,root);      //create graph && print

}

};

#endif
