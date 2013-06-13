#lab4

#Variables
CXX=g++
CXXFLAGS=-W -Werror -Wall -ansi -pedantic
OBJECTS=person.o

#targets
all: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -o person.o -c person.cpp

clean:
	rm -f *~ *.o a.out
