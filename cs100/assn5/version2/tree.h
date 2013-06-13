/* Course: CS 14 Summer 2010

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Lecture Section: 101
   Lab Section: 121
   TA: Ryan Rusich

   Assignment: assn3

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */

#ifndef __TREE_H
#define __TREE_H

#include "node.h"
using namespace std;

class Tree {

private:


public:
	  Node *root;
	  int size_n;
  //!INSERT AN ITEM INTO THE BINARY TREE
  //Be sure to keep the binary search tree properties. When an item is first
  //inserted into the tree the count should be set to 1. When adding a
  //duplicate string (case sensitive), rather than adding another node, the
  //count variable should just be incremented.
  void insert( const string & s)
  {
	  //CASE1, empty tree
	  if(root == NULL)
	  {
		  Node* temp = new Node(s);
		  root = temp;
		  return;
	  }
	  //CASE2, non-empty tree
	  else
		  insert_recursive(root,s);
  }

  //!SEARCH FOR A STRING IN THE BINARY SEARCH TREE
  //It should return true if the string is in the tree, and false otherwise.
  bool search( const string & s)
  {
	  Node* result = search_recursive(root,s);
	  if(result == NULL)
		  return false;
	  else
		  return true;
  }

    void clear()
    {
        size_n = 0;
        cout << "hello" << endl;
        //root.reset();
        cout << "hi" << endl;
        clear_recursive(root);
        cout << "hi1" << endl;
    }


    bool empty()
    {
        if(root == NULL)
            return true;
        else
            return false;
    }

  //!Traverse and print the tree in preorder notation
  int size()
  {
        return size_n;
  }

  void copy(Tree t)
  {
        copy_recursive(root,t);
  }



  //////////////////////////////////////////////////////
  ///// Add any additional variables/functions here ////
  //////////////////////////////////////////////////////

  //!Defualt Constructor
  Tree()
  :root(NULL),size_n(0)
  {
  }

  //DeConstructor
  ~Tree()
  {
	  clear();
  }

  //////////////////////////////////////////////////////
  ///////////////// HELPER FUNCTIONS ///////////////////
  //////////////////////////////////////////////////////
  private:

    //!Recursive insert helper function
    Node* insert_recursive(Node* node_ptr, string s)
    {

  	  //Case1, duplicate value
  	  if(node_ptr->data == s)
  	  {
  		  node_ptr->count++;
  		  return NULL;
  	  }

  	  //Case2, left node
  	  else if(node_ptr->data > s)
  	  {
  		  if(node_ptr->left == NULL)
  		  {
  			  Node* temp = new Node(s);
  			  node_ptr->left = temp;
  			  temp->parent = node_ptr;
  			  size_n++;
  			  return NULL;
  		  }
  		  else return insert_recursive(node_ptr->left,s);
  	  }

  	  //Case3, right node
  	  else if(node_ptr->data < s)
  	  {
  		  if(node_ptr->right == NULL)
  		  {
  			  Node* temp = new Node(s);
  			  node_ptr->right = temp;
  			  temp->parent = node_ptr;
  			  size_n++;
  			  return NULL;
  		  }
  		  else return insert_recursive(node_ptr->right,s);
  	  }
  	  return NULL;
    }

    //!Recursive serach helper function
    Node* search_recursive(Node* node_ptr, string s)
		{
   	 if(node_ptr == NULL)
   		 return NULL;
   	 else if(node_ptr->data == s)
   		 return node_ptr;
   	 else if(node_ptr->data > s)
   		 return search_recursive(node_ptr->left,s);
   	 else if(node_ptr->data < s)
   		 return search_recursive(node_ptr->right,s);
   	 else
   		 return NULL;
		}



    //!Recursive inorder helper function
    void copy_recursive(Node* node_ptr,Tree &t)
    {
   	 if(node_ptr)
   	 {
   		 copy_recursive(node_ptr->left,t);
   		 t.insert(node_ptr->data);
   		 copy_recursive(node_ptr->right,t);
   	 }

    }


    //!Recursive clear helper function
    void clear_recursive(Node* node_ptr)
    {
		  if(node_ptr)
		  {
			  clear_recursive(node_ptr->left);
			  clear_recursive(node_ptr->right);
			  delete node_ptr;
		  }
    }





};

#endif
