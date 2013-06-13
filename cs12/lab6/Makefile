#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -Wall -Werror -ansi -pedantic

#Include
INCLUDE=-I/usr/local/include -I/usr/csshare/include -I/usr/csshare/pkgs/instinct_graphics/include -I/usr/csshare/freetype2

#Library locations
LIBDIRS=-L/usr/lib -L/usr/local/lib -L/usr/csshare/lib -L/usr/csshare/pkgs/instinct_graphics/lib

#Libraries
LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -linstinct -lSDL_mixer

#Main program
MAIN=main.cpp

#Object files
OBJECTS=jshape.o jrectangle.o jsquare.o jtriangle.o

all: $(OBJECTS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out $(MAIN) $(OBJECTS)
jsquare.o: jrectangle.o jsquare.cpp jsquare.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jsquare.o -c jsquare.cpp
jrectangle.o: jshape.o jrectangle.cpp jrectangle.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jrectangle.o -c jrectangle.cpp
jtriangle.o: jshape.o jtriangle.cpp jtriangle.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jtriangle.o -c jtriangle.cpp
jshape.o: jshape.h jshape.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o jshape.o -c jshape.cpp
clean:
	rm -rf *.o a.out *~ *#
