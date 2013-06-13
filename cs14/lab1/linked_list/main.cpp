/**
 * UCR CS&E
 * CS014 Eclipse Tutorial
 * Part 2 - Linked List
 * main.cpp
 */

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	/* Instantiate two Lists */
	List myList;
	List myList2;
	
	/* Try to print an empty List */
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}

	////my_functions test harness////
	List myList3;
	for(int i = 10; i <= 100; i = i + 10)
	{
		myList3.push_back(i);
	}
	myList3.print();

	cout << "\nusing instert_sort with (55)";
	myList3.sorted_insert(55);
	myList3.print();

	cout << "\nusing reverse function";
	myList3.print_reverse();
	cout << endl;
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}
