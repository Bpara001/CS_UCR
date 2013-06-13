//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn3b
// Lab section: 022
// TA: Busra Celikkaya
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================
#include<iostream>
#include<sys/types.h>
#include<vector>
#include<errno.h>
#include<stdlib.h>
#include<string>
#include<cassert>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sstream>
#include <pwd.h>
#include <errno.h>
#include<fstream>
using namespace std;


//The 'doit' function, it executes the user command with or without arguments
int execute( string command, vector<string> v)
{

    if(!v.size() || v[0] == "") return 0;   //do nothing if command is null
    pid_t kidpid;
    int mypipe[2];
    int bytes;
    char chars[80];

    //make sure the program continues after first instance
    if(kidpid = fork())
    {
        //support operations running on  the background
        int status;
        if(v.back() != "&")
        {
            waitpid(kidpid,&status,0);
            cout.flush();
        }
        return status;
    }

    //output eerror if an error occured
    if(kidpid == -1)
    {
        perror("fork");
        exit(1);
    }
    //output & input redirection and setting up pipes
    for(unsigned int i = 0; i < v.size(); i++)
    {
        //check to see if speical characters are used
        if(v[i]==">"||v[i]==">>"||v[i]=="<"||v[i]=="2>")
        {
           if(v[i] == ">")freopen(v[i+1].c_str(),"w",stdout); //output to file
           else if(v[i] ==">>")freopen(v[i+1].c_str(),"a",stdout); //append to file
           else if(v[i] =="<")freopen(v[i+1].c_str(),"r",stdout); //read from file
           else if(v[i] =="2>") freopen(v[i+1].c_str(),"w",stdout); //error to file
           v.pop_back();        //pop the contents of the last two elemetns
           v.pop_back();
        }

    //Making the pipe
        if(v[i].substr(0,1) =="|")
        {
            //makes a chlid
            pipe(mypipe);           //calls pipe function
            if(kidpid== 0)          //for left side of argument
            {
                close(1);
                dup(mypipe[1]);         //duplicates a file descriptor
                close(mypipe[1]);       //clsoes other pipses
                close(mypipe[0]);
                vector<string>vtemp;    //creates a temp vec of strings
                for(unsigned int j = 0; j < i;j++) vtemp[j] = v[j];
                execute(command,vtemp); //recursively calls execute on left side
            }
            kidpid = fork();
            if(kidpid == 0)             //for right side of argument
            {
                close(1);
                dup(mypipe[1]);         //duplicates a file descriptor
                close(mypipe[1]);       //closes other pipes
                close(mypipe[0]);       //closes other pipes
                vector<string>vtemp;    //creates a temp vec of strings
                for(unsigned int j = i+1; j < v.size();j++) vtemp[j] = v[j];
                execute(command,vtemp); //recursively calls execute on right side
            }
        }
    }


       //creates a char array with the command + arguments, seperated by spaces
    char *command_char[v.size()+1];
    for(unsigned int i =0; i< v.size(); i++)
    {
        command_char[i] = const_cast<char*>(v[i].c_str());
        command_char[i+1] = NULL;              //end the last char with NULL
    }

    //calls execvp function to find and execute the command
    //if command was not found, outputs errror message
    string tempcommand = v[0];
    if(v[0] == "~") tempcommand = getenv("HOME")+tempcommand.substr(1);
    if(execvp(tempcommand.c_str(),command_char) < 0)
    {
        fprintf(stderr,strerror(errno));        //output error message
        cout << endl;
    }
}

//changes the directory if 'cd' is inputted
void change_directory(string name)
{
    //need to add extra space if size is 2
    if(name.size() == 2) name += " ";

    //cd to directory
    int check = chdir(name.substr(3).c_str());

    //cd to root
    if(name.size() < 4) chdir(getpwuid(getuid())->pw_dir);

    //cd invalid, output error message
    else if(check == -1)
        cout <<"bash: cd: "<<(name.substr(3))<<": No such file or directory\n";
}

//MAIN function
int main(int argc, char *argv[], char *envp[])
{
    //clears the terminal and outputs introduction message
    char c = '\0';
    system("clear");
    cout << "Welcome to WONG'S SHELL" << endl;

	while(c != EOF)
    {
        cout <<"? ";
        string command;
        getline(cin,command);

        //exits program if user inputs exit
        if(command == "exit") break;

        //calls cd function if user inputs cd
        else if(command.substr(0,2) == "cd") change_directory(command);

        //populates a vector with the command, sepearted by spaces
        else
        {
            vector<string> vec;
            stringstream ss(command);
            string s;
            while( ss >> s) vec.push_back(s);
            execute(argv[0],vec);
        }

        //displays cirrent directory
        system("dirs");
    }

    cout << "\nExiting Program...\n" << endl;
	return 0;
}
