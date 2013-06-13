#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string>words;
    bool more = true;
    int i;
    string done = "done";

    cout << "Enter words (enter the word 'done' to quit)" << endl;
    while(more)
    {
        string s;
        cin >> s;
        if(s == done)
        {
            more = false;
        }
        else
        {
            words.push_back(s);
        }
    }


    cout <<"Enter a Letter: ";
    string letterchoice;
    cin >> letterchoice;
    cout <<"Words that start with " << letterchoice <<": ";

    for (i = 0; i < words.size(); i++)
    {
        string letter = words[i].substr(0,1);
        if (letterchoice == letter)
        {
            cout << words[i] << " ";
        }
    }
cout << endl;


    return 0;
}
