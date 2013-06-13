#include <vector>
#include <iostream>

using std::vector;
using std::ostream;

// This function will allow you to use the << operator to print
// out a vector.
// Example: vector<int> v; v.push_back(5); v.push_back(4); cout << v;
// Output : [5] [4]
template <class T>
ostream& operator<<(ostream& out, vector<T>& v)
{
    for( unsigned int i = 0; i < v.size(); i++ )
        if( i < v.size()-1 )
            out << '[' << v[i] << "] ";
        else
            out << '[' << v[i] << ']';
    return out;
}


