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

#include "Ladder.h"

//!////////////////////////////
//!/// MAIN FUNCTION //////////
//!////////////////////////////
int main(int argc, char ** argv)
{
	//Check for correct input
	if(argc != 2)
	{
		cerr<<"\nUsage error: input dictionaryfile name!" << endl;
		exit(1);
	}

    //create a dictionary, check if user inputs are contained
    Dictionary dictionary(argv[1]);
    //create the wordladder 'graph',
    Ladder wordladder(dictionary);
    //call the print function which prints the answer to the assn problem
    wordladder.print();
    //Print exit when everything is done
    cout << "\nprogram terminated" << endl;
    return 0;

}
