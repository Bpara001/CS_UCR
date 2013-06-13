#include "main.H"
using namespace std;


void print(vector<string> vec)
{
    for(int i=0;i<vec.size();i++)
        cout << "\""<< vec[i] << "\", ";
}

void split_test(string s, string pat)
{
    cout <<"-if pat is \"" << pat<< "\" -> ";
    vector<string> vec_s = split(s, pat);
    print(vec_s);
    cout << endl;
}


int main()
{

/////////////////////
/////TEST SPLIT//////
/////////////////////
    string string_vec_s = "inline function";

    cout <<"\nTesting Split function\n";
    cout << "if string is \"" << string_vec_s << "\"\n";
    split_test(string_vec_s,"fun");
    split_test(string_vec_s,"in");
    split_test(string_vec_s,"n");
    cout << endl;

/////////////////////
/////TEST JOIN///////
/////////////////////
    string s;
    vector<string> vec;
    vec.push_back("M");
    vec.push_back("ss");
    vec.push_back("ss");
    vec.push_back("pp");
    vec.push_back("");


    cout << "Testing join function\n";
    s = join(vec,"i"); cout << s << endl;
    s = join(vec,"i",0,2); cout << s << endl;
    s = join(vec,"i",0,1); cout << s << endl;


    cout << endl;
     return 0;
}
