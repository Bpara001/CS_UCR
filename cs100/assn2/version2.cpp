#include <iostream>
#include <vector>




inline std::vector<std::string>
split( const std::string s, const std::string pat )
// Returns the vector of fragments (substrings) obtained by
// splitting s at occurrences of pat. Use C++’s string::find.
// If s begins with an occurrence of pat, it has an empty-string
// fragment. Similarly for trailing occurrences of pat. After each
// occurrence of pat, scanning resumes at the following character,
// if any.
/*
if string is "inline function"
-if pat is "fun" -> "inline", "cition"
-if pat is "in"  -> "", "l", "e function"
-if pat is "n"   -> "i", "li", "e fu", "ctio" ,""
*/
{
//declare vectors and variables
    std::vector<std::string> stringvec;
    std::vector<int> posvec;
    int pos = 0;
    int postemp = 0;

//get the position of each instance of the pat
    posvec.push_back((0));
    while(s.find(pat,pos) != -1)
    {
        posvec.push_back(s.find(pat,pos) + pat.size());
        postemp = s.find(pat,pos);
        pos = postemp + pat.size();
    }

//calculate the string and add to vector
    for(int i = 0; i < posvec.size(); i++)
    {
        pos = posvec[i+1] - posvec[i] - pat.size();
        stringvec.push_back(s.substr(posvec[i],pos));
    }

//return newly created vector
    return stringvec;
}

inline std::string
join(const std::vector<std::string> v, const std::string pat, int start, int n)
// Joins members of v separated by occurrences of pat into a single
// string and returns it. The value of start is the index of the
// first member to be joined, and n bounds the number of members to
// be joined; a value of -1 indicates that all members from start to
// the end of v should be joined
{

//Error check: make sure n is not more then vector size
    if(n > v.size())
    {
        std::cout <<"\nERROR:inline string join: n is greater then vector size\n";
        return 0;
    }

//check: if n is -1, transfers through entire vector
    if(n == -1)
        n = v.size();

//create a string adding vector and pat information
    std::string s = "";
    for(int i = start; i < n; i++)
    {
        s += v[i];
        if((i+1) < v.size())
            s += pat;
    }
//return newly created string
return s;
}

int main()
{
std::vector<std::string> v;
std::string s;


//TEST SPLIT

v = split("inline function","n");

for(int i = 0; i < v.size(); i++)
    std::cout << "'" << v[i] << "', ";


//TEST JOIN
std::cout << std::endl;
v.clear();
v.push_back("m");
v.push_back("ss");
v.push_back("ss");
v.push_back("pp");
v.push_back("");
s = join(v,"i",0,4);
std::cout << s;

std::cout << "\n///End Program///\n";
return 0;
}
