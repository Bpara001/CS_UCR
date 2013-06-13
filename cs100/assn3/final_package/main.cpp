//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn3
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
using namespace std;


//The 'doit' function, it executes the user command with or without arguments
int execute(const string command, const vector<string> v)
{
    //creates a fork
    if(pid_t kidpid = fork())
    {
        int status;
        if(v.back() != "&")
        {
            waitpid(kidpid,&status,0);
            cout.flush();
        }
        return status;
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
    if(execvp(v[0].c_str(),command_char) < 0)
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
