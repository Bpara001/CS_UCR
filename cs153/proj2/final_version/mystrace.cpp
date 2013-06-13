//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj2
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
//=================================================

//#include <stdio.h>
//#include <stdlib.h>
#include <syscall.h>
#include <sys/ptrace.h>
//#include <unistd.h>
#include <errno.h>

#include <sys/ptrace.h>
#include <signal.h>
#include <linux/user.h>
#include <sys/wait.h>
//#include <sys/types.h>

#include <iostream>
#include <fstream>

//#define ORIG_RAX 120
using namespace std;

//declare global constants
const int ORIG_RAX = 120;
const int LIST64_SIZE = 303;
const string LIST64_NAME = "64list.txt";


/**
*Used for reading system call files
*Parameters: name of file, size of array, array itself
*WHAT DOES IT DO: using a specific format, puts system calls in array
*/
void read_file(string const& filename,int const& size,string vec[]){

    //open file,check for errors, and get inital line
    fstream myfile;
    myfile.open(filename.c_str());
    if(!myfile.is_open()) exit(1);
    string line, temp;

    //read file and push into appropiate vector;
    getline(myfile,line);
    while(line.size() != 0){
        temp = line.substr(0,line.find(" "));
        line = line.substr(line.find(" ")+1);
        while(line.substr(0,1) == " ") line = line.substr(1);
        vec[atoi((line.substr(0,line.find(" "))).c_str())] = temp;
        getline(myfile,line);
    }
    myfile.close();
}


/**
* main executable block
* Parameters: name of executable, file needed to be traced
* Purpose: trace all system calls the following executable makes and output
*/
int main(int argc, char** argv)
{
    //check for correct inputs
    if(argc < 2){
        cerr << "Incorrect input: mystrace executable" << endl;
        exit(1);
    }

    //Put all system command numbers into string arrays
    string list64[LIST64_SIZE];
    read_file(LIST64_NAME,LIST64_SIZE,list64);

    //creates a char array with the command + arguments, seperated by spaces
    char *command_char[argc];
    for(int i = 0; i < argc; i++) {
        command_char[i] = (argv[i+1]);
        command_char[i+1] = NULL;              //end the last char with NULL
    }

    //declare varibles
    int wait_val,pid,sysnum,count = 0;

    //open temp dump file for peekuser to work properly
    ofstream myfile;
    myfile.open ("mycustomdumpmefile_08813375678.txt");

    //main logic loop
    switch (pid = fork()) {

    //when -1, it denotes an error
        case -1:
            perror("fork");
            break;

    //inital case
        case 0:
            ptrace(PTRACE_TRACEME, 0, 0, 0);
            execvp(argv[1],command_char);
            break;

    //most used case, trace children and output inital sys num
        default:

            //output inital sys number
            wait(&wait_val);
            cerr<<list64[ptrace(PTRACE_PEEKUSER,pid,ORIG_RAX,NULL)]<<endl;

            //trace children and output sys number when appropiate
            while (WIFSTOPPED(wait_val) && WSTOPSIG(wait_val) == SIGTRAP) {
                //call perror when appropriate
                if (ptrace(PTRACE_SYSCALL, pid, 0, 0) > 0)perror("ptrace");

                //output to dump for for correct sys call output
                for(int i = (ORIG_RAX-120); i < (ORIG_RAX+1); i++){
                    sysnum = ptrace(PTRACE_PEEKUSER,pid,i,NULL);
                    myfile << endl;

                //output findings to console
                    if(i == 120 && sysnum != -1 && count %2 == 0)
                        cerr<<list64[sysnum]<<endl;
                }
            //increment counter and wait
            count++;
            wait(&wait_val);
            }
    }

    //close opended file and end program
    myfile.close();
    return 0;
}
