//inclusion guards
#ifndef __INTVECTOR_H_
#define __INTVECTOR_H_

class IntVector
{
private:
	unsigned size;	//size of valid elements in the array.
	unsigned capacity;	//capacity of your dynamic array
	int* data;	//your data array

public:
	//Default constructor initializes size and capacity to 0.
	IntVector();

	// Parameterized constuctor initializes BOTH size and capacity to 's',
	// and creates an array accordingly.
	// All the elements in the array should be initialized to 0.
	IntVector(unsigned s);

	//Do we need a destructor?
	~IntVector();

	//returns size
	unsigned get_size() const;

	// Returns the value of the element at index.
	// You should also handle the cases where the index is not valid
	// (index out of bounds)
	int get(unsigned index) const;

	// Sets the element at index to value.
	// You should also handle the cases where the index is not valid
	// (index out of bounds)
	void set(unsigned index, int value);

	// Adds value at the end of vector.
	// push_back function should call resize
	// when size == capacity in order to double the capacity.
	void push_back(int value);

	// Removes the element at the end of the vector and returns its value.
	// (Do you need to remove/delete anything)?
	// What happens if the array is empty?
	int pop_back();

	// Doubles the capacity of the vector, preserving existing data.
	// Invoked by push_back when needed
	void resize(int s);

	// Prints the elements in your vector, separated by spaces
	void print() const;

	// Searches the data and returns the index of first instance of value,
	// if none exists, returns -1.
	int find(int value) const;
};

#endif
