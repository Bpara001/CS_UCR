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

using namespace std;

#define each(I) for( typeof((I).begin()) it=(I).begin(); it!=(I).end(); ++it )


int doit( const string progname, const vector<string> tok )
{
// Executes a parsed command line returning command’s exit status.
    if ( ! tok.size() || tok[0] == "" )
        return 0; // nothing to be done.

    if ( string(tok[0]) == "cd" )
    {
        chdir( tok[1].c_str() ); // can’t be done for us by a child.
        return 0;
    }

// fork child and wait if child not backgrounded
    if ( pid_t kidpid = fork() )
    {
// You’re the parent
        int status;
        if ( tok.back() != "&" )
        {
            waitpid( kidpid, &status, 0 );
            cout.flush();

// if ( WIFEXITED(status) ) { // to report on exit status.
// cout << "exit status = " << WEXITSTATUS(status) << endl;
// }
        }
        return status;
    }

// You’re the child.

// REDIRECT I/O INCLUDING THE SETTING UP OF PIPES (Part 2)
// COPY THE APPROPRIATE PORTIONS OF TOK TO A C-ARRAY OF C-STRINGS,
// CALLED, arglist

// execute the command
    string command = tok[0];
    if ( command[0] == ’~’ ) command = getenv("HOME")+command.substr(1);
    int result = execvp( command.c_str(), arglist );
// if we get here, there is an error in the child’s attempt to exec.
// REPORT ERRORS USING sterror(errno)
exit(errno);
}

int main( int argc, char* argv[], char* envp[] )
{
    while ( ! cin.eof() )
    {
        cout << "? " ;
        string temp;
        getline(cin,temp);

        if ( temp == "exit" )
            break;

        vector<string> v;

        { // split temp (at white space) into v
            stringstream ss(temp);
            string s;
            while( ss >> s )
                v.push_back(s);
        }


        doit( argv[0], v );
    }

    cout << "exit" << endl;
    return 0;
}
