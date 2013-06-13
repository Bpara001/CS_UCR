# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = date.o
OUT = a.out

# Compile components:
CXX = g++
FLAGS = -W -Wall -Werror -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

# The directory where ccc_win library header files reside:
# NONE NEEDED FOR THIS ASSIGNMENT
INCDIR = 

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

# Libraries & where to find them:
# NONE NEEDED FOR THIS ASSIGNMENT
LIBS = 
LIBDIRS = 

# Now compile it all:
all: $(OBJECTS)
	$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT)

date.o: date.h
	$(COMPILE_ONLY) date.cpp

# ... or clean it up:
clean:
	rm -rf *.out *.o *~ $(OUT) docs

# ... or generate documentation (you must have a doxygen
# congiguration file in the current directory):
docs:
	doxygen Doxyfile
