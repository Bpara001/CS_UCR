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
//! \file l_list.cpp
//! \brief Implementation of the class L_list.

#include "l_list.h"
#include <iostream>

using namespace std;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                Constructors and Destructors                ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//! \brief Default constructor for the L_list class.
L_list::L_list( )
:head(NULL),tail(NULL),size(0)
{
}

//! \brief Destructor for the L_list class.
L_list::~L_list( )
{

}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                          Accessors                         ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//! \brief Print the contents of the list to the screen.
//! \return void.
void L_list::print( )
{
    Node* ptr = NULL;
    for(ptr = head; ptr != NULL; ptr = ptr->get_next())
    {
        cout << ptr->get_value();
    }

}

//! \brief Return the current size (number of nodes in list).
//! \return int.
int L_list::get_size( ) const
{
    return size;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                          Mutators                          ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//! \brief Create and insert a new node at the front of the list.
//! \param value is the value added to the list.
//! \return void.
void L_list::push_front( const string & value )
{
    Node* new_node = new Node(value);
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        size++;
        return;
    }

    new_node->set_next(head);
    head = new_node;
    size++;
}

//! \brief Create and insert a new node at the back of the list.
//! \param value is the value added to the list.
//! \return void.
void L_list::push_back( const string & value )
{
    Node* new_node = new Node(value);

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        size++;
        return;
    }

    Node* temp = head;

    while(temp->get_next() != NULL)
    {
        temp = temp->get_next();
    }

    temp->set_next(new_node);
    tail = new_node;
    size++;

}


//! \brief Remove the node at the front of the list.
//! \return void.
void L_list::pop_front( )
{

    if(head == NULL)
    {
        return;
    }

    head = head->get_next();
    size--;
}

Node* L_list::search(const string& str)
  {
      Node* ptr = NULL;

      for(ptr = head; ptr != NULL; ptr = ptr->get_next())
      {
          if(ptr->get_value() == str)
          {
              return ptr;
          }
      }

      return NULL;
  }


