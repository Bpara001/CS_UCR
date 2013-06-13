/*
 * cs014_10su1 lab 5
 * main.cc for BST
 */

#include "tree.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 2) {
    	cerr << "Usage error: expected <executable> <value>" << endl;
    	exit(1);
    }

    string cmd;
    string key;
    Tree t;

    ofstream ofs(argv[1]);
    if(!ofs) {
    	cout << "output.dot could not be opened." << endl;
    	exit(1);
    }
//==============================================


	for(;;) {
		cin >> cmd;
		if(cmd == "insert")
		{
			cin >> key;
			t.insert(key);
		}
		else if(cmd == "remove")
		{
			cin >> key;
			t.remove(key);
		}
		else if(cmd == "dotty")
		{
			ofs.clear();
			ofs.close();
			ofstream ofs(argv[1]);
			ofs << "digraph G {" << endl;

			// implement code here that will produce the correct dot file
			// based on the user's preference, i.e. preorder, postorder,
			// inorder, node height

			/*For writing to a dotty file
			 * Tree t;
			 * queue<Node*> q;
			 * push t's root into q;
			 * while q is not empty
			 * 	Node* temp <- q.top
			 * 	q.pop;
			 * 	ofs << temp->data << "_" << temp->count << " ";
			 * 	ofs << "-> ";
			 * 	ofs << temp->left->data << "_" << temp->left->count << ";"
			 * 	ofs << endl;
			 *
			 * 	q.push(temp->left);
			 *
			 * 	ofs << temp->data << "_" << temp->count << " ";
			 * 	ofs << "-> ";
			 * 	ofs << temp->right->data << "_" << temp->right->count << ";"
			 * 	ofs << endl;
			 */
		   queue<Node*> q;
			q.push(t.root);
			while(!q.empty())
			{
				Node* temp = q.front();

				if(temp->left != NULL && temp->right != NULL)
				{
					q.pop();
					ofs << temp->data << "_count_" << temp->count;
					ofs << "_height_" << t.height(temp->data);
					ofs << "-> ";
					ofs << temp->left->data << "_count_" << temp->left->count;
					ofs << "_height_" << t.height(temp->left->data) << ";";
					ofs << endl;
					ofs << temp->data << "_count_" << temp->count;
					ofs << "_height_" << t.height(temp->data);
					ofs << "-> ";
					ofs << temp->right->data << "_count_" << temp->right->count;
					ofs << "_height_" << t.height(temp->left->data) << ";";
					ofs << endl;
					q.push(temp->left);
					q.push(temp->right);
				}

				else if(temp->left != NULL && temp -> right == NULL)
				{
					q.pop();
					ofs << temp->data << "_count_" << temp->count;
					ofs << "-> ";
					ofs << temp->left->data << "_count_" << temp->left->count;;
					q.push(temp->left);
				}

				else if(temp->left == NULL && temp -> right != NULL)
				{
					q.pop();
					ofs << temp->data <<"_count_" << temp->count;
					ofs << "-> ";
					ofs << temp->right->data  <<"_count_" << temp->right->count <<";";
					q.push(temp->right);
				}
				else //if(temp->left == NULL && temp-> right == NULL)
					q.pop();
		   }

			ofs << "}" << endl;
			system("dotty output.dot");

		}

		else if(cmd == "end") break;

		else
			cout << cmd << ", not found, try again." << endl;
	}
	ofs.clear();
	ofs.close();
	cout << "Good bye!" << endl;
	return 0;
}
