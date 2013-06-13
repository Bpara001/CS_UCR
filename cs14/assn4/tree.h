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


#ifndef __TREE_H
#define __TREE_H

#include "node.h"

class Tree {
private:
  Node *root;

public:

  //!Defualt constructor
  Tree ( )
  :root(NULL)
  {
  }

  //!Deconstructor
  ~Tree ( )
  {
	  empty(root);
  }

  //Inserts the specified string into the tree and retains balance
  void insert ( string x)
  {
	  Node* leaf = find_leaf(root,x);
	  if(leaf == NULL)
	  {
		  Node* temp = new Node(x);
		  root = temp;
		  return;
	  }
	  if(leaf->get_small() != "" && leaf->get_large() == "")
	  {
		  string min = leaf->find_min(x);
		  string max = leaf->find_max(x);
		  leaf->set_small(min);
		  leaf->set_large(max);
	  }
	  else
		  split(leaf,x);
  }

  //!prints preorder
  void preOrder ( )
  {
	  preorder_recursive(root);
	  cout << endl;
  }

  //!Prints inorder
  void inOrder ( )
  {
	  inorder_recursive(root);
	  cout << endl;
  }

  //!Prints postorder
  void postOrder ( )
  {
	  postorder_recursive(root);
	  cout << endl;
  }

  //!Removes the specified string from the tree and retains balance
  void remove ( string x)
  {

	  Node* n = search_orginal(x);
	  if(n == NULL)
		  return;
	  else
		  fix(n,x);
  }

  //Searches for the specific node, returns true or false of found
  bool search ( string x)
  {
	  return search_recursive(x,root);
  }

// Add additional functions/variables here


  //Searches for the specific node, returns the node, or null if not found
  Node * search_orginal ( string x)
  {
	  return search_recursive(x,root);
  }


  /////////////////////////////////////////////////////////////////
  ///////////////// Recursive helper Functions ////////////////////
  /////////////////////////////////////////////////////////////////

  //!Recursive helper function for preorder transversal
  void preorder_recursive(Node* node)
  {
	  if(node)
	  {
		  if(node->get_large() == "")
		  {
			  cout << node->get_small() << ", ";
			  preorder_recursive(node->get_left());
			  preorder_recursive(node->get_right());
		  }
		  else
		  {
			  cout << node->get_small() << ", ";
			  preorder_recursive(node->get_left());
			  cout << node->get_large() << ", ";
			  preorder_recursive(node->get_middle());
			  preorder_recursive(node->get_right());
		  }
	  }
  }

  //!Recursive helper function for inorder transversal
  void inorder_recursive(Node* node)
  {
	  if(node)
	  {
		  if(node->get_large() == "")
		  {
			  inorder_recursive(node->get_left());
			  cout << node->get_small() << ", ";
			  inorder_recursive(node->get_right());
		  }
		  else
		  {
			  inorder_recursive(node->get_left());
			  cout << node->get_small() << ", ";
			  inorder_recursive(node->get_middle());
			  cout << node->get_large() << ", ";
			  inorder_recursive(node->get_right());
		  }
	  }
  }

  //!Recursive helper funciton for postorder transversal
  void postorder_recursive(Node* node)
  {
	  if(node)
	  {
		  if(node->get_large() == "")
		  {
			  postorder_recursive(node->get_left());
			  postorder_recursive(node->get_right());
			  cout << node->get_small() << ", ";
		  }
		  else
		  {
			  postorder_recursive(node->get_left());
			  postorder_recursive(node->get_middle());
			  cout << node->get_small() << ", ";
			  postorder_recursive(node->get_right());
			  cout << node->get_large() << ", ";
		  }
	  }
  }


  //!Recursive empty function
  void empty(Node* node)
  {
	  if(node)
	  	  {
	  		  if(node->get_large() == "")
	  		  {
	  			  empty(node->get_left());
	  			  empty(node->get_right());
	  			  delete node;
	  		  }
	  		  else
	  		  {
	  			  empty(node->get_left());
	  			  empty(node->get_middle());
	  			  delete node;
	  			  empty(node->get_right());
	  			  delete node;
	  		  }
	  	  }
  }

  //!Recursive Helper function for search
  Node* search_recursive(string x, Node* node)
  {
	  if(node)
	  {
		  if(node->get_small() == x || node->get_large() == x)
			  return node;
		  else
		  {
			  if(x < node->get_small())
				  return search_recursive(x,node->get_left());
			  else if(x < node->get_large())
				  return search_recursive(x,node->get_middle());
			  else
				  return search_recursive(x,node->get_right());
		  }
	  }
		  return NULL;
  }

  /////////////////////////////////////////////////////////////////
  /////////////////// Other helper Functions //////////////////////
  /////////////////////////////////////////////////////////////////

  //!Recursive helper function for insert
  void split(Node* n, string x)
  {
	  Node* p = new Node();
	  if(n == root)
		  root = p;
	  else
		  p = n->get_parent();

	  Node* n1 = new Node(n->find_min(x),"",p);
	  Node* n2 = new Node(n->find_max(x),"",p);

	  if(p->get_small() != "" && p->get_large() == "")
	  {
		  if(p->get_left() == n)
		  {
			  p->set_left(n1);
			  p->set_middle(n2);
		  }
		  else
		  {
			  p->set_middle(n1);
			  p->set_right(n2);
		  }

	  }
	  else if(p->get_small() == "")
	  {
	  p->set_left(n1);
	  p->set_right(n2);
	  }

	  if(!n->is_leaf())
	  {
		  if(n->get_left()->is_full())
		  {
			  Node* sm = new Node(n->get_middle()->get_small());
			  Node* lr = new Node(n->get_middle()->get_large());
			  //n1 becomes the parent of n’s two leftmost children
			  n1->set_left(n->get_left());
			  n->get_left()->set_parent(n1);
			  n1->set_right(sm);
			  sm->set_parent(n1);
			  //n2 becomes the parent of n’s two rightmost children
			  n2->set_right(n->get_right());
			  n->get_right()->set_parent(n2);
			  n2->set_left(lr);
			  lr->set_parent(n2);
		  }
	  }

	  if(p->is_full())
	  {
			p->set_middle(n1);
			string sm = n1->find_min(n2->get_small());
			string lr = n1->find_max(n2->get_small());
			p->get_middle()->set_small(sm);
			p->get_middle()->set_large(lr);
			split(p,n->find_mid(x));
	  }
	  else
	  {
		  if(p->is_empty())
		  {
			 p->set_small(n->find_mid(x));
			 p->set_large("");
			 n1->set_parent(p);
			 n2->set_parent(p);
		  }
		  else
		  {
			 string sm = p->find_min(n->find_mid(x));
			 string lr = p->find_max(n->find_mid(x));
			 p->set_small(sm);
			 p->set_large(lr);
		  }
	  }

	  delete n;
  }

  //Finds the leaf where the string must be placed starting at node
  Node* find_leaf(Node* node,string x)
  {
	  if(node == NULL)
	  {
		  return NULL;
	  }

	  //BASE CASE
	  if(node->is_leaf())
		  return node;

	  //Case1, one value
	  else if(node->get_small() != "" && node->get_large() == "")
	  {
	  	  //go left
	  	  if(node->get_small() > x)
	  		  return find_leaf(node->get_left(),x);
	  	  //go right
	  	  else if(node->get_small() < x)
	  		  return find_leaf(node->get_right(),x);
	  }

	  //Case2, two value
	  else if(node->get_small() != "" && node->get_large() != "")
	  {
		  //go left
	  	  if(node->get_small() > x)
	  		  return find_leaf(node->get_left(),x);
	  	  //go mid
	  	  else if(node->get_small() < x && node->get_large() > x)
	  		  return find_leaf(node->get_middle(),x);
	  	  //go right
	  	  else if(node->get_large() < x)
	  		  return find_leaf(node->get_right(),x);
	  }
	  return NULL;
  }
  //Recursive helper function for remove
  void fix(Node* n,string x)
  {
	  //CASE1, String To remove is root
	  if(n == root)
	  {
		  //Case1, 1 value, root is leaf
		  if(n->get_small() == x && n->is_leaf() && !n->is_full())
		  {
			  root = NULL;
			  delete n;
		  }
		  //Case2, 2 values, string is small, root is leaf
		  else if(n->get_small() == x && n->is_leaf() && n->is_full())
		  {
			  n->set_large("");
		  }
		  //Case3, 2 values, string is large, root is leaf
		  else if(n->get_large() == x && n->is_leaf())
		  {
			  n->set_large("");
		  }
		  //Case4, 2 values, string is small, root has children
		  else if( !n->is_leaf() && n->get_small() == x && !n->is_full())
		  {
			 n->set_small(n->get_left()->get_small());
			 n->set_large(n->get_right()->get_small());
			 delete n->get_right();
			 delete n->get_left();
			 n->set_right(NULL);
			 n->set_left(NULL);
		  }
	  }
	  else
	  {
		  Node* p = n->get_parent();

		  //CASE2, String To remove is leaf with 1 value and p has 1 value
		  if(n->is_leaf() && !n->is_full() && !p->is_full())
		  {
			  //left node case
			  if(p->get_left() == n)
			  {
				  string sm = p->get_small();
				  string lr = p->get_right()->get_small();
				  p->set_small(sm);
				  p->set_large(lr);
				  delete p->get_right();
				  n = NULL;
				  delete n;
				  p->set_right(NULL);
				  p->set_left(NULL);
			  }
			  //right node case
			  else
			  {
				  string sm = p->get_left()->get_small();
				  string lr = p->get_small();
				  p->set_small(sm);
				  p->set_large(lr);
				  delete p->get_left();
				  n = NULL;
				  delete n;
				  p->set_right(NULL);
				  p->set_left(NULL);
			  }
		  }
		  //CASE3, String To remove is leaf with 2 value and p has 1 value
		  else if(n->is_leaf() && n->is_full() && !p->is_full())
		  {
			  //Case1, small value
			  if(x == n->get_small())
			  {
				  n->set_small(n->get_large());
				  n->set_large("");
			  }
			  //Case2, large value
			  else
				  n->set_large("");
		  }
		  //String to remove is leaf with 1 value and p has 2 value
		  else if(n->is_leaf() && !n->is_full() && p->is_full())
		  {
			  //left node
			  if(x == p->get_left()->get_small())
			  {
				  delete n;
				  p->set_left(p->get_middle());
				  p->set_middle(NULL);
				  p->get_left()->set_large(p->get_left()->get_small());
				  p->get_left()->set_small(p->get_small());
				  p->set_small(p->get_large());
				  p->set_large("");
			  }
			  //middle node
			  else if(x == p->get_middle()->get_small())
			  {
				  delete n;
				  p->set_middle(NULL);
				  p->get_left()->set_large(p->get_small());
				  p->set_small(p->get_large());
				  p->set_large("");
			  }
			  //right node
			  else
			  {
				  delete n;
				  p->set_right(p->get_middle());
				  p->set_middle(NULL);
				  p->get_right()->set_large(p->get_large());
				  p->set_large("");
			  }
		  }
	  }
  }

};

#endif
