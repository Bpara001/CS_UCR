#censorship assignment

CXX= g++
CXXFLAGS= -g -Wall -W -Werror -ansi -pedantic

#object files that will be linked to main
OBJECTS= sentence.o bad_word.o


all: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

sentence.o: sentence.cpp sentence.h bad_word.h
	$(CXX) $(CXXFLAGS) -o sentence.o -c sentence.cpp

bad_word.o: bad_word.cpp bad_word.h
	$(CXX) $(CXXFLAGS) -o bad_word.o -c bad_word.cpp	
clean:
	rm -rf *~ *.o a.out
