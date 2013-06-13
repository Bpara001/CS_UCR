#Names: Chris Wong , Hans wun
#Login:  wongc, wunh
#Email: cwong030@student.ucr.edu , wunh001@ucr.edu
#Lab Section: 022
#Assignment: Lab 7
#I acknowledge all content is original.
#####################################################################

#Variable to hold lab number
LABNUM=7

#Variable to hold first lastname
LASTNAME1=Wong

#Variable to hold second lastname
LASTNAME2=Wun

#Variable of Post Script generated
PSPRINT=lab$(LABNUM)_$(LASTNAME1)_$(LASTNAME2).ps

#Variables
CXX=g++ -ansi -pedantic

#Files to be included in the PS/PDF print
FILES= Makefile decoder_gen.cc  mux_gen.cc *.vhd

#ALL: echos incorrect usage message and correct syntax instead
all:
	@echo Incorrect usage, Type "make mux" or "make decoder"

#Clean: a basic clean command that wipes all junk files, or all files that
#can be created by this makefile.
clean:
	rm -f *~ *.vhd mux_gen decoder_gen


#Print files to a .ps document
print:
	a2ps -M letter --line-numbers=1 -o $(PSPRINT) $(FILES)

#mux: compiles ux_gen.cc and runs it. the user will be prompted to input the
#the number of multiplexer inputs. A mux_NUMINPUTS_1.vhd file will be generated
#in this same directory. As part of the filename, NUMINPUTS is the nubmer of
#inputs that the user passed to the executable.
mux: mux_gen.cc
	$(CXX) -o mux_gen mux_gen.cc && ./mux_gen

#decoder: compiles decoder_geri.cc and runs it. the user will be prompted to
#input the decoder input width.A decoder_umbits.vhd wll be generated in this
#same directory. As part of the filename, numbits is the bitwidth as
#specified by the user earlier
decoder: decoder_gen.cc
	$(CXX) -o decoder_gen decoder_gen.cc && ./decoder_gen


