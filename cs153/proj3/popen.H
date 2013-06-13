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

#ifndef POPEN__H__
#define POPEN__H__

#include <iostream>
#include <sys/wait.h>

/**
* PURPOSE: Popen opens a process by creating a pipe, forking,and invoking shell
* Parameters: char pntr containg a shell command line, type argument may specify
* only reading or writing, with "w" and "r" respectivley
* Returns: FILE pointer
*/
inline FILE* Popen( char *command, char *type){

    //Decloare file ptr, ints, pipe, and initialize pipe_ends and pipe
    int mypipe[2];
    int p_end = (type == "w" ? 1:0); // parent end = 1 when 'w', else = 0
    int c_end = 1 - p_end;           //child = opposite ( 0 or 1 ) of parent
    pipe(mypipe);

    //Main logic switch cases
    switch (pid_t pid = fork()) {  //initialze the fork

    case -1:    //Handle ERROR case(s) (when pid == -1)
        perror("fork");
        exit(-1);                           //kill program
        break;

    case 0:     //Handle CHILD case(s) (when pid == 0)
        close(mypipe[p_end]);
        dup2(mypipe[c_end], c_end);
        execlp("/bin/sh", "sh", "-c", command, NULL); //call shell
        perror("execlp");       //if problem with execlp, exit and throw error
        exit(-1);
        break;

    default:    //Handle PARENT case (when pid != 0 && pid != -1)
        close(mypipe[c_end]);
        dup2(mypipe[p_end], p_end);
    }
    close(mypipe[0]);           //close the pipes just in case
    close(mypipe[1]);
    return fdopen(p_end,type);   //return the file
}

/**
*Purpose: pclose function waits for the associated process to terminate.
*Parameters: File pointer needed to be closed
*Returns: returns the exit status of the command as returned by wait4()
*/
inline int Pclose(FILE * f){

    int temp = fclose(f);
    int wait_val;
    wait(&wait_val);
    return temp;   //let fclose do the rest of the work
}


#endif
