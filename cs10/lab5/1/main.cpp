#include <iostream>
#include <string>
using namespace std;

int main()
{
   int number;
   cout << "Input a interger!" << endl;
   cin >> number;

   if ( number%2 == 0 )
   {
      cout << "You typed the following number: " << number <<
           "\nThis number is even\n" << endl;
   }
   else
   {
       cout << "You typed the following number: " << number <<
            "\nThis number is odd" << endl;
   }

   return 0;
}

