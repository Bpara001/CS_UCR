#include "hash.h"
using namespace std;


///REMEMBER TO SPECIFY THE "HASH_TABLE_SIZE"
///ex, $g++ -D HASH_TABLE_SIZE=10 *.cc

int main(int argc, char ** argv)
{

	cout << "HI WORLD";
	cout << endl;
	//Check for correct input
	if(argc != 2)
	{
		cerr<<"Usage error: expected <executable> <file> "<< endl;
		exit(1);
	}

	Hash h;

	h.processFile(argv[1]);
	h.print();
	h.printStats();
	cout << "//End of Main" << endl;
	return 0;
}
