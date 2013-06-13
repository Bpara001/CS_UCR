#include <iostream>
using namespace std;

class Custom
{

private:
    string sentence;
    int number;


public:

Custom()
:sentence(""),number(0)
{}

Custom(string s)
:sentence(s),number(0)
{}

Custom(int n)
:sentence(""),number(n)
{}

Custom(string s, int n)
:sentence(s),number(n)
{}


};
