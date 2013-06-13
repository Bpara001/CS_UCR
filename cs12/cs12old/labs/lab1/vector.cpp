#include "helpers.h"
//What else do we need to #include?


using namespace std;


// Search for an item with value equal to key in the vector and
// return the position at which it was found.
// What should you return if the key was not found?
int search(const vector<int>& v, int key)
{
   for (unsigned int i = 0; v.size(); i++)
   {
      if (v[i] == key)
	   {
	return i;
	   }
	}
return -1;	 
}

// Remove the element at position loc from the vector.
// All remaining elements should be shifted forward so that there is
// no empty space in the vector and then you should decrease the size
// of the vector by 1.
// If loc is outside the range of the vector you should do nothing.
void remove(vector<int>& v, int loc)
{

if (loc != -1)
	{
    for (unsigned int i = loc; i < v.size() -1; i++)
	  v[i] = v[i+1];
	  v.pop_back();
	}
}

int main()
{
    // Create a vector and add 10 ints to it.
    vector<int>v(10);
    cout << "enter 10 integers" << endl;

    for ( int i = 0; i < v.size(); ++i)
	{
	cin >> v[i];
	}


    // Print the vector (use the helper function)
	cout << v;
        
    // Allow the user to remove three numbers before the program ends.
    for( int i = 0; i < 3; i++ )
    {
    cout << endl << "enter a number to remove" << endl;
    int n;
    cin >> n; 
    int location = search(v,n);
    remove(v,location);
    cout << v;

        
    }

    
    return 0;
}



