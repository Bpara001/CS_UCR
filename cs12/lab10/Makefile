# to be completed ...
# remember to use tab for rules, not spaces!

CXX = g++
CXXFLAGS = -g -Wall -W -Werror -ansi -pedantic

# precompiled code to include
OBJECTS = music_collection.o tune.o

all: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

music_collection.o: music_collection.cpp music_collection.h tune.h
	$(CXX) $(CXXFLAGS) -o music_collection.o -c music_collection.cpp

node.o: tune.cpp tune.h
	$(CXX) $(CXXFLAGS) -o tune.o -c tune.cpp

# remove unnecessary files
clean:
	-rm -rf *~ *.o a.out
