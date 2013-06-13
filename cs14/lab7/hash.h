#ifndef __HASH_H__
#define __HASH_H__

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Hash
{

private:

	list<string> data[HASH_TABLE_SIZE];
	int collision_count;
	int longest;

public:
	Hash()
	{
		collision_count = 0;
		longest = 0;
	}

	// This is only a sample hash function (and a bad one at that). You will
	// need to comment out the contents of this hash function and add your own
	// hash function

	int hf(string ins)
	{
		 // place your hash function here...
		//return( ((int) ins[0]) + (32*(int) ins[1]) + (32* (32) *(int) ins[2]))  % HASH_TABLE_SIZE;
	   //return ( ((int) ins[0]) + ((int) ins[1]) + ((int) ins[1])) % HASH_TABLE_SIZE;

		//USED FOR THE first PART OF THE LAB.
		//return ( (int) ins[0] ) % HASH_TABLE_SIZE;
		return 1;
	}

	void print()
	{
		data[0].pop_back();
		cout << "LINE [0] REMOVING extra line\n" << endl;
		for(int i = 0; i < HASH_TABLE_SIZE; i++)
		{
			int longest_temp = 0;
			cout << i << ": ";
			while(!data[i].empty())
			{
				cout << data[i].front() << ", ";
				data[i].pop_front();
				longest_temp++;
				if(longest < longest_temp)
					longest = longest_temp;
			}
			cout << endl;
		}
	}

	void processFile(string filename)
	{
		ifstream infile;
		infile.open(filename.c_str());
		while(infile)
		{
			string key;
			getline(infile,key);

			int loc = hf(key);

			if(!data[loc].empty())
				collision_count++;
			data[loc].push_back(key);

			cout << "LINE [" << loc << "] ADDING to element: \"" << key << "\"" << endl;
		}
	}

	void printStats()
	{
		cout <<"Number of collisions: " << collision_count-1 << endl;
		cout << "Length of longest list: " << longest << endl;
	}
};

#endif
