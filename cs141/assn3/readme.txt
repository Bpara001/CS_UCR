NOTE: i've already done this assignment in cs14
I asked the professor if i could use the same code from that assignment
and he said it was okay
I've done a few minor tweaks to the code but the majority is the same as my old code.


HOW TO USE:
include jug.h in your test harness
ex, #include "jug.h"
To compile, use g++ compiler without any flags
ex, g++ test.cpp


Program passes all the tests from the sample main in 3.7 seconds
(i assumed we could not make a makefile)
Total of 4 classes shoved into one .h file

Used STL <vector> to store information,
but i did use the STL <list> for storing neighbors.
Uses the STL <stack> to output the solution.

Classes:

-CONTAINERS:
	stores the two jug's current water levels,
	max capacity of each jug,
	the distance(cost) to get to the object,
	the method to get to the object (eg.fillA)

-VERTEX:
    creates a node for the graph containg a container

-DIJKSTRA:
	a simple data structure containing:
	containers current; describes the current jugs
	int pr; the index to the previous
	int d; the distance(cost)
	vector<Containers> edge; the edges of that vertex
-JUG
    makes the graph and runs dijkstra on it

The algoritum used for solving the shortest path was entierly
based off of Dijkstra's algorithm

outline of algoritum & program

creating graph:
	-for each new vertex,
	-Determine if it is necessary to create a new vertex
	-Push back children if necessary
	-repeat until no more children can be created	

finding shortest path:
	-create a blank table with apporipate size
	-populate the table with the vertex's and its neighbors w/ edges
	-use greedy algoritum take the shortest path of each
	-once table is complete, create a stack
	-find the intended destination and push the values onto the stack
	-pop and output the stack and you have your answer.




