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
	if(argc != 3)
	{
		cerr<<"\nUsage error: startword endword < dictionaryfile " << endl;
		exit(1);
	}

    //check for identical words
	if(argv[1] == argv[2])
	{
	    cout << "Start and End words are identical\n"
	    << argv[1] << "\n" << argv[2] << "\n" << "program terminated" <<endl;
	    return 0;
	}

    //create a dictionary, check if user inputs are contained
    Dictionary dictionary;
    dictionary.read();

    if(!dictionary.contains(argv[1]) || !dictionary.contains(argv[2]))
    {
        cout << "Inputs are not contained in dictionary" << endl;
        exit(1);
    }

    //create the wordladder 'graph',
    //switch inputs b/c wordladder outputs in reverse
    Ladder wordladder(dictionary,argv[2],argv[1]);

    //call the print function which prints the word ladder
    wordladder.print();

    //Print exit when everything is done
    cout << "\nprogram terminated" << endl;
    return 0;

}
