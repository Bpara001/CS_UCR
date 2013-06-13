# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
TEST = test.main
CLASSES = date.cpp
OUT = a.out
TESTOUT = test.out

# Compile components:
CXX = g++
CXXFLAGS = -g -W -Wall -Werror -pedantic -ansi

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS) $(INCDIR)


# Now compile it all:
all:
	$(COMPILE) $(CLASSES) $(MAIN) -o $(OUT)
test:
	$(COMPILE) $(CLASSES) $(TEST) -o $(TESTOUT)

# ... or clean it up:
clean:
	rm -rf *.out *.o *~ $(OUT) docs

# ... or generate documentation (you must have a doxygen
# congiguration file in the current directory):
docs:
	doxygen Doxyfile
