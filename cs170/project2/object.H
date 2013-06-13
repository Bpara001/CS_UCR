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
//object.h

#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>
#include <vector>
using namespace std;

class Object {

    public:
	double classnum;  		//the class number of the object
	vector<double> feature;	//all features for the object
	
    //Defualt Constructor
    Object()
    :classnum(-1)
    {}
    
    //Constructor with parameters
    Object(double name, vector<double> features)
    :classnum(name),feature(features)
    {}

};
#endif
