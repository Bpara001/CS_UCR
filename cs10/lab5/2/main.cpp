#include <iostream>
#include <string>
using namespace std;

int main()
{
   string choice;
   double weight;
     

   cout << "type \"moon\" or \"mars\"" << endl;
   cin >> choice;


//moon output and caluclation
   if ( choice == "moon")
   {	
        cout << "Input your weight" << endl;
  	cin >> weight;
	cout << "your weight on the moon is: " << weight * .1667 << endl;
   }


//mars output and calulation
   if (choice == "mars")
   {
        cout << "Input your weight" << endl;
  	cin >> weight;
	cout << "your weight on mars is: " << weight * .337 << endl;
   }
   
  
 return 0;
   

}
