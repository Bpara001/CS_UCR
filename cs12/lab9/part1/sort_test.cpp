// Course: CS 12 spring quarter , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 002
// Lab Section: 023
// TA: A. Muzo
//
// Assignment: LAB 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================




#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

int rand_gen( int range, int offset )
{
  return offset + rand() % range;
}

void vector_print(vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
}

void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int find_min(vector<int>& v, int element_start, int element_end)
{
    int min_pos = element_start;

    for(int i = element_start + 1; i < element_end; i++)
    {
        if(v[i] < v[min_pos])
        {
            min_pos = i;
        }
    }

    return min_pos;
}

void selection_sort(vector<int>& v)
{

    for(int i = 0; i < v.size() ; i++)
    {
        int min_pos = find_min(v, i, v.size() );
        swap(v[min_pos], v[i]);

    }
}

/*
void insertion_sort(vector<int>& v)
{
    for(int element_start = 0; element_start < v.size(); element_start++)
    {
        for(int i = element_start - 1; i > -1; i--)
        {
            if(v[element_start] < v[i])
            {
                swap(v[element_start], v[i]);
                element_start = i;
            }
        }
    }
}
*/

void insertion_sort(vector<int>& v)
{

int current = 1;
int temp;
int i;

    while (current < v.size())
    {
        temp = v[current];
        i = current -1;

            while (( i >= 0 )&&( temp < v[i] ))
            {
            v[i +1] = v[i];
            i = i -1;
            }

        v[i+1] = temp;
        current = current + 1;
    }
}




int main()
{
    srand( time(0) );

//this pair will generate random numbers in the range -10 to +10
    int r = 21;
    int o = -10;
    vector<int> v (20);
    vector<int> v2 (20);
    vector<int> v3 (20);
    vector<int> vlong1 (7500);
    vector<int> vlong2 (7500);
    vector<int> vlong3 (7500);


    vector<int> v_array (6);
    v2[0] = 2;
    v2[1] = 4;
    v2[2] = 6;
    v2[3] = 8;
    v2[4] = 10;
    v2[5] = 5;

    for (int i = 0; i < 20; ++i)
    {
        v[i] = rand_gen(r, o);
    }

    for (int i = 0; i < 20; ++i)
    {
        v2[i] = rand_gen(r, o);
    }

    for (int i = 0; i < 20; ++i)
    {
        v3[i] = rand_gen(r, o);
    }

    cout << "\n unsorted vector: ";
    vector_print(v);

    cout << "\n SELECTION SORT: " ;
    selection_sort(v);
    vector_print(v);

    cout << "\n\n unsorted vector#2: ";
    vector_print(v2);

    cout << "\n INSERTION SORT: " ;
    insertion_sort(v2);
    vector_print(v2);

    cout << "\n\n unsorted vector#3: ";
    vector_print(v3);

    cout <<"\n STL SORT: ";
    sort(v3.begin(),v3.end());
    vector_print(v3);

    cout << "\n===========PART 2 TIME =================";

    clock_t start;
    clock_t end;
    double dif;

    for (int i = 0; i < 7500; ++i)
    {
        vlong1[i] = rand_gen(r, o);
    }

    for (int i = 0; i < 7500; ++i)
    {
        vlong2[i] = rand_gen(r, o);
    }

    for (int i = 0; i < 7500; ++i)
    {
        vlong3[i] = rand_gen(r, o);
    }

    start = clock();
    selection_sort( vlong1 );
    end = clock();

    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "\nSELECTION SORT took " << dif << " seconds\n";
    cout << endl;
    //-----


    start = clock();
    insertion_sort( vlong2 );
    end = clock();

    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "\nINSERTION SORT took " << dif << " seconds\n";
    cout << endl;

    //-----


    start = clock();
    sort(vlong3.begin(),vlong3.end());
    end = clock();

    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(3);
    cout << "\nSTL SORT took " << dif << " seconds\n";
    cout << endl;

    return 0;
}
