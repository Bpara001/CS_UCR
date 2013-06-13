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


void execute(const string command, const vector<string> v)
{

    char *command_char[v.size()+1];
    for(int i =0; i< v.size(); i++)
    {
        command_char[i] = const_cast<char*>(v[i].c_str());
        command_char[i+1] = NULL;
    }
    if(execvp(v[0].c_str(),command_char) < 0) errno;

}

void change_directory(string name)
{
    if(name.size() == 2) name += " ";

    //cd to directory
    int check = chdir(name.substr(3).c_str());

    //cd to root
    if(name.size() < 4) chdir(getpwuid(getuid())->pw_dir);

    //cd invalid
    else if(check == -1)
        cout <<"bash: cd: "<<(name.substr(3))<<": No such file or directory\n";
}

int main(int argc, char *argv[], char *envp[])
{

    system("clear");
    cout << "Welcome to WONG'S SHELL" << endl;

	while(true)
    {
        cout <<"? ";
        string command;
        getline(cin,command);

        if(command == "exit") break;
        else if(command.substr(0,2) == "cd") change_directory(command);
        else
        {
            vector<string> vec;
            stringstream ss(command);
            string s;
            while( ss >> s) vec.push_back(s);
            execute(argv[0],vec);
        }

        system("dirs");
    }

    cout << "\nexiting program\n" << endl;
	return 0;
}
