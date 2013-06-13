// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// Assignment: LAB 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include <iostream>
#include <vector>

using namespace std;

vector<string> generate_subsets(string word, int index, string subs,
                                vector<string>& subsets)
{
    if(index == word.length())
        subsets.push_back(subs);
    else
    {
        subs += word[index];
        subsets = generate_subsets(word,index+1,subs,subsets);
        subs.resize(subs.length()-1);
        subsets = generate_subsets(word,index+1,subs,subsets);
    }
    return subsets;
}

int main()
{
    vector<string>subsets;
    string word = "Rercursion";
    string subs;
    generate_subsets(word,0,subs, subsets);

    for(int i = 0; i < subsets.size(); i ++)
    {
        cout << subsets[i] << " ";
    }

    return 0;
}
