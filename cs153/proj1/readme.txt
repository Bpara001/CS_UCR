//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj1
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

Readme file

I. HOW TO USE (easy as 1,2,3!)
 1. Untar proj using console
 2. type 'make' into console to compile
 3. type 'observer 'period' 'interval'' into console; ex, observer 2 60


II. WHAT IS IT?
Observer is a c++ program that creates periodic snapshots of the kernel's
state for a given interval.

It takes two command-line arguemnts, period and interval, the first of which
tells the time betweensnapshots and the second of which tells the duration
of the obersation period

The snapshots are then printied out to the program's standard output file(cout)
and contain the following information in the respective order:
-CPU type and model
-Kernal version
-Amoutn of time since was last booted
-amount of time CPU has been in userode,systemmode,idlemode
-number of disk requests made for disk sda
-number of context switches
-time when the system was last booted
-number of processes that have been created since last boot
-amount of memory configured into the system
- amount of memory currently available.


III.How did you make it?
 -creates observer class to hold values
 -by calling 'report' functoin of observer, observer calculates and prints
 all necessary variables
 -see main.cpp for in-depth commentary
