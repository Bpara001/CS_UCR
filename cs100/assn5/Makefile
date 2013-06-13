#
# Name: wong, christopher
# Login id: wongc
# Email: cwong030@student.ucr.edu
#
# Assignment name: assn3
# Lab section: 022
# TA: Busra Celikkaya
#
# I hereby certify that the contents of this file
# re ENTIRELY my own original work.
#
#=================================================




#Compiler
CXX=g++

#Compiler Flags
CXXFLAGS=-g -W -ansi

#Include
INCLUDE=-I/usr/local/include -I/usr/csshare/include -I/usr/csshare/freetype2

#Library locations
LIBDIRS=-L/usr/lib -L/usr/local/lib -L/usr/csshare/lib

#Libraries
LIBS=-lSDL -lSDL_image -lGL -lfreetype -lz -lSDL_mixer

#Main program
MAIN=main.cpp

#Object files
OBJECTS=

all: $(OBJECTS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBDIRS) $(LIBS) -o a.out $(MAIN) $(OBJECTS)

clean:
	rm -rf *.o a.out *~ *#
