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

#ifndef __WordLadder_H__
#define __WordLadder_H__

#include "StackQueue.H"
#include <fstream>
#include <vector>
using namespace std;

class WordLadder
{

private:
	string dictionary[9800];
	int dictionary_size;

	//Helper Functions
	bool letter_diff(string a, string b)
	{
		int letter_difference = 0;
		for(unsigned int i = 0; i < a.size(); i++)
		{
			if((a.substr(i,1)) != (b.substr(i,1)))
			{
				letter_difference++;
			}
		}
		if(letter_difference == 1)
			return true;
		else
			return false;
	}

public:
   //!Constructor that passes in the name of the dictionary file.
	WordLadder( const string &listFile )
	{
		dictionary_size = 3800;
		ifstream infile;
		infile.open(listFile.c_str());
		int count_size = 0;

		if(infile.fail())
		{
			cerr <<"cannot open \""<<listFile<<" \"; file does not exist" << endl;
			exit(1);
		}

		while(infile)
		{
			getline(infile,dictionary[count_size]);
			count_size++;
		}

		infile.close();
	}

	//!Passes in the start and end words and outputs to standard
	//!output the word ladder.
   void outputLadder( const string &start, const string &end )
   {
   	//Check#1, make sure words are not the same
   	if(start == end)
   	{
   		cout << start << " -> " << end << endl;
   		cout << end<<"("<<end<<" is both the start word and end word)"<<endl;
   		return;
   	}

   	//Check#2, make sure words are exactly 5-Letters long
   	if(start.size() != 5 || end.size() != 5)
   	{
   		cerr <<"Please enter a 5-Letter word only!" << endl;
   		return;
   	}

   	//Check#3, make sure the words exist in the dictionary
   	bool start_exists = false;
   	bool end_exists = false;
   	for(int i = 0; i < dictionary_size; i++)
   	{
   		if(dictionary[i] == start)
   			start_exists = true;
   		if(dictionary[i] == end)
				end_exists = true;
   	}
   	if((!start_exists) || (!end_exists))
   	{
   		if(!start_exists)
   			cout << start<<" does not exist in the inputed dictionary."<<endl;
   		if(!end_exists)
   			cout << end<<" does not exist in the inputed dictionary."<<endl;
   		cout <<"Please input valid words." << endl;
   		return;
   	}

   	//If words are valid, we begin the search!!
   	//Create a String of stacks, Queue of Stacks, and array of strings
   	//If a valid word is found, it is check against the words in the array
   	//If the word is still valid, it is inserted onto the array

   	StringStack stack(start);
   	StackQueue queue(stack);
   	string used[5000];
   	used[0] = start;
   	int count = 1;

   	cout << "loading...\n" << endl;
   	while(!queue.is_empty())
   	{
   		for(int i = 0; i < dictionary_size; i++)
   	   {
   	   	if(letter_diff(dictionary[i], queue.get_front().get_top()))
   	   	{
   	   		bool repeat = false;
   	   		if(dictionary[i] == end)
   	   		{
   	   			cout << "WORD LADDER OF: "<< start << " -> " << end << endl;
   	   			StringStack answer_reverse =queue.get_front().copy_reverse();
						answer_reverse.print();
						cout << end;
   	   			return;
   	   		}

   	   		for(int j = 0; j < 1000; j++)
   	   		{
   	   			if(dictionary[i] == used[j])
   	   				repeat = true;
   	   		}

   	   		if(!repeat)
   	   		{
   	   			StringStack copy = queue.get_front();
   	   		   copy.push(dictionary[i]);
   	   			queue.enqueue(copy);
   	   			count++;
   	   			used[count] = dictionary[i];
   	   		}
   	   	}
   	   }
   		queue.dequeue();
   	}
   	cout << "I'm sorry, the word ladder could not be found" << endl;
   }
};

#endif
