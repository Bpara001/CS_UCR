//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn4
// Lab section: 022
// TA: Busra Celikkaya
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

///////////////////////////////////////////////////////////////////////////
///CLASS NAME: PQueue                                                   ///
///PURPOSE:  -creates a heap-based priority queue of something          ///
///REQUIRES: -STL algorithm                                             ///
///          -Vertx.h                                                   ///
///////////////////////////////////////////////////////////////////////////


#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include "Vertex.h"
#include <algorithm>

template <class ItemType>
class PQueue
{

private:
vector< pair<ItemType,int> > v;

//! Private helper function, returns the left child of the node
int left(int root) const
{
  return (root * 2) + 1;
}

//!Private helper function, returns the right child of the node
int right(int root) const
{
  return (root * 2) + 2;
}

//!Private helper function, returns the parent of the node
int parent(int child) const
{
  return (child - 1) / 2;
}


public:

//!Constructor, 0 arguments
PQueue()
{}

//!Member: pushs a value in the queue with a priority
void push(const ItemType &item, int n )
{
    //Place the new entry in the heap in the first avaialbe location
    v.push_back(pair<ItemType,int> (item,n));


    //While the new entry's parent is less than the new entry, swap
    int pos = v.size() -1;
    while(v[pos].second > v[parent(pos)].second)
    {
        swap(v[pos],v[parent(pos)]);
        pos = parent(pos);
    }

}

//!Member: dequeues the highest priority
void pop()
{
    //copy the last entry in the depest level to the root, and remove that node
    //only if the values are not equal, otherwise...
    if(v.back().second != v.front().second){
    swap(v.back(),v.front());
    v.pop_back();

    //while the out of place entry is less then one of its children, swap
    int i = 0; //using 'i' instead ofp pos to avoid line wrapping
    while(v[i].second<=v[right(i)].second||v[i].second<v[left(i)].second
          && right(i) < (v.size()-1) && left(i) < (v.size()-1))
    {
        //out of bounds checks
        if(v.size() == 0 ) return;
        if(right(i) > (v.size()-1)) return;
        if(left(i) > (v.size()-1)) return;

        //swap with highest child: right
        if(v[left(i)].second < v[right(i)].second)
        {
            swap(v[i],v[right(i)]);
            i = right(i);
        }

        //swap with highest child: left
        else if(v[left(i)].second > v[right(i)].second)
        {
            swap(v[i],v[left(i)]);
            i = left(i);
        }
        //if equal, go right
        else
        {
            cout <<" ITS EQUAL WHAT DO I DO?" << endl;
            swap(v[i],v[right(i)]);
            i = right(i);
        }
    }
    }

    //if they are equal, then shift everything by one and pop the back
    else{
    for(int i = 0; i < v.size()-1; i++)
        swap(v[i],v[i+1]);
    v.pop_back();

    }
}

//!Acessor: returns the top value of the queue
ItemType front()
{
    return v[0].first;
}

//!Acessor, tells if it is empty or not
bool empty() const
{
   return (v.size() == 0);
}

};

#endif
