/* Course: CS 170 fall quarter , 2012
 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Project 2

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//node.H

#ifndef __NODE_H__
#define __NODE_H__
#include "object.H"
#include <sstream>

class Node {

    public:
	vector<char> active;
	double cv;
	
    //Defualt Constructor
    Node()
    :cv(-1)
    {}
    
    Node(double a)
    :cv(a)
    {}
    
    //Constructor with parameters
    Node(double a, vector<char> b)
    :active(b),cv(a)
    {}
    
    //Returns a string containing the active features in this node
    string string_activef(){
		string s = "{";
		for(int i = 0; i < active.size(); i++){
			if(active[i] == 1){
				if(s.size() > 1)s += ",";
				stringstream ss;
				ss << (i+1);
				s += ss.str();
			}
		}
		return (s + "}");
	}
	
};
#endif
