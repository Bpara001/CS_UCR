# A really, really simple makefile!

CXX=g++
CXXFLAGS=-g -W -Wall -Werror -pedantic -ansi -I /usr/csshare/include

# compile the program
all:
	$(CXX) $(CXXFLAGS) all_in_one.cpp -o a.out

# remove unnecessary files
clean:
	rm -rf *~ *# a.out
