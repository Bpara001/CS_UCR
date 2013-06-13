#include <iostream>
#include <string>
using namespace std;

int main()
{
   int startvalue;
   int incrementvalue;
   int endvalue;

   cout <<"Input Start Value" << endl;
   cin >> startvalue;
   cout <<"Input Increment Value" << endl;
   cin >> incrementvalue;
   cout <<"Input End Value" << endl;
   cin >> endvalue;
   cout << startvalue << " ";

   while ( startvalue + incrementvalue < endvalue)
   { startvalue = startvalue + incrementvalue;
     cout << startvalue << " ";
    }


   return 0;
}

