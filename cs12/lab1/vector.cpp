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
// Assignment: Lab 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include "helpers.h"
//What else do we need to #include?


using namespace std;


// Search for an item with value equal to key in the vector and
// return the position at which it was found.
// What should you return if the key was not found?
int search(const vector<int>& v, int key)
{
   for(unsigned int i = 0; i < v.size(); i++)
   {
      if(v[i] == key)
      {
         return i;
      }
   }
   return -1;

}

// Remove the element at position loc from the vector.
// All remaining elements should be shifted forward so that there is
// no empty space in the vector and then you should decrease the size
// of the vector by 1.
// If loc is outside the range of the vector you should do nothing.
void remove(vector<int>& v, int loc)
{
   if(loc != -1)
   {
      for(unsigned int i = loc; i < v.size() -1; i++)

         v[i]=v[i+1];
         v.pop_back();
   }
}

void print(vector<int>& v)
{
    for(unsigned int i = 0; i > v.size(); i++)
    {
      cout << "{" << v[i] << "} ";
    }
 }


int main()
{
    // Create a vector and add 10 ints to it.
    vector<int>v(10);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    v[4] = 4;
    v[5] = 5;
    v[6] = 6;
    v[7] = 7;
    v[8] = 8;
    v[9] = 9;


    // Print the vector (use the helper function)
   //print(v);
    cout << v;

    // Allow the user to remove three numbers before the program ends.
    for( int i = 0; i < 3; i++ )
    {
    cout << endl << "enter a number to remove" << endl;
    int n;
    cin >> n;

    int location = search(v,n);

    remove(v,location);
    cout << "LOCATION: " << location << endl;
    cout << v;
 }
    
    return 0;
}



