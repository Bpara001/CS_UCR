/*
 * cs014_10su1 lab 8
 * Graph.H
 */


#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "Vertex.H"
#include <queue>

/*
 * num_v
 * num_e
 * for 1  to num_v
 * 	label = read label
 * 	vertices.push_back(Vertex(label));
 * 	m[label] = i;
 * for 1 to num_e
 * 	u = read source label
 * 	v = read destination label
 * 	w = read weight
 * 	vertices[m[u]]neighbors.push_back(par<int,int>(m[v],w);
 * 	vertices[u's index] neighbors.push_back(p);
 *
 * Graph Class: map<string,int> m;
 *
 * void Graph::write_dot()
 * {
 * ofstream ofs("output.dot"_;
 *(check file open if not error message and exit)
 *check ofs << "digraph G{" << endl;
 *for(unsiged int i = 0; i< vertices.size(0; i++))
 *		ofs << vertices[i].label << "
 *
 *	output.dot
 *	micky_mouse[colol =red, paripheries = 3, style = filled, label = "mikey_mouse"];
 *
 *
 *BFS
 *Queue 9;
 *initiate all nodes dist = infiinity;
 *set source node dist = 0;
 *q.push(source node)
 *while(!q.empty())
 *		Node n = q.top;
 *		q.pop;
 *		visit n's neighbors;
 *		update weights, push neigbhor in q
 */

using namespace std;

class Graph {

private:
	vector<Vertex> vertices;
	map<string, int> m;

public:
	Graph()
	{
	}

	/* implement overloaded constructor */
	Graph(string filename)
	{
		ifstream ifs(filename.c_str());

		if(!ifs)
		{
		   cerr << "Input file not found." << endl;
		   exit(1);
		}

		string s;
		int num_v;
		int num_e;

		ifs >> num_v;
		ifs >> num_e;

		for(int i = 0; i < num_v; i++)
		{
			//getline(ifs,s);
			ifs >> s;

			vertices.push_back(Vertex(s));
			m[s] = i;
			cout << s;
			cout << " " << m[s] << endl;
		}

		for(int i = 0; i < num_e; i++)
		{
			string u;
			string v;
			int w;
			ifs >> u;
			ifs >> v;
			ifs >> w;
			cout << "m[u]:" << m[u] << ":m[v]:" << m[v] << ":weight:" <<  w <<  endl;

			vertices[m[u]].neighbors.push_back(pair<int,int>(m[v],w));
			//vertices[u's index] neighbors.push_back(p);
		}
	}

	~Graph()
	{
		while(!vertices.empty())
		{
			vertices.pop_back();
		}
	}

	/* implement build_graph */
	void build_graph(ifstream& ifs)
	{

	}

	/* implement output_graph */
	void output_graph()
	{
		ofstream ofs ("output.dot");
		ofs << "digraph G { " << endl;
		ofs << "bgcolor = black" << endl;
		for(unsigned int i = 0; i < vertices.size(); i++)
		{
			ofs << i << "[color = yellow, paripheries = 3, style = filled, label =\""
					<< vertices[i].label << "\"]" << endl;
		}
		for(unsigned int i = 0; i < m.size(); i++)
		{
			while(!vertices[i].neighbors.empty())
			{
				ofs << i << "->" << vertices[i].neighbors.front().first;
				ofs << "[color=white];" << endl;
				vertices[i].neighbors.pop_front();
			}
		}

		ofs << "}" << endl;
		system("dotty output.dot");

	}

	/* implement bfs */
	void bfs()
	{
		queue<Vertex> q;
		for(unsigned int i = 0; i < vertices.size(); i++)
		{
			vertices[i].distance = 999;
		}

		vertices[0].distance = 0;
		q.push(vertices[0]);
			while(!q.empty())
			{
				Vertex u = q.front();
				q.pop();
				//for(const_iterator ci = u.neighbors.begin(); ci != u.neighbors.end(); ++ci)
				{
					//if(u.neighbors.)
				}
			}


	}


};

#endif /* GRAPH_H_ */
