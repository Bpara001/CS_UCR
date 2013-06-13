//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj5
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

Readme file

DISCLAMER: 95% of this CODE IS COPIED FROM proj 4 OR COPIED FROM NOTES IN CLASS/LAB

I. HOW TO USE
 1. Open the terminal
   ->right click on desktop-> click on 'open terminal'
 2. Untar proj using terminal
   -> ex "tar -xzvf proj5.tgz"
 3. To compile, type 'make' into terminal
   -> ex "make"
   -> this will create the exectuable, 'run'
            --> IF DOES NOT COMPILE: type 'make clean' and redo step 3
 4. To execute type the exectuable's name,
   -> ex "run"
 5. You will now see the output on the terminal


II. WHAT IS IT?
A minor varian of the exercise at the end of Subsection 5.2.5 on page 82 of the
notes. It adds an operation, tail_wait() to the condition class, and implements
the class sharableLock using tail waiting on okToShare. It implements a thread
safe version of the STL contaier class set by encapsulating set in
a Mulitor, in a manner similar to the way we encapsulated queue in a Monitor.
Insertions and deletions require exclusive access,while find() and size() operation allow shared acces.
RUNS UP TO 35 (in terminal you will see 34) TICKS.

III.How did you make it?
using the puesdo instructions supplied by the professor, I followed them
and completed the assignment.
