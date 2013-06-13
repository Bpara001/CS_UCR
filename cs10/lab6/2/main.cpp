#include <iostream>
#include <string>
using namespace std;

int main()
{
   int riceamount = 1;
   int loop_end;
   int daynumber = 2;
   int riceincrease = 2;


   cout <<"Day 1: 1 grain of rice" << endl;

   for(loop_end = 0; loop_end < 29; ++loop_end)
   {
       riceamount = riceamount + riceincrease;
       riceincrease = riceincrease * 2;
       cout <<"Day " << daynumber << ": " << riceamount << " grains of rice" <<
              endl;
       ++daynumber;
       
    }

   return 0;
}

