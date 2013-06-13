Program passes all the tests from the sample main.

Assignment specs DID NOT state it had to be super efficent;
give the program about 5-10 seconds to load it is a little slow.
I used frequently used STL <vector> to store information,
but i did use the STL <list> for storing neighbors.
Uses the STL <stack> to output the solution.

Two custom made classes: 

-CONTAINERS: 
	stores the two jug's current water levels, 
	max capacity of each jug,
	the distance(cost) to get to the object,
	the method to get to the object (eg.fillA)
-DIJKSTRA:
	a simple data structure containing:
	containers current; describes the current jugs
	int pr; the index to the previous
	int d; the distance(cost)
	vector<Containers> edge; the edges of that vertex
	
	
The algoritum used for solving the shortest path was entierly 
based off of Dijkstra's algorithm

outline of algoritum:
	-create a blank table with apporipate size
	-populate the table with the vertex's and its neighbors w/ edges
	-use the 'greedy algoritum' take the shortest path of each
	-once table is complete, create a stack
	-find the intended destination and push the values onto the stack
	-pop and output the stack and you have your answer.

for a more detailed description, 
http://tinyurl.com/2frk3fx

fun having you as a TA. Have a great summer.
=]

