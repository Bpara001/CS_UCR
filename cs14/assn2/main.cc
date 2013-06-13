/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn2

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */
#include <fstream>
#include "WordLadder.H"
using namespace std;


//main function
int main(int argc, char ** argv)
{

	cout << endl;
	//Check for correct input
	if(argc != 4)
	{
		cerr<<"Usage error: expected <executable> <dictionary> <5_letter_word> "
				 << "5_letter_word>" << endl;
		exit(1);
	}
	else
	{

	WordLadder(argv[1]).outputLadder(argv[2],argv[3]);
	cout << "\n\n//end of program..." << endl;
	cout << endl;
	return 0;
	}
}

