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
OBJECTS=

all: $(OBJECTS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out $(MAIN)
clean:
	rm -rf a.out *~ *#
