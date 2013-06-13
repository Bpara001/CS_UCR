#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g

#Include
#INCLUDE=-I/usr/local/include -I/usr/csshare/include-I/usr/csshare/freetype2

#Library locations
#LIBDIRS= -L/usr/local/lib -L/usr/csshare/lib

#Libraries
#LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -lSDL_mixer

#Main program
MAIN=square.cpp

#Object files
OBJECTS=

all: $(OBJECTS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o square $(MAIN)
clean:
	rm -rf a.out *~ *#
