#include <iostream>
using namespace std;


void numbers(int orginal)
{   int num1, num2, num3;
    num1 = orginal / 100;
    num2 = (orginal % 100) /10;
    num3 = orginal % 10;
    cout <<"Hundreds digit: " << num1 << "\nTens digit: " << num2 <<"\nUnit digit: "
            << num3 << endl;
}

int main()
{
    int orginal;
    cout <<"Enter an integer (0-999),input a negative number to quit"<< endl;
    cin >> orginal;

    while(orginal <= 999 && orginal >= 0)
    {
        numbers(orginal);
        cout <<"Enter another integer (0-999),input a negative number to quit"<< endl;
        cin >> orginal;
    }

    cout << "Invalid input! Try again!" << endl;

return 0;
}
