#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string str ("There are lots of famous applications software packages written in c++");
	

	cout << "There are lots of famous applications" 
	<< "software packages written in c++" << endl;
	
	cout << endl;
	
	cout << "What word are you looking for? " << endl;
	string str2;
	cin >> str2;
	size_t found;

	found=str.find(str2);
	if (found!=string::npos)
	  cout << "First  \"" << str2 << "\"  found at position: " << int(found) <<endl;

  return 0;
}
