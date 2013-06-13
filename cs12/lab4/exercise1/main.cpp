#include <iostream>
using namespace std;

void dynamic_array(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout <<"Input an integer for spot #" << i + 1 <<": ";
        cin >> array[i];
    }
}


void print_array(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout <<"dynamic array spot #" << i+1 << ": " << array[i] << endl;
    }
}

int greatest(int array[], int size)
{
    int greatest = array[0];

    for(int i = 1; i < size; i++)
    {
        if(array[i] > greatest)
        {
            greatest = array[i];
        }
    }
    return greatest;
}



int main()
{

int size = 0;
cout <<"Enter the size of the array: ";
cin >> size;

int* array = new int[size];
dynamic_array(array,size);
int greatest_num = greatest(array,size);
cout <<"===========================================" << endl;
print_array(array,size);
cout <<"Greatest int of the dynamic array: " << greatest_num << endl;

delete array;
array = NULL;

return 0;
}

