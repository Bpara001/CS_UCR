# to be completed ...
# remember to use tab for rules, not spaces!

CXX = g++
CXXFLAGS = -g -Wall -W -Werror -ansi -pedantic

# precompiled code to include
OBJECTS = l_list.o node.o

all: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

l_list.o: l_list.cpp l_list.h node.h
	$(CXX) $(CXXFLAGS) -o l_list.o -c l_list.cpp

node.o: node.cpp node.h
	$(CXX) $(CXXFLAGS) -o node.o -c node.cpp

# remove unnecessary files
clean:
	-rm -rf *~ *.o a.out
