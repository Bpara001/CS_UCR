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
#include <iostream>
#include "tree.h"

using namespace std;

void printOrders( Tree *tree ) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}


int main( ) {

  Tree tree;

  cout << "----------------------------------------------------------------\n";
  cout << "Test 1: Testing simple insert" << endl;
  cout << "inserting: 6, 6, 3, 8, 1, 5, 9, 0, 4, 8, 1, 1, 1, 0" << endl;
  tree.insert("6");
  tree.insert("6");
  tree.insert("3");
  tree.insert("8");
  tree.insert("1");
  tree.insert("5");
  tree.insert("9");
  tree.insert("0");
  tree.insert("4");
  tree.insert("8");
  tree.insert("1");
  tree.insert("1");
  tree.insert("1");
  tree.insert("0");

  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search testing" << endl;
  if(tree.search("2"))
	  cout << "\"2\" (false value) -> passed" << endl;
  else
	  cout << "\"2\" (false value) -> failed" << endl;
  if(tree.search("0"))
	  cout << "\"0\" (leaf node) -> passed" << endl;
  else
	  cout << "\"3\" (leaf node) -> failed" << endl;
  if(tree.search("5"))
	  cout << "\"5\" (internal node) -> passed" << endl;
  else
	  cout << "\"5\" (internal node) -> failed" << endl;

  if(tree.search("6"))
	  cout << "\"6\" (root node) -> passed" << endl;
  else
	  cout << "\"6\" (root node) -> failed" << endl;


  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"6\" (root) = "
       << tree.height( "6" ) << endl;
  cout << "Height of subtree rooted at \"3\" (internal node) = "
       << tree.height( "3" ) << endl;
  cout << "Height of subtree rooted at \"4\" (leaf node) = "
       << tree.height( "4" ) << endl;
  cout << "Height of subtree rooted at \"7\" (false value) = "
       << tree.height( "7" ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "\nRemoving \"0\" (leaf node w/ count > 1)" << endl;
  tree.remove( "0" );
  printOrders( &tree );
  cout << "\nRemoving \"0\" (leaf node)" << endl;
  tree.remove( "0" );
  printOrders( &tree );
  cout << "\nRemoving \"8\" (internal node w/ count >1)" << endl;
  tree.remove( "8" );
  printOrders( &tree );
  cout << "\nRemoving \"3\" (internal node)" << endl;
  tree.remove( "3" );
  printOrders( &tree );
  cout << "\nRemoving \"6\" (root node w/ count > 1)" << endl;
  tree.remove( "6" );
  printOrders( &tree );
  cout << "\nRemoving \"6\" (root node)" << endl;
  tree.remove( "6" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "//END OF MAIN"<< endl;

  return 1;
}
