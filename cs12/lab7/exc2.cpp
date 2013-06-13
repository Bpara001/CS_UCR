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
    ofstream writer;
    writer.open(argv[1]);
    string kf;
    string px;
    string py;

    cout << "Welcome to Wong's Basic Animation File Generator" << endl;

    while(true)
    {
    cout << "\nEnter a Keyframe (-1 when done): ";
    cin >> kf;
    writer << "KF: " << kf << endl;

    if(kf == "-1")
    {
        writer.clear();
        writer.close();
        return 0;
    }

    cout << "Enter x position: ";
    cin >> px;
    cout << "Enter y position: ";
    cin >> py;
    writer << "P: " << px << " " << py <<" " << endl;
    }

    writer.clear();
    writer.close();
    return 0;
}
