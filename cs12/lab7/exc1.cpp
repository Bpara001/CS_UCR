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
// Assignment: LAB 7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream infile;
    infile.open(argv[1]);
    char c;
    string txt;

    while(infile)
    {

    infile.get(c);

    if(c == '/')

        {
        infile.get(c);

            if(c =='/')
            {
            getline(infile,txt);
            cout << txt << endl;
            }
        }
    }


infile.close();
return 0;

}
