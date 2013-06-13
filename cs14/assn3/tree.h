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
  Node *root;

public:

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

  //!FIND AND RETURN THE LARGEST VALUE IN THE TREE.
  //!Return an empty string if the tree is empty.
  string largest( )
  {
	  //CASE1, empty tree
	  if(root == NULL)
	  {
		  cout <<"ERROR, tree::largest; no root exists" << endl;
		  return "";
	  }
	  //CASE2, non-empty tree
	  else
		  return largest_recursive(root)->data;
  }

  //!FIND AND RETURN THE SMALLEST VALUE IN THE TREE.
  //!Return an empty string if the tree is empty.
  string smallest( )
  {
	  //CASE 1, empty tree
	  if(root == NULL)
	  {
		  cout <<"ERROR, tree::smallest; no root exists" << endl;
		  return "";
	  }
	  //CASE 2, tree exists
	  else
		  return smallest_recursive(root)->data;
  }

  //!COMPUTE AND RETURN THE HEIGHT OF A PARTICUALR STRING IN THE TREE
  //The height of a leaf node is 0 (count the number of edges on the
  //longest path). Return -1 if the string does not exist.
  int height( const string & s)
  {
	  //CASE1, node does not exist
	  if(!search(s))
		  return -1;

	  //CASE2, node exists
	  else
	  {
		  Node * temp = search_recursive(root,s);
		  int h = 0;
		  int max = 0;
		  return height_recursive(temp,h,max);
	  }
  }

  //!REMOVE A SPECIFIED STRING FROM THE TREE.
  //Be sure to maintain all binary search tree properties.

/*If removing a node with a count greater than 1, just decrement the count,
 *  otherwise, if the count is simply 1, remove the node. You MUST follow the
 *  remove algorithm discussed in class or else your program will not pass the
 *  test functions. When removing, if removing a leaf node, simply remove the
 *  leaf. Otherwise, if the node to remove has a left child, replace the node
 *  to remove with the largest string value that is smaller than the current
 *  string to remove (i.e. find the largest value in the left subtree of the
 *  node to remove). If the node has no left child, replace the node to remove
 *  with the smallest value larger than the current string to remove (i.e.
 *  find the smallest value in the right subtree of the node to remove).
*/
  void remove( const string & s)
  {
	  //CASE1; Item not found
	  if(!search(s))
		  return;
	  else
	  {
	     Node* node = search_recursive(root,s);
		  remove_recursive(node,s,s);
	  }
  }


 /*Print the tree in the following manners. When printing a node, print the
  * string followed by the count in parentheses followed by a , and 1 space.
  * For example: goodbye(1), Hello World(3),
 */

  //!Traverse and print the tree in preorder notation
  void inOrder( )
  {
	  inorder_recursive(root);
	  cout << endl;
  }

 //Traverse and print the tree in inorder notation
  void postOrder( )
  {
	  postorder_recursive(root);
	  cout << endl;
  }

  //Traverse and print the tree in postorder notation
  void preOrder( )
  {
	  preorder_recursive(root);
	  cout << endl;
  }

  //////////////////////////////////////////////////////
  ///// Add any additional variables/functions here ////
  //////////////////////////////////////////////////////

  //!Defualt Constructor
  Tree()
  :root(NULL)
  {
  }

  //DeConstructor
  ~Tree()
  {
	  empty(root);
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

    //!Recursive function to find the largest string starting at the node
    Node* largest_recursive(Node* node_ptr)
    {
   	 if(node_ptr->right == NULL)
   		 return node_ptr;
   	 else
   		 return largest_recursive(node_ptr->right);
    }

    //!Recursive function to find the smallest string starting at the node
    Node* smallest_recursive(Node* node_ptr)
    {
   	 if(node_ptr->left == NULL)
   		 return node_ptr;
   	 else
   		 return smallest_recursive(node_ptr->left);
    }

    //!Recursive function to find the height of a specific node
    int height_recursive(Node* node_ptr, int h, int max)
    {
   	 if(node_ptr != NULL)
   	 {
   		 if(h > max)
				 max = h;

   		 // Traverse the left subtree
   		 if(node_ptr->left != NULL)
   			 max = height_recursive(node_ptr->left, h+1, max);

   		 // Traverse the right subtree
   		 if(node_ptr->right != NULL)
   			 max = height_recursive(node_ptr->right, h+1, max);
   	 }
   	 return max;
    }

    //!Recursive inorder helper function
    void inorder_recursive(Node* node_ptr)
    {
   	 if(node_ptr)
   	 {
   		 inorder_recursive(node_ptr->left);
   		 cout << node_ptr->data <<"("<<node_ptr->count<<"), ";
   		 inorder_recursive(node_ptr->right);
   	 }
    }

    //!Recursive postorder helper function
    void postorder_recursive(Node* node_ptr)
    {
   	 if(node_ptr)
   	 {
   		 postorder_recursive(node_ptr->left);
   		 postorder_recursive(node_ptr->right);
   		 cout << node_ptr->data <<"("<<node_ptr->count<<"), ";
   	 }
    }

    //!Recursive preorder helper Function
    void preorder_recursive(Node* node_ptr)
    {
   	 if(node_ptr)
   	 {
   		 cout << node_ptr->data <<"("<<node_ptr->count<<"), ";
   		 preorder_recursive(node_ptr->left);
   		 preorder_recursive(node_ptr->right);
   	 }
    }

    //!Recursive empty function
    void empty(Node* node_ptr)
    {
		  if(node_ptr)
		  {
			  empty(node_ptr->left);
			  empty(node_ptr->right);
			  delete node_ptr;
		  }
    }

    //!Recursive remove function
    void remove_recursive(Node* node,string s,string orginal)
    {
	     Node* node_ptr = search_recursive(node,s);

   	 //CASE1; remove a leaf
   	 if(node_ptr->left == NULL && node_ptr->right == NULL)
   		 kill_node(node_ptr,orginal);

   	 //CASE2; more than one count
   	 else if(node_ptr->count > 1 )
   		 kill_node(node_ptr,orginal);

   	 //CASE3; Children are present!!
   	 else if(node_ptr->left != NULL)
   	 {
   		 string highest = largest_recursive(node_ptr->left)->data;
   		 int count_temp = largest_recursive(node_ptr->left)-> count;
   		 remove_recursive(node_ptr,highest,orginal);
   		 node_ptr->data = highest;
   		 node_ptr->count = count_temp;
   	 }
   	 else
   	 {
   		 string smallest = smallest_recursive(node_ptr->right)->data;
   		 int count_temp = largest_recursive(node_ptr->right)->count;
   		 remove_recursive(node_ptr,smallest,orginal);
   		 node_ptr->data = smallest;
   		 node_ptr->count = count_temp;
   	 }
    }

    //!Helper-Helper function,removes node or decrements count
    void kill_node(Node* node_ptr,string orginal)
    {
   	 if(node_ptr->count > 1 && node_ptr->data == orginal)
   		 node_ptr->count = node_ptr->count - 1;
   	 else
   	 {
   		 Node* node_parent = node_ptr->parent;
   		 if(node_parent->left == node_ptr)
   		 {
   			 node_parent->left = NULL;
   			 delete node_ptr;
   		 }

   		 else if(node_parent->right == node_ptr)
   		 {
   			 node_parent->right = NULL;
   			 delete node_ptr;
   		 }
   	 }
    }

};

#endif
