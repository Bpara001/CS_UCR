/* Course: CS 141

   First Name: Chris
   Last Name: Wong
   Login id: wongc
   email address: cwong030@student.ucr.edu

   Assignment: assn3

   I hereby certify that the code in this file
   is ENTIRELY my own original work.

   ================================================================
 */
//jug.h
#ifndef __JUG_H__
#define __JUG_H__

#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

//////////////////////////////////////////////////////////
///////////////// CONTAINER CLASS ////////////////////////
//////////////////////////////////////////////////////////
//!Creates two separate containers with one int value each;
//!Contains distance(cost) and method for solving the problem
class Containers
{
private:

	int A;
	int B;
	int A_max;
	int B_max;
	int distance;
	string method;

public:

	//Default Constructor
	Containers()
	:A(0),B(0),A_max(0),B_max(0),distance(999999),method("")
	{
	}

	//Constructor with initial capacity values
	Containers(int max1, int max2)
	:A(0),B(0),A_max(max1),B_max(max2),distance(999999),method("")
	{
	}

	//Constructor with initial capacity values and initial values
	Containers(int max1, int max2,int a, int b)
	:A(a),B(b),A_max(max1),B_max(max2),distance(999999)
	{
	}

	//Constructor with initial capacity values and initial values
	Containers(int max1, int max2,int a, int b,int d)
	:A(a),B(b),A_max(max1),B_max(max2),distance(d)
	{
	}

	//Fills container A
	void fillA()
	{
		A = A_max;
	}

	//Fills Container B
	void fillB()
	{
		B = B_max;
	}

	//Empties Container A
	void emptyA()
	{
		A = 0;
	}

	//Empties Container B
	void emptyB()
	{
		B = 0;
	}

	//Pours A into B, B cannot exceed its capacity, any leftover will remain in A
	void pAB()
	{
		int temp1 = (A+B);
		if(temp1 > B_max)
		{
			int temp2 = temp1 - B_max;
			A = temp2;
			B = B_max;
		}
		else
		{
			A = 0;
			B = temp1;
		}
	}

	//Pours B into A, A cannot exceed its capacity, any leftover will remain in B,
	void pBA()
	{
		int temp1 = (A+B);
		if(temp1 > A_max)
		{
			int temp2 = temp1-A_max;
			B = temp2;
			A = A_max;
		}
		else
		{
			B = 0;
			A = temp1;
		}
	}

	//Empties both A and B
	void empty()
	{
		A = 0;
		B = 0;
	}

	//Set A and B values
	void set(int a, int b)
	{
		A = a;
		B = b;
	}

	//Set A,B,distance, and method values
	void set(int a, int b, int d, string m)
	{
		A = a;
		B = b;
		distance = d;
		method = m;
	}

	//Set the method of the Container
	void set_m(string m)
	{
		method = m;
	}

	//Prints the contents of A and B into the console
	void print()
	{
		cout << "Contents: [A->" << A << ", B->" << B <<  "]";
		if(distance != 0)
			cout << " "<< distance;
		cout << endl;
	}

	//Returns weather the Containers are both empty
	bool is_empty()
	{
		return (A == 0 && B == 0);
	}

	//Returns Container A contents
	int get_A() const
	{
		return A;
	}

	//Returns Container B contents
	int get_B() const
	{
		return B;
	}

	//Returns Container A capacity
	int get_A_max() const
	{
		return A_max;
	}

	//Returns Container B capacity
	int get_B_max() const
	{
		return B_max;
	}

	//Returns Container distance
	int get_d() const
	{
		return distance;
	}

	//Returns Container method
	string get_m() const
	{
		return method;
	}

	//Determines if the compared container is identical
	bool is_same(Containers other)
	{
		return (other.get_A() == A && other.get_B() == B);
	}
};
///////////////////////////////////////////////////////////
/////////////////// DIJKSTRA CLASS ////////////////////////
///////////////////////////////////////////////////////////
//! Data Structure that Contains:current,previous(pr),distance(d),and edges
class Dijkstra
{
public:
	Containers current;
	int pr;
	int d;
	vector<Containers> edge;

	//Default Constructor
	Dijkstra()
	:pr(-1),d(999999),edge()
	 {
		current.set(-1,-1);
	 }

};


//Creates a Vertex for the Graph
class Vertex {
public:

	Containers data;
	vector<Containers> neighbors;

	//Default Constructor
	Vertex()
	:data()
	{
	}

	//Constructor with 2 values
	Vertex(int max_a, int max_b )
	:data(max_a,max_b)
	 {
	 }

	//Constructor with 4 values
	Vertex(int max_a, int max_b, int a, int b )
	:data(max_a,max_b,a,b)
	 {
	 }

	//DeConstructor
	~Vertex()
	{
	}
};

///////////////////////////////////////////////////////////
/////////////////////// JUG CLASS /////////////////////////
///////////////////////////////////////////////////////////
class Jug
{
private:

stack<string> stack;
vector<Vertex> v;
int cA;
int cB;
int N;
bool valid_param;

public:
	//Default Constructor with values
   Jug(int cA,int cB, int N, int cfA, int cfB, int ceA, int ceB, int cpAB,
        int cpBA)
   :cA(cA),cB(cB),N(N)
   {

        //check for valid paramters
        if( 0 <= cA && cA <= cB && N <= cB && cB <= 1000 && N >= 0 &&
            cfA > 0 && cfB > 0 && ceA > 0 && ceB > 0 && cpAB > 0 && cpBA > 0)
            valid_param = true;
        else valid_param = false;

        ////!POPULATE THE GRAPH
        v.push_back(Vertex(cA,cB));
        bool should_continue = true;
        unsigned int count = 0;

        while(should_continue)
        {
            should_continue = false;
            bool neighbor_fillA = false;
            bool neighbor_fillB = false;
            bool neighbor_emptyA = false;
            bool neighbor_emptyB = false;
            bool neighbor_pourAB = false;
            bool neighbor_pourBA = false;
            int a = v[count].data.get_A();
            int b = v[count].data.get_B();
            Containers temp(cA,cB,a,b);

            /////!PHASE1: Determine if it is necessary to create a new vertex
            for(unsigned int i = 0; i < v.size(); i++)
            {
                //Check fillA
                temp.set(a,b);
                temp.fillA();
                if(v[i].data.is_same(temp) && !neighbor_fillA)
                    neighbor_fillA = true;

                //Check fillB
                temp.set(a,b);
                temp.fillB();
                if(v[i].data.is_same(temp) && !neighbor_fillB)
                    neighbor_fillB = true;

                //Check emptyA
                temp.set(a,b);
                temp.emptyA();
                if(v[i].data.is_same(temp) && !neighbor_emptyA)
                    neighbor_emptyA = true;

                //Check emptyB
                temp.set(a,b);
                temp.emptyB();
                if(v[i].data.is_same(temp) && !neighbor_emptyB)
                    neighbor_emptyB = true;

                //check pourAB
                temp.set(a,b);
                temp.pAB();
                if(v[i].data.is_same(temp) && !neighbor_pourAB)
                    neighbor_pourAB = true;

                //check pourBA
                temp.set(a,b);
                temp.pBA();
                if(v[i].data.is_same(temp) && !neighbor_pourAB)
                    neighbor_pourBA = true;
				}

            /////!PHASE2: Pushes back more vertexes & adds neighbors when needed

            //check fillA
            temp.set(a,b,cfA,"fill A");
            temp.fillA();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_fillA)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            //check fillB
            temp.set(a,b,cfB,"fill B");
            temp.fillB();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_fillB)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            //check emptyA
            temp.set(a,b,ceA,"empty A");
            temp.emptyA();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_emptyA)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            //check emptyB
            temp.set(a,b,ceB,"empty B");
            temp.emptyB();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_emptyB)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            //check pourAB
            temp.set(a,b,cpAB,"pour A B");
            temp.pAB();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_pourAB)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            //check pourBA
            temp.set(a,b,cpBA,"pour B A");
            temp.pBA();
            if(!v[count].data.is_same(temp))
            {
                if(!neighbor_pourBA)
                    v.push_back(Vertex(cA,cB,temp.get_A(),temp.get_B()));
                v[count].neighbors.push_back(temp);
            }

            /////!PHASE3: Checks to see if there are any more possible nodes
            if(count < v.size()-1)
                should_continue = true;
            count++;
        }
    }

   //DeConstructor
   ~Jug()
   {
   }

   //!Finds the cheapest solution to the jug problem
   int Solve()
   {
  	 //INVAILD INPUTs
    //check that paramters are valid
    if(!valid_param)
        return -1;

  	 Dijkstra table[v.size()];
  	 vector<unsigned int> cloud;

  	 //STEP1, Create a blank table
  	 for(unsigned int i = 0; i < v.size(); i++)
  	 {
  		 table[i].current = v[i].data;
  		 for(unsigned int j = 0; j < v[i].neighbors.size(); j++)
  			 table[i].edge.push_back(v[i].neighbors[j]);
  	 }

  	 table[0].d = 0;
  	 int u = 0;
  	 int total = 0;

  	 //STEP2, Fully populate the Dijkstra table
  	 while(cloud.size() != v.size())
  	 {
				u = find_min_pos(table,v.size(),cloud);
				cloud.push_back(u);
				if(u != 0)
					total = table[u].d;
				else
					total = 0;
				for(unsigned int i = 0; i < table[u].edge.size(); i++)
				{
					int compared_pos = find_pos(table, v.size(),
							table[u].edge[i].get_A(),table[u].edge[i].get_B());
					if((table[u].edge[i].get_d() + total) < table[compared_pos].d
							&& !is_there(cloud,compared_pos))
					{
						table[compared_pos].d = table[u].edge[i].get_d() + total;
						table[compared_pos].pr = u;
						table[compared_pos].current.set_m(table[u].edge[i].get_m());
					}
				}

  	 }

  	 //STEP3, calculate the answer
  	 int index = find_pos(table,v.size(),0,N);
  	 if(index == -1)
  		 return 0;
  	 int success_temp =  table[index].d;
  	 while(index > 0)
  	 {
  		 stack.push(table[index].current.get_m());
  		 index = table[index].pr;
  	 }

  	 //STEP4, output the answer
  	 while(!stack.empty())
  	 {
  		 cout << stack.top() << endl;
  		 stack.pop();
  	 }
  	 cout << "success " << success_temp << endl;

   	return 1;
   }

   /////// PRIVATE HELPER FUNCTIONS //////

   //HELPER FUNCTION FOR JUG::SOLVE; returns the min_pos of table
   int find_min_pos(Dijkstra t[],unsigned int size,vector<unsigned int> cloud)
   {
  	 int min_pos = 0;
  	 while(is_there(cloud,min_pos))
  		 min_pos++;

  	 for(unsigned int i = 0; i < size; i++)
  	 {
  		 if(t[min_pos].d > t[i].d)
  		 {
  			 bool is_incloud = false;
  			 for(unsigned int j = 0; j < cloud.size(); j++)
  			 {
  				 if(i == cloud[j])
  					 is_incloud = true;
  			 }
  			 if(!is_incloud)
  				 min_pos = i;
  		 }
  	 }
  	 return min_pos;
   }

   //HELPER FUNCTION FOR JUG::SOLVE; returns the position of a specific value
   int find_pos(Dijkstra t[],int size,int a, int b)
   {
  	 for(int i = 0; i < size; i++)
  	 {
  		 if(t[i].current.get_A() == a && t[i].current.get_B() == b)
  			 return i;
  	 }
  	 return -1;
   }

   //HELPER FUNCTION FOR JUG::SOLVE; determines if number is in vector
   bool is_there(vector<unsigned int> v, unsigned int n)
   {
  	 for(unsigned int i = 0; i < v.size(); i++)
  	 {
  		 if(v[i] == n)
  			 return true;
  	 }
  	 return false;
   }

};
#endif
