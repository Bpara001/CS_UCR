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
#include <sstream>
#include <fstream>
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
Create the decoder based on user input
*/
int main() {

    //Get the user input: num of inputs
	int inputs;
	cout << "Type the Input Width for the decoder: "; cin >> inputs;

    //Declare string stream, and output stream
	stringstream ss; ss << inputs;
	string name = "decoder_" + ss.str( );
	ofstream myout( (name + ".vhd").c_str( ) );

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
    << "use IEEE.STD_LOGIC_1164.ALL;\n"
    << "use IEEE.STD_LOGIC_ARITH.ALL;\n"
    << "use IEEE.STD_LOGIC_UNSIGNED.ALL;\n"
    << endl;

	//Output all the entity stuff (port map, etc)
	int outsize= int(pow(2.0,inputs));
	string binNum = ConvertToBin(1,outsize);
	myout << "entity " << name << " is\n"
	<< "\tport( \n"
	<< "\tinput : in std_logic_vector(" << inputs- 1 << " downto 0);\n"
	<< "\toutput : out std_logic_vector( "<< outsize-1 <<" downto 0)\n\t);\n"
    << "end " << name << ";\n"
    << endl;

	//Output all the Architecture stuff
	myout << "architecture behavior of " << name << " is\nbegin\n"
    << "\t with input select output <="
    << endl;

    //map each decoder input
	for (int i = 0;i < outsize - 1;i++) {
        myout << "\t\t\"" << binNum
	    << "\" when \"" << ConvertToBin(i,inputs) << "\","
	    << endl;
	    binNum = binNum.substr(1); binNum = binNum.insert(binNum.length(),"0");
	}

    //create the last line
	myout << "\t\t\"" << binNum << "\" when others;\n"
	<< "end behavior;\n"
	<< endl;

    //close the stream, kill program
	myout.close();
	return 0;
}
