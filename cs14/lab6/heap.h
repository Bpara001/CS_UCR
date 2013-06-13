
#ifndef __HEAP_H
#define __HEAP_H

#include "printjob.h"
using namespace std;

const int MAX_HEAP_SIZE = 7;

class Heap {
private:
  PrintJob* arr;      // Notice this is a dynamically created array of
                       // printjob pointers
  int numItems;

public:

  void enqueue ( PrintJob* pj)
  {
	 // cout << "NOT WORKING" << endl;

	  if(numItems != MAX_HEAP_SIZE)
	  {
		  if(numItems == 0)
		  {
			  arr[numItems].setJobNumber(pj->getJobNumber());
			  arr[numItems].setPages(pj->getPages());
			  arr[numItems].setPriority(pj->getPriority());
			  numItems++;
		  }


		  else
		  {
			  int x = numItems;

			  while(x>0 && arr[(x-1)/2].getPriority() < pj->getPriority())
			  {
				  arr[x] = arr[(x-1)/2];
				  x =((x-1)/2);
			  }

			  arr[x].setJobNumber(pj->getJobNumber());
			  arr[x].setPages(pj->getPages());
			  arr[x].setPriority(pj->getPriority());
			  numItems++;
		  }

	  }
	  else
		  cout <<"ERROR HEAP_MAX_SIZE_REACHED" << endl;

  }
  void dequeue ( )
  {

	  PrintJob temp;

	  temp.setJobNumber(arr[numItems-1].getJobNumber());
	  temp.setPages(arr[numItems-1].getPages());
	  temp.setPriority(arr[numItems-1].getPriority());

	  arr[numItems-1].setPriority(0);
	  arr[numItems-1].setJobNumber(0);
	  arr[numItems-1].setPages(0);

	  arr[0].setPriority(0);
	  arr[0].setJobNumber(0);
	  arr[0].setPages(0);

	  dequeue_recursive(temp,0);

	  numItems--;


  }
  PrintJob* highest ( )
  {
	  if(numItems == 0)
		  return NULL;
	  else
		  return &arr[0];
  }
  void print ( )
  {
	  for(int i = 0; i < MAX_HEAP_SIZE; i++)
	  {
		  if(arr[i].getPriority() != 0 && arr[i].getJobNumber() != 0 && arr[i].getPages() != 0)
		  {
			  cout <<"(" << arr[i].getPriority() << ", ";
			  cout << arr[i].getPages() << ", ";
			  cout << arr[i].getJobNumber() << ")";
		  }
	  }
	  cout << endl;
  }

// include any additional variables/functions here

  Heap()
  {
	  arr = new PrintJob[MAX_HEAP_SIZE];
	  numItems = 0;
  }

  void dequeue_recursive(PrintJob pj, int loc)
  {

	  if(pj.getPriority() > arr[(2 * loc) + 1].getPriority()
			  && pj.getPriority() > arr[(2 * loc) +2].getPriority())
	  {
		  arr[loc].setPriority(pj.getPriority());
		  arr[loc].setJobNumber(pj.getJobNumber());
		  arr[loc].setPages(pj.getPages());
	  }
	  else if( arr[(2 * loc) + 1].getPriority() == 0 &&
			  arr[(2 * loc) +2].getPriority() == 0)
	  {
		  arr[loc].setPriority(0);
		  arr[loc].setJobNumber(0);
		  arr[loc].setPages(0);
	  }
	  else
	  {
		  if( arr[(2 * loc) + 1].getPriority() > arr[(2 * loc) +2].getPriority())
		  {
			  arr[loc].setPriority(arr[(2 * loc) + 1].getPriority());
			  arr[loc].setJobNumber(arr[(2 * loc) + 1].getJobNumber());
			  arr[loc].setPages(arr[(2 * loc) + 1].getPages());

			  dequeue_recursive(pj,((2*loc)+1));
		  }
		  else if( arr[(2 * loc) + 1].getPriority() < arr[(2 * loc) +2].getPriority())
		  {
			  arr[loc].setPriority(arr[(2 * loc) + 2].getPriority());
			  arr[loc].setJobNumber(arr[(2 * loc) + 2].getJobNumber());
			  arr[loc].setPages(arr[(2 * loc) + 2].getPages());

			  dequeue_recursive(pj,((2*loc)+2));
		  }
	  }

  }


};

#endif
