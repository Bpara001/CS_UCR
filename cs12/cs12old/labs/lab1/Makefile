#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -Wall -ansi -pedantic

#Include locations
INCLUDE=-I/usr/local/include -I/usr/csshare/include -I/usr/csshare/pkgs/instinct_graphics/include -I/usr/csshare/freetype2

#Library locations
LIBDIRS=-L/usr/lib -L/usr/local/lib -L/usr/csshare/lib -L/usr/csshare/pkgs/instinct_graphics/lib

#Libraries
LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -linstinct -lSDL_mixer

all: triangle box vector cube

triangle: triangle.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out triangle.cpp
box: box.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out box.cpp
vector: vector.cpp
	$(CXX) $(CXXFLAGS) -o a.out vector.cpp
cube: cube.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out cube.cpp
clean:
	rm -rf a.out *~ *#
