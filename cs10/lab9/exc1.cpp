#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout <<"Input 10 integers!" << endl;;
    vector<int>n(10);

    cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] >> n[5] >> n[6] >> n[7]
            >> n[8] >> n[9];

    //FORWARD
    cout <<"Forward: ";
    int i;
    for(i=0; i < 10; i++)
    {
        cout << n[i] << " ";
    }

    //REVERSE
    cout <<"\nReverse: ";
    for(i=9; i > -1; i--)
    {
        cout <<n[i] << " ";
    }

    //Greater or equal to 10
    cout <<"\nGreater or equal to 10: ";
    for(i=0; i < 10; i++)
    {
        if(n[i] >= 10)
        {
            cout << n[i] << " ";
        }
    }

    //Max number
    double highest = n[0];
    cout <<"\nMax Number: ";
    for(i=0; i < 10; i++)
    {
        if(n[i] > highest)
        {
            highest = n[i];
        }
    }
    cout << highest;
    //Min number
    double min = n[0];
    cout <<"\nMin Number: ";
        for(i=0; i < 10; i++)
    {
        if(n[i] < min)
        {
            min = n[i];
        }

    }
    cout << min << endl;



    return 0;
}

