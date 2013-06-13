/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn4

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */


#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node {

  friend class Tree;

private:

  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

// Add additional functions/variables here. Remember, you may not add any
// Node * or string variables.

public:
  ////////////////////////////////////////////////////////////
  //////////////////////  CONSTRUCTORS  //////////////////////
  ////////////////////////////////////////////////////////////

  //!Defualt Constructor
  Node()
  :small(""),large(""),left(NULL),middle(NULL),right(NULL),parent(NULL)
   {
   }

  //!Constructor with one value
  Node(string x)
  :small(x),large(""),left(NULL),middle(NULL),right(NULL),parent(NULL)
  {
  }

  //!Constructor with two values
  Node(string x, string y)
  :small(x),large(y),left(NULL),middle(NULL),right(NULL),parent(NULL)
  {
  }

  //!Constructor with three values
  Node(string x, string y, Node* p)
  :small(x),large(y),left(NULL),middle(NULL),right(NULL),parent(p)
  {
  }

  //!Constructor with all values: string, string, PARENT, LEFT, MID, RIGHT
  Node(string x, string y, Node* p, Node* l, Node* m, Node* r)
  :left(l),middle(m),right(r),parent(p)
  {
	  if(x > y)
	  {
		  small = y;
		  large = x;
	  }
	  else
	  {
		  small = x;
		  large = y;
	  }
  }

  //////////////////////////////////////////////////////////////
  ////////////////////  FIND FUNCTIONS /////////////////////////
  //////////////////////////////////////////////////////////////

  //!Find the smallest value when compared with another string
  string find_min(string x)
  {
	  //CASE1, small exists
	  if(small != "")
	  {
		  if(x > small)
			  return small;
		  else if(x < small)
			  return x;
	  }

	  //CASE2, small does not exist but large does
	  else if(small == "" && large != "")
	  {
		  if(x < large)
			  return x;
		  else
			  return large;
	  }

	  //CASE3, empty node
	  else
		  return x;
	  return "";
  }

  //!Find the middle value when compared with another string
  string find_mid(string x)
  {
	  //CASE1, small exists, large does not
	  if(small != "" && large == "")
		  cout << "Error: node::find_mid, large does not exist" << endl;


	  //CASE2, small and large exist
	  else if(small != "" && large != "")
	  {
		  if(small > x && small < large)
			  return small;
		  else if(small < x && x < large)
			  return x;
		  else if(small < large && large < x)
			  return large;
		  else
			  cout << "ERROR: node::find_mid" << endl;
	  }

	  //CASE3, only large exists
	  else if(small == "" && large != "")
		  return x;

		return "";

  }

  //!Find the largest value when compared with another string
  string find_max(string x)
  {
	  //CASE1, large exists
	  if(large != "")
	  {
		  if(large > x)
			  return large;
		  else
			  return x;
	  }

	  //CASE2, small exists only
	  else if(small != "" && large == "")
	  {
		  if( small > x)
			  return small;
		  else
			  return x;
	  }

	  //CASE3, anything else
	  else
		  cout << "ERROR, node::find_max" << endl;

	  return "";
  }


  ///////////////////////////////////////////////////////////////////
  //////////   BASIC ACCESSOR AND MUTATOR FUNCTIONS   ///////////////
  ///////////////////////////////////////////////////////////////////

  //Returns bool if the node is a leaf
  bool is_leaf()
  {
	  if(left == NULL && right == NULL && middle == NULL)
		  return true;
	  else
		  return false;
  }

  //Returns bool if the node has a small and large value
  bool is_full()
  {
	  if( small != "" && large != "")
		  return true;
	  else
		  return false;
  }

  //Returns bool if the node has values or not
  bool is_empty()
  {
	  if(small == "" && large == "")
		  return true;
	  else
		  return false;
  }

  //Returns string small
  string get_small() const
  {
	  return small;
  }

  //Returns string large
  string get_large() const
  {
	  return large;
  }

  //Returns the next left node
  Node* get_left() const
  {
	  return left;
  }

  //Returns the next middle node
  Node* get_middle() const
  {
	  return middle;
  }

  //Returns the next right node
  Node* get_right() const
  {
	  return right;
  }

  //Returns the parent of the node
  Node* get_parent() const
  {
	  return parent;
  }

  //Sets the small string
  void set_small(string x)
  {
	  small = x;
  }

  //Sets the large string
  void set_large(string x)
  {
	  large = x;
  }

  //Sets the next left node
  void set_left(Node* x)
  {
	  left = x;
  }

  //Sets the next middle node
  void set_middle(Node* x)
  {
	  middle = x;
  }

  //Sets the next right node
  void set_right(Node* x)
  {
	  right = x;
  }

  //Sets the parent node
  void set_parent(Node* x)
  {
	  parent = x;
  }
};

#endif
