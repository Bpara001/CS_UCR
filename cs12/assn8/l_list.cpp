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
// Assignment: ASSN 8
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
    for(Node* ptr = head; ptr != NULL; ptr = ptr->get_next())
    {
        delete ptr;
        ptr = NULL;
    }
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
    if(head == NULL)
    {
        cout << "Nothing to print: List is empty";
    }
    for(ptr = head; ptr != NULL; ptr = ptr->get_next())
    {
        cout << ptr->get_value() << " ";
    }
}

//! \brief Return the current size (number of nodes in list).
//! \return int.
int L_list::get_size( ) const
{
    return size;
}

//! \brief Return the ptr of the head
//! \return Node ptr
Node* L_list::get_head() const
{
    return head;
}

//! \brief Return the ptr of the tail
//! \return Node ptr
Node* L_list::get_tail() const
{
    return tail;
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


//! \brief Remove the node at the back of the list.
//! \return void.
void L_list::pop_back( )
{

    if(head == NULL)
    {
        return;
    }

    Node* temp = head;

    while(temp->get_next()->get_next() != NULL)
    {
        temp = temp->get_next();
    }

    temp->set_next(NULL);
    tail = temp;
    size--;
}

//! \brief Finds the ptr of a specific node
//! \param value of the node searched for
//! \return Node ptr
//! The order of complexity of this function is O(n), because no matter
//! how large or small the list is, the search must alaways search the entire
//! list.
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

      cout << "COULD NOT FIND VALUE " << str << endl;
      return NULL;
  }

//! \brief Inserts a specific Node in the list after the Node pointed to
//! \param value of the node and postiion using ptr
//! \return The newly created Node.
  Node* L_list::insert(const string& str, Node* node)
  {

      Node* node_new = new Node(str);
      if(head == NULL)
      {
          head = node_new;
          size++;
          return node;
      }

      for(Node* ptr = head; ptr != NULL; ptr = ptr->get_next())
      {
          if(ptr == node)
          {
              Node* temp = ptr->get_next();
              ptr->set_next(node_new);
              node_new->set_next(temp);
              size++;
              return node;
          }
      }
      return NULL;
  }

//! \brief Erases a specific Node
//! \param value of the node that must be erased
//! \return The newly ereased Node.
  Node* L_list::erase(Node* node)
  {
      if(head == NULL)
      {
          return node;
      }

      for(Node* ptr = head; ptr != NULL; ptr = ptr->get_next())
      {
          if(ptr->get_next() == node)
          {
              ptr->set_next(ptr->get_next()->get_next());
              size--;
              return node;
          }
      }

      cout << "COULD NOT FIND NODE " << node << endl;
      return NULL;
  }

//! \brief reverses the entire list
//! \return void
  void L_list::reverse()
  {
      recursive_reverse(head);
  }

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~                  Private Helper Functions                  ~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//! \brief recursivly reverses from parameter
//! \param start of the list
//! \return void
  void L_list::recursive_reverse(Node* ptr)
  {
      if(ptr == NULL)
      {
          Node* new_node = head;
          push_back(new_node->get_value());
          pop_front();
          return;
      }

      insert(tail->get_value(),ptr);
      pop_back();

      recursive_reverse(ptr->get_next());
  }
