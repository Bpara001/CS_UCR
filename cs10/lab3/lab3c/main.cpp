#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

cout <<"Enter a floating-point number (4 digits after the decimal point): "<< endl;
float number;
cin >> number;

	cout << fixed << setprecision(0);

	cout << left << setw(10) << number << " "
     	 << setw(10) << number << endl;
	cout << fixed << setprecision(1);
	
	cout << left << setw(10) << number << " "
     	 << setw(10) << number<< endl;
	cout << setprecision(2);

	cout << left << setw(10) << number << " "
     	 << setw(10) << number<< endl;
	cout << fixed << setprecision(3);

	cout << left << setw(10) << number << " "
     	 << setw(10) << number<< endl;
	cout << fixed << setprecision(4);

	cout << left << setw(10) << number << " "
     	 << setw(10) << number<< endl;
	cout << fixed << setprecision(5);



	






  return 0;
}
