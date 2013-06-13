/* Course: CS 170 fall quarter , 2012

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Project 1

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//node.h


#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <vector>
#include <math.h>
#include <functional>


using namespace std;

class Node {

    public:

    //pointers to array position (b/c i dont like actual pointers)
    int parent;       //pointer to the parent node
    int moveup;       //pointer to the up node
    int movedown;     //pointer to the down node
    int moveright;    //pointer to the right node
    int moveleft;     //pointer to the left node

    //data stuff
    int depth;        //depth of the node
    string path;      //path taken to get the node
    int i;            //position of the node in the vector
    int misplaced;    //number of misplaced tiles
    int fn;          //calculated heurstic f(n)
    int tile_pos;    //postion of the '0' or blank tile in the vector
    int hn;
    int manhattan;

    vector<int> data;  //vector containing the data


    //Defualt constructor
     Node()
    :parent(-1),moveup(-1),movedown(-1),moveright(-1),moveleft(-1),depth(0),path(""),i(0),misplaced(0),fn(0),tile_pos(0),hn(0)
    {}

    //Constructor with parameters
    Node(vector<int> v,int p,int dep,string pat,int ai,int pathtype = 0)
    :parent(p),moveup(-1),movedown(-1),moveright(-1),moveleft(-1),data(v),depth(dep),path(pat),i(ai),hn(0)
    {

        //check to see if its the goal state
        misplaced = v.size();
        for(int i = 0; i <  v.size(); i++){
            if(i == v.size() -1 && 0 == v[i] ) misplaced--; //if the blank tile is in the right place
            else if(i != v.size() - 1 && i + 1 ==  v[i]) misplaced--; //if the other tile is in the right place
        }


        //calculate the misplaced tile position
        tile_pos = 0;
        for(int i = 0; i < v.size(); i++) if(v[i] == 0) tile_pos = i;

        //if applicable, check manhatten distance
        int hn2 = 0;
        if(pathtype == 3){

            int w = int(floor(sqrt(v.size()))); //calculate the width or length
            for(int i = 0; i < v.size(); i++){
                //if(i == v.size() -1 && 0 == v[i]) {} //if the blank tile is in the right place
                if(i != v.size() - 1 && i + 1 ==  v[i]) {} //if the other tile is in the right place
                else if( v[i] == 0) {} //if moving tile, ignore
                else{
                    int real_y = (v[i]-1) / w;                      //calculate where the real position of v[i] should be
                    int real_x = (v[i]-1) - (real_y*w) ;
                    int current_y = (i) / w;                        //calculate the current cooredinates
                    int current_x = (i)  - (current_y*w);
                    if(v[i] == 0){real_y = w-1; real_x = w-1;}
                    hn2 += (abs(current_x-real_x) + abs(current_y-real_y)); //add to hn
                }
            }
            manhattan = hn2;
        }

        //calculate fn
        if(pathtype == 1) fn = depth;
        else if(pathtype == 2) {fn = misplaced + depth; hn = misplaced;}
        else if(pathtype == 3) {fn = hn2 + depth; hn = hn2;}
    }



    //Prints the contents of the node;
    void printdata(){

        //Output it to the console
        for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";

        //Output newline character when necessary
        if( (i+1) % int (floor(sqrt(data.size()))) == 0 && i != 0)
            cout << endl;
        }
    }

};


//Overload the < operator (for STL priority queue usage)
bool operator< (const Node& lhs, const Node &rhs) {return lhs.fn > rhs.fn;}
//Overload the > operator (for STL priority queue usage)
bool operator> (const Node& lhs, const Node &rhs) {return lhs.fn < rhs.fn;}


#endif
