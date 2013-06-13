#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	cout << "Enter purchase amount: " << endl;
	double purchase;
	cin >> purchase;
	
	cout << "Enter amount received: " << endl;
	double recieved;
	cin >> recieved;

	double subt = recieved - purchase;
	
	int dollars = subt / 1;
	int quarters = (subt - dollars) / .25;
        int dimes = ((subt - dollars) - (quarters * .25)) / .1;
        int nickels = ((subt - dollars) - (quarters * .25) - (dimes * .1)) / .05;
        int pennies = ((subt - dollars) - (quarters * .25) - (dimes * .1) - (nickels * .05)) / .01;

	cout << "Total Change: $" << subt << endl;
	cout << endl;
	cout << right << fixed << setprecision(0);
	cout << setw(12) << "dollars " << dollars << endl;
	cout << setw(12) << "quarters " << quarters << endl;
	cout << setw(12) << "dimes "  << dimes << endl;
	cout << setw(12) << "nickels " << nickels << endl;
	cout << setw(12) << "pennies " << pennies << endl;




  return 0;
}
