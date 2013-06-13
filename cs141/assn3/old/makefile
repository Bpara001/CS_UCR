# to be completed ...
# remember to use tab for rules, not spaces!

#Compiler
CXX = g++

#Compiler Flags
CXXFLAGS = -g -W -ansi -pedantic

# precompiled code to include
OBJECTS = jug.o Dijkstra.o Vertex.o Containers.o

all: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

jug.o: jug.h Vertex.h Dijkstra.h
	$(CXX) $(CXXFLAGS) -c -o jug.o jug.h

Dijkstra.o: Dijkstra.h Containers.H
	$(CXX) $(CXXFLAGS) -o Dijkstra.o -c Dijkstra.h

Vertex.o: Vertex.h Containers.h
	$(CXX) $(CXXFLAGS) -o Vertex.o -c Vertex.h

Containers.o: Containers.h
	$(CXX) $(CXXFLAGS) -o Containers.o -c Containers.h

# remove unnecessary files
clean:
	-rm -rf *~ *.o a.out
