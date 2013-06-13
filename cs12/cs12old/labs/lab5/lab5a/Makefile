CXX = g++
CXXFLAGS = -g -W -Wall -Werror -pedantic -ansi
OBJECTS = employee.o manager.o

all: 	$(OBJECTS) employee_test.o
	$(CXX) $(CXXFLAGS) -o employee_test.out employee_test.o $(OBJECTS)

employee_test.o: employee.h manager.h
	$(CXX) $(CXXFLAGS) -c employee_test.cpp

employee.o: employee.h employee.cpp
	$(CXX) $(CXXFLAGS) -c employee.cpp

manager.o: manager.h manager.cpp employee.h
	$(CXX) $(CXXFLAGS) -c manager.cpp

clean:
	rm -rf *.out *.o *~
