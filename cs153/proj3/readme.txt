//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj3
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
//=================================================

Readme file

proj3.tgz includes:
-popen.H        <- file containing inline functions
-testbench.cpp  <- file containing tests for inline functions
-Makefile       <- script to compile testbench.cpp
-readme.txt     <- file containing instructions

Important notes:

-popen.H includes only <iostream> and <sys/wait.h> as headers
b/c thats all i need for the functions to work (everything else is overkill)

-when using the function, only call Popen once
(dont have Popen("ls *", "r"), and Popen("wc","w") in the same file),
 otherwise there are random glitches


I. HOW TO USE
 1. Open the terminal
   ->right click on desktop-> click on 'open terminal'
 2. Untar proj using terminal
   -> ex "tar -xzvf proj3.tgz"
 3. To compile, type 'make' into terminal
   -> ex "make"
   -> this will create the exectuable, 'a.out'
 4. To execute type the exectuable's name in the terminal
   -> ex "a.out"
 5. You will now see the output on the terminal


II. WHAT IS IT?
Two Inline functions packaged inside "popen.h",

Popen:
-PURPOSE: Popen opens a process by creating a pipe, forking,and invoking shell
-Parameters: string containg a shell command line, type argument may specify
only reading or writing, with "w" and "r" respectivley
-Returns: FILE pointer

Pclose:
-Purpose: pclose function waits for the associated process to terminate.
-Parameters: File pointer needed to be closed
-Returns: returns the exit status of the command as returned by wait4()


III.How did you make it?
 -opend the process by created a pipe, forking, then invoking shell on children
 -see Popen.H for in-depth commentary
