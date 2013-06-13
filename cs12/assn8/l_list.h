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
//! \file l_list.h
//! \brief Delaration of the class List.

#ifndef __L_LIST_H__
#define __L_LIST_H__

#include "node.h"

//! \class Linked List.
//! \brief Class for a linked-list object.
class L_list
{
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 public:
  //! \brief Default constructor for the List class.
  L_list( );

  //! \brief Destructor for the List class.
  virtual ~L_list( );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  //! \brief Print the contents of the Llist to the screen.
  //! \return void.
  void print( );

  //! \brief Return the current size (number of Nodes in LList).
  //! \return int.
  int get_size( ) const;

  //! \brief Return the ptr of the head
  //! \return Node ptr
  Node* get_head() const;

  //! \brief Return the ptr of the tail
  //! \return Node ptr
  Node* get_tail() const;

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Create and insert a new node at the front of the list.
  //! \param value is the value added to the list.
  //! \return void.
  void push_front( const string & value );

  //! \brief Remove the node at the front of the list.
  //! \return void.
  void pop_front( );

  //! \brief Remove the node at the back of the list.
  //! \return void.
  void pop_back();

  //! \brief Create and insert a new node at the back of the list.
  //! \param value is the value added to the list.
  //! \return void.
  void push_back( const string & value );

  //! \brief Finds the ptr of a specific node
  //! \param value of the node searched for
  //! \return Node ptr
  //! The order of complexity of this function is O(n), because no matter
  //! how large or small the list is, the search must alaways search the entire
  //! list.
  Node* search(const string& str);

  //! \brief Inserts a specific Node to a specific place
  //! \param value of the node and postiion using ptr
  //! \return The newly created Node.
  Node* insert(const string&, Node*);

  //! \brief Erases a specific Node
  //! \param value of the node that must be erased
  //! \return The newly ereased Node.
  Node* erase(Node*);

  //! \brief reverses the entire list
  //! \return void
  void reverse();


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                 Private Members and Data                   ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 private:
  Node * head;  	//!< A pointer to the first node in the list.
  Node * tail;          //!< A pointer to the last node in the list.
  int size;		//!< The actual size of the list.

  //! \brief helps to reverse the entire list
  //! \param ptr to the start of the list
  //! \return void
  void recursive_reverse(Node* ptr);
};

#endif // __L_LIST_H__
