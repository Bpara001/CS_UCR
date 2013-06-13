/* Course: CS 170 fall quarter , 2012

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Project 1

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//tree.h


#ifndef __TREE_H__
#define __TREE_H__

//load libraries
#include "node.H"
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <time.h>
using namespace std;

//global contants
#define HASHTABLESIZE 12557647  //table size of hashtable. set to prime for better hashing
#define MAXDEPTH 30             //max depth till we stop searching

class Tree {

    //Create objects
    Node root;             //node to the root
    Node goalnode;         //the actual node which is the goal state, can be null if goalstate isnt found

    //Create data structures
    vector<Node> tree;      //vector that holds all states
    queue<int> q;           //queue for which leaf to look at
    priority_queue<Node, vector<Node>,less<vector<Node>::value_type> > q2;  //custom priority queue for nodes
    bool hashtable [HASHTABLESIZE]; //hashtable that tells us if node has been created or not

    //Create objects for statistical information
    int maxqsize;        //counter for the max queue size
    bool goalfound;       //tells us if the goal stae has been found


    //Hashing function taken from online
    //Takes a string,
    //returns a hashed integer value
    unsigned long long hash(const char *str) {
        unsigned long long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % HASHTABLESIZE;
    }

    //function that checks for duplicates
    //Takes a vector with the puzzle integers
    //returns true for "is a duplicate", false for "not a duplicate"
    bool is_dup(vector<int> v){


        //generate the key for the hash value
        //concatnate all values of array and turn into string
        const char* hashkey;
        string temp ="";
        for(int i = 0; i < v.size(); i++){
            stringstream ss;
            ss << v[i];
            temp = temp + ss.str();
        }
        hashkey = temp.c_str();

        //if its a new key, set the item to true and return false
        if(hashtable[hash(hashkey)] != true){
            hashtable[hash(hashkey)] = true;
            return false;
        }

        //if its a repeat key
        else return true;
    }

    //Print solution with a lot of extra text
    //if solution doesnt exist, print the dne text.
    void print_solution(int searchtype,bool possible){

        //If solution could not be found,
        if(!goalfound && possible){
            cout << "\nSoultion could not be found" << endl
                 << "Fatal collision in hashing" << endl
                 << "\nTo solve this problem the search algorithm expanded a total of " << tree.size()-1 << " nodes.\n" //subtract the root node
                 << "The max number of nodes in the queue at any one time was " << maxqsize << ".\n";
        }
        else if(!possible) cout << "Solution DOES NOT exist" << endl;

        //if solution was found
        else{
            cout << "\nSoultion found!\n" << endl;
            cout << "Path of 'Uniform Cost Search'" << endl;

            //push solutions onto the stack
            stack<int> mystack;
            if(root.misplaced != 0){
                Node newnode = tree[goalnode.i];
                mystack.push(goalnode.i);
                while(newnode.depth != 1){
                    mystack.push(tree[newnode.parent].i);
                    newnode = tree[newnode.parent];
                }
            }
            mystack.push(0);


            //otuput the solution
            while(!mystack.empty()){
                Node tempnode = tree[mystack.top()];
                if(tempnode.path != "") cout << "->Moving blank tile " << tempnode.path << ", hn = " << tempnode.hn <<  endl;
                else cout << "->Start!!"  << ", hn = " << tempnode.hn << endl;
                tempnode.printdata();
                cout << endl;
                mystack.pop();
            }
            cout << "\n->FINISHED!" << endl;

            //output some cool stuff
            cout << "To solve this problem the search algorithm expanded a total of " << tree.size()-1 << " nodes.\n"
                 << "The max number of nodes in the queue at any one time was " << maxqsize << ".\n"
                 << "The depth of the goal node was " << goalnode.depth << endl;


        }

    }


    //Tells us if the puzzle is solveable
    //returns true for solveable, false for not.
    bool is_solveable(vector<int> v){

		//return true;
        //solvablility algorithum from http://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html

        int inversions = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i; j < v.size(); j++)
                if(v[i] > v[j]) inversions++;
        }

        //check for widths with odd numbers
        if(inversions %2 != 0 && int(floor(sqrt(v.size()))) % 2 == 1) return false;
        else return true;

    }


    public:

    //defualt constructor
    Tree(vector<int> v){

        //Create the root node and push it back
        root = Node(v,-1,0,"",0,3);
        tree.push_back(root);
        goalfound = false;
        maxqsize = 0;

    }


    //Function to make the tree & find path to solution
    //Param: integer to indicate which search type
    //Does all necessary calculations, sets goalfound and goalnode and all stat info
    void general_search(int searchtype){

        //set the root node
        Node n = root;

        //check if the solution is possible
        bool possible = is_solveable(n.data);

        //Make the tree using the specifica algroithum until maxdepth or goal is found
        while(n.depth != MAXDEPTH and !goalfound and possible){

            //cout << "\n\n" << "DP: " << n.depth  << "/" << n.path << " :: " << q2.size() <<   "; " << tree.size() << ".." << n.hn <<endl;
            //n.printdata();

            //If we reached the goalstate, leave
            if(n.misplaced == 0){
                goalfound = true;
                goalnode = n;
                q.empty();
                break;
            }



            //If its hitting the max depth search, skip making children
            if(n.depth == MAXDEPTH- 1 && searchtype != 1) { /*do nothing*/ }
            else{

                //pop the queue if needed
                if(q.size() > 0) q.pop();
                if(q2.size() > 0) q2.pop();

                //get i position of the zero / blank title
                int pos = n.tile_pos;

                //get length of each row
                int dsize = int(floor(sqrt(n.data.size())));

                //Make right child IF POSSIBLE
                if( (pos+1) % dsize != 0){
                    //swap the values
                    vector<int> new_vec = n.data;
                    new_vec[pos] = new_vec[pos+1];
                    new_vec[pos+1] = 0;


                    //make the newnode and push it
                    if(!is_dup(new_vec)){
                        Node new_node = Node(new_vec, n.i, n.depth+1,"right",tree.size(),searchtype);
                        tree.push_back(new_node);
                        n.moveright = new_node.i;
                        if(searchtype == 1) q.push(tree.size()-1);
                        else if(searchtype == 2 || searchtype == 3) q2.push(new_node);
                    }
                }

                //Make left child IF POSSIBLE
                if( (pos+1) % dsize != 1){

                     //swap the values
                    vector<int> new_vec = n.data;
                    new_vec[pos] = new_vec[pos-1];
                    new_vec[pos-1] = 0;

                    //make the newnode and push it
                    if(!is_dup(new_vec)){
                        Node new_node = Node(new_vec, n.i, n.depth+1,"left",tree.size(),searchtype);
                        tree.push_back(new_node);
                        n.moveleft = new_node.i;
                        if(searchtype == 1) q.push(tree.size()-1);
                        else if(searchtype == 2 || searchtype == 3) q2.push(new_node);
                    }
                }

                //Make up child IF POSSIBLE
                if( (pos+1) > dsize ){
                    //swap the values
                    vector<int> new_vec = n.data;
                    new_vec[pos] = new_vec[pos-dsize];
                    new_vec[pos-dsize] = 0;

                    //make the newnode and pushs it
                    if(!is_dup(new_vec)){
                       Node new_node = Node(new_vec, n.i, n.depth+1,"up",tree.size(),searchtype);
                        tree.push_back(new_node);
                        n.moveup = new_node.i;
                         if(searchtype == 1) q.push(tree.size()-1);
                        else if(searchtype == 2|| searchtype == 3) q2.push(new_node);
                    }
                }

                //Make down child IF POSSIBLE
                if( (pos+1 +dsize) <= n.data.size()){
                     //swap the values
                    vector<int> new_vec = n.data;
                    new_vec[pos] = new_vec[pos+dsize];
                    new_vec[pos+dsize] = 0;


                    //make the newnode and push it
                    if(!is_dup(new_vec)){
                        Node new_node = Node(new_vec, n.i, n.depth+1,"down",tree.size(),searchtype);
                        tree.push_back(new_node);
                        n.movedown = new_node.i;
                         if(searchtype == 1) q.push(tree.size()-1);
                        else if(searchtype == 2|| searchtype == 3) q2.push(new_node);
                    }
                }

                //record the max queue size
                if(searchtype ==1 &&maxqsize < q.size()) maxqsize = q.size();
                else if( (searchtype == 2 || searchtype == 3) && maxqsize < q2.size() ) maxqsize = q2.size();

            }

            //do the search on the next node
            if(searchtype == 1) n = tree[q.front()]; //use regular queue
            else if(searchtype == 2|| searchtype == 3) n = tree[q2.top().i]; //use priority queue

        }

        //print the solution
        print_solution(searchtype,possible);

    }


    //deconstructor
     ~Tree(){

    }

};


#endif
