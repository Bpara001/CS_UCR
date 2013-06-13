////////////////////////////////////////////
/*
Names: Chris Wong, Hans Wun
Login: wongc, wunh
Email: cwong030@ucr.edu, wunh001@ucr.edu
Lb Section: 022
Assignment: Lab 7
I acknowledge all content is original.
*/
///////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

/**
Converts the integer to a binary number/string
Parameters: insert the integer number to convert, and the
length of the binary num
*/
string ConvertToBin(int n,int length) {
    string s;       //declare the return string
	for(int i = 0; i < length; i++) { //logic for converting to binary
		int temp = n & 0x1; //set temp
		n >>= 1; //shift the number
		s = temp == 0 ? s.insert(0,"0") : s.insert(0,"1");//set string
	}
	return s;   //return s
}


/**
Main function
Creates the mux depending on user input from the terminal
*/
int main() {

    //Get the user input: num of inputs
	int inputs;
	cout << "Type the number of inputs for mux: "; cin >> inputs;

    //Declare string stream, and output stream
	stringstream ss; ss << inputs;
	string filename = "mux_" + ss.str(); //decare name of file
	ofstream myout((filename + ".vhd").c_str());

	//Declare headers
	myout <<"--##############################\n"
    <<"--Names: Hans Wun, Chris Wong\n"
    <<"--Login: wunh, wongc\n"
    <<"--Email: hwun001@ucr.edu, wongc@cs.ucr.edu\n"
    <<"--Lab Section: 022\n"
    <<"--Assignment: Lab 7\n"
    <<"--I acknowledge all content is original.\n"
    <<"--##############################\n"
    << endl;

    //Declare all the libararies that are needed
	myout << "library IEEE;\n"
	<<"use IEEE.STD_LOGIC_1164.ALL;\n"
	<<"use IEEE.STD_LOGIC_ARITH.ALL;\n"
	<<"use IEEE.STD_LOGIC_UNSIGNED.ALL;\n"
    << endl;

	//Output all the entity stuff (port map, etc)
	int sel = int(ceil(log(inputs)/log(2)));
	myout << "entity" << " " << filename << " is \n"
    << "\tport(\n"
	<< "\tsel : in std_logic_vector( " << sel - 1 << " downto 0 );\n"
	<< "\tinput : in std_logic_vector(" << inputs - 1 << " downto 0);\n"
	<< "\toutput : out std_logic\n\t);\n"
    << "end " << filename << ";\n"
    << endl;

	//Output all the Architecture stuff
	myout << "architecture behavior of " << filename << " is\n"
    << "begin\n"
    << "\twith sel select output <="
    << endl;

    //Create selector lines
	for (unsigned i = 0;i < inputs-1;i++) {
		myout << "\t\tinput(" << i <<") when "<<"\""<<ConvertToBin(i,sel)
		<< "\","
		<< endl;
	}

    //create the last selector line
	myout << "\t\tinput(" << inputs-1 << ") when others;\n"
	<< "end behavior;"
    << endl;

    //close the stream, kill program
	myout.close();
	return 0;
}
