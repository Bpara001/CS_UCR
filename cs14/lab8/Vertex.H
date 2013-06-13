#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

using namespace std;

class Vertex {
public:

	string label;
	int distance;
	list<pair<int, int> > neighbors;

	/* implement constructor*/
	Vertex()
	:label(""),distance(999)
	{
	}

	Vertex(string l)
	:label(l),distance(999)
	 {
	 }

	~Vertex()
	{
	}


};

#endif /* VERTEX_H_ */
