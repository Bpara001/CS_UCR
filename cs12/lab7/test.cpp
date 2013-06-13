#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    ifstream infile;
    infile.open(argv[1]);
 //   char c;
   vector<string> txt;
  //  int i = 0;
//string str;

	//std::getline(infile,txt[0]);
	//txt[0] = str;
	//cout << txt[0];
	//cout << str;
        string s;
	while(getline(infile,s))
      txt.push_back(s);

cout << txt[0];
  


infile.close();
return 0;

}
