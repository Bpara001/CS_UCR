#include "Stack.H"
#include <fstream>

int main(int argc, char ** argv )
{
	//READING a txt file and outputing everything in reverse
	cout << "===========BASIC STACK===========" << endl;
	Stack<int> stack_double;
	for(int i = 0; i < 5; i ++)
	{
		int number = (i * 4) + 3;
		stack_double.push(number);
		cout << "Pushing INT: " <<  number << endl;
	}

	while(!stack_double.empty())
	{
		cout << "Top is: "<< stack_double.get_top() << endl;
		cout << "*POPPING STACK" << endl;
		stack_double.pop();
	}

	//READING a txt file and outputing everything in reverse
	cout << "\n===========DEMOSTRATING READING TXT FILE===========" << endl;
	ifstream infile;
	Stack<string> stack_string;
	infile.open(argv[1]);
	string input = "void";
	while(infile)
	{
		getline(infile,input);
		stack_string.push(input);
		cout << "Pushing string: " << input << endl;
	}

	while(!stack_string.empty())
	{
		cout << "Top is: "<< stack_string.get_top() << endl;
		cout << "POPPING STACK" << endl;
		stack_string.pop();
	}

	infile.close();

	//POSTFIX
	cout << "\n\n===========DEMOSTRATING POST FIX===========" << endl;
	/*
	string p = "6 5 2 3 + 8 * + 3 + *";
	Stack<int> S;
	for(unsigned int i = 0; i < p.size(); i++)
	{
		string s = p.substr(i,1);
		if(s != "+" && s != "*")
				S.push(atoi(s.c_str()));
		else
		{
			if(S.empty())
				cout << "ERROR#1" << endl;
			else
			{
				string b = S.get_top();
				S.pop();

				if(S.empty())
					cout << "ERROR#2" << endl;
				else
				{
					string a = S.get_top();
					S.pop();
					string c = a + s + b;
					S.push(c);
				}
			}
		}

		string v = S.get_top();
		S.pop();

		if(!S.empty())
			cout << "ERROR#3" << endl;
		else
			cout << v ;
	}


	cout << "\n\n////////////////END OF MAIN///////////////////" << endl;
	return 0;
	*/
}


/*
 *
 * Stack.h
 *
 * Stack s; // non-templatied version
 * Stack<int> si; // template
 * Stack<string> ss; //" "
 *
 *typedef int T;
 *template <class T>
 *tclass Stack
 */
