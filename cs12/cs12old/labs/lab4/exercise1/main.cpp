#include <iostream>

using namespace std;


void read_data(int a[], int a_capacity)
{
   for (int i = 0; i < a_capacity; i++)
   {
       cout << "Enter the integers!" << endl;
       cin >> a[i];
    }

}



int highest(int a[], int a_capacity)
{
/*
 int highest = 0;
 if (a_capacity > 0)
  {
  highest = a[0];
  int i;
      for (i = 1; i < a_capacity; i++)
           if (a[i] > highest)
     	   {
           highest =  a[i];      
           }
  }
*/

int highest = a[0];
for (int i = 1; i < a_capacity; ++i)
  	if (a[i] > highest)
	{
	highest = a[i];
	}

return highest;

}

void print(int a[], int a_capacity,int highest)
{
   for (int i = 0; i < a_capacity; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
   cout << highest << endl;
}


int main()
{
   cout << "Input the number of arrays you want!" << endl;
   int capacity;
   cin >> capacity;

   int* array = new int[capacity];
   read_data(array, capacity);
   int highest_number = highest(array,capacity);
   print(array,capacity,highest_number);
   delete array;   
   return 0;
}

