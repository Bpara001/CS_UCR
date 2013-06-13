#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

template<class T>
class Node
{
public:
  T data;
  Node *next;


  //!Constructor with data
  Node(T s)
  :data(s),next(NULL)
  {
  }

};

#endif
