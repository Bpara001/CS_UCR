#include <iostream>
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
// Assignment: LAB 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//========================================================================

#include <vector>

using namespace std;

int max(vector<int>nums, int index)
{
    if(index == 0)
        return nums[index];

    int res = max(nums,index-1);

    if(nums[index] > res)
        return nums[index];
    else
    return res;

}

int main()
{

    vector<int> v;

    int number;


    cout <<"Input numbers: ";
    while(cin>>number)
    {
        v.push_back(number);
    }

    int n = v.size() -1;
    int max_number = max(v,n);
    cout << "\nMax number: " << max_number << endl;

    for(int i = 0; i < v.size(); i ++)
    {
        cout << v[i] << " ";
    }
    cout << endl;


    return 0;
}
