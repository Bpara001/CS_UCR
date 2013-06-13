#Compiler
GCC = g++

#Compiler Flags
FC = -c

FM =

OBJECTS = employee.o manager.o


all: $(OBJECTS) main.cpp
	 $(GCC) $(FM) main.cpp $(OBJECTS)

employee.o: employee.h employee.cpp
	$(GCC) $(FC) employee.cpp

manager.o: manager.h manager.cpp employee.o
	$(GCC) $(FC) manager.cpp

clean:
	rm -rf *.o a.out *~ *#

