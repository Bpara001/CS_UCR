#include <iostream>
#include <string>
using namespace std;

int main()
{
   int grade = 0;
   int gradeA = 0;
   int gradeB = 0;
   int gradeC = 0;
   int gradeD = 0;
   int gradeF = 0;

   while ( grade >= 0)
   { cout << "Input Grade Precentage, type -1 to finish" << endl;
     cin >> grade;
       if (grade >= 90)
       { gradeA = gradeA +1;}
       else if (grade < 89 && grade >= 80)
       {gradeB = gradeB + 1;}
       else if (grade < 79 && grade >= 70)
       {gradeC = gradeC + 1;}
       else if (grade < 69 && grade >= 60)
       {gradeD = gradeD + 1;}
       else if (grade < 50 && grade >= 0)
       {gradeF = gradeF +1;}
    }
       cout <<"Number of A's: " << gradeA << endl;
       cout <<"Number of B's: " << gradeB << endl;
       cout <<"Number of C's: " << gradeC << endl;
       cout <<"Number of D's: " << gradeD << endl;
       cout <<"Number of F's: " << gradeF << endl;


   return 0;
}

