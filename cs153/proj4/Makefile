#//=================================================
#//
#// Name: wong, christopher
#// Login id: wongc
#// Email: cwong030@student.ucr.edu
#//
# Assignment name: proj5
# Lab section: 001
# TA: Chih-Hsun Chou
#
# I hereby certify that the contents of this file
# are ENTIRELY my own original work.
#
#=================================================


#Makefile

OBJS = main.o
SFLS= main.cc

CC = g++
#CXXFLAGS = -g -I/usr/local/include/sgi-stl - pedantic -Wall -Werror
CXXFLAGS = -g -I/usr/local/include/sgi-stl

run:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o run -lfl -lpthread
main.o:

clean:
	rm *.o lex.c lex.yy.c yac.c source.tab.c\
	source.output source.tab.h tok.h printout.ps core run

print:
	a2ps --font-size=8pts -E C++ --line-numbers=1 -M letter Makefile main.cc heading.H -o printout.ps

size:
	cat *.cc *.H | wc
checkin:
	ci README Makefile main.cc heading.H
checkout:
	co -1 README Makefile main.cc heading.H
test:
	./testscript
