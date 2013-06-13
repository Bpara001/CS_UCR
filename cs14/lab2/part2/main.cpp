#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{

    if(argc != 2)
    {
        cerr << "Usage error: expected <excutable> <input file>" << endl;
        exit(1);
    }

	ifstream infile;
	infile.open(argv[1]);
	string txt;

	if(!infile)
	{
	    cerr << "Input file "<< argv[1] << " not found" << endl;
	}

	while(infile)
	{
	    getline(infile,txt);
	    cout << txt << endl;
	}

	infile.close();

	return 0;
}
