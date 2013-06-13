#include <iostream>
using namespace std;



void swap(int &first, int &second)
{
int temp = first;
first = second;
second = temp;
}

void order(int &first, int &second, int &third)
{
if(first >= second & second >= third & third >= first)
    {
    int temp = third;
    third = first;
    first = temp;
    }
if(first >= second & second <=third & first >= third)
    {
    swap(first,third);
    swap(first,second);
    }
if(first <= second & second >= third & first >= third )
    {
    swap(first,third);
    swap(second,third);
    }
if(first >= second & second <= third & first <= third)
    {
    swap(first,second);
    }
if(first <= second & second >= third & first <= third)
    {
    swap(second,third);
    }
}


int main()
{


int first,second,third,fourth,fifth;

cout <<"Enter two int numbers:";
cin >> first >> second;
swap(first,second);
cout << "Swapped numbers: ";
cout << first << " " << second;


cout<<"\n\nEnter three int numbers: ";
cin >> third >> fourth >> fifth;
cout << "Acending Order numbers: ";
order(third,fourth,fifth);
cout << third << " " << fourth << " "<< fifth;




cout << endl;
cout << endl;

return 0;
}
