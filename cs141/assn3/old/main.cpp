/* Course: CS 141

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Assignment: assn3

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

//main.cc
#include "jug.h"

using namespace std;

int main()
{

	{Jug fred( 3,   5,   4, 1, 1, 1, 1, 1, 1); 		if(fred.Solve() != 1) {cout << "Error 1\n"; }}
	{Jug fred( 3,   5,   4, 6, 5, 4, 3, 2, 1); 		if(fred.Solve() != 1) {cout << "Error 2\n"; }}
	{Jug fred( 3,   5,   4, 1, 2, 3, 4, 5, 6); 		if(fred.Solve() != 1) {cout << "Error 3\n"; }}
	{Jug fred(81, 128, 100, 1, 2, 3, 4, 5, 6); 		if(fred.Solve() != 1) {cout << "Error 4\n"; }}
	{Jug fred(81, 128, 100, 6, 5, 4, 3, 2, 1); 		if(fred.Solve() != 1) {cout << "Error 5\n"; }}
	{Jug fred( 4,   8,   6, 1, 2, 3, 4, 5, 6); 		if(fred.Solve() == 0) cout << "No Solution 6\n";
								 else cout << "Error 6\n";}



/*
    Jug fred( 999,   1000,   500, 1, 1, 1, 1, 1, 1);
    cout << "completed1"<<endl;
    if(fred.Solve() != 1) {cout << "Error 1\n"; }
*/

	cout << "\n//END OF MAIN //" << endl;

	return 0;
}
