#include <iostream>
#include <string>
using namespace std;

int main()
{
   int integer1;
   int integer2;
   int sum = 0;


   cout <<"Input frist integer!" << endl;
   cin >> integer1;
   cout <<"Input second integer!" << endl;
   cin >> integer2;

   while (integer1 > integer2)
   { cout << "Please renter the values!" << endl;

   cout <<"Input frist integer!" << endl;
   cin >> integer1;
   cout <<"Input second integer!" << endl;
   cin >> integer2;
   }

if (integer1 < integer2)
   {
   cout << integer1;
   while (integer1 < integer2)
        {
        sum = sum + integer1;
        ++integer1;
        cout <<" + " << integer1;
        }
   cout << " = " << sum + integer1 << endl;
   }
   return 0;
}

