#lab5

#Variables
CXX = g++
CXXFLAGS = -W -Werror -Wall -ansi -pedantic
OBJECTS = intvector.o

#targets
all: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

intvector.o: intvector.cpp intvector.h
	$(CXX) $(CXXFLAGS) -o intvector.o -c intvector.cpp

clean:
	rm -f *~ *.o a.out