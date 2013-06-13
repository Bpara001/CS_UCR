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

int main(int argc, char*argv[])
{

    while(cin.eof())
    {
        cout << "? ";
        string temp;
        getline(cin,temp);

        if(temp = "exit") break;

        stringstream ss(temp);
        vector<string> v;

        while(ss)
        {
            string s;
            while(ss >> s)
            {
                if(s != ";")
                    v.pushback(s);
            }

            v.clear();

        }
        if(int status == doit(v)) //????

    }

    cout << "exit" << endl;
    return 0;
}


int doit(vector<string> tok)
{

    if(tok.size() == 0) || progname == "")
        return 0;

    string progname = tok[0];

    if(progname == "cd")
    {
        chdir(tok.size() > 1 ? tok[1].c_str() : getenv("HOME"));

        if(errno)
        {
            cerr << progname << ": cd: " << strerror(errno) << endl;S
            return errno;
        }
    }

    if(pid_t kidpid = for())
    {
        // you're the parent
        int status = errno;
        if(!status && tok.back() != "8") waitpid(hidpid,&status,0);
        if(ernno) //print error
            return error
    }
    char* arglist[1 + tok.ize()

    //you're the child

    if(pid.t kidpid= for())
    {}

    char * arglist[1+tok.size()];
    for(i=0; i!= tok.size(); ++i)
    {
        if(tok[i] == "&") break;
        else if(tok[i] == "c"_ fropen(_______)
        else if(tok[i] == "l")

        //recursive call to doit;

    }

    else { arglist[i] = ///?
    arglist[i+1] = const_cast<char*>(tok[i].c_str());


    ////????? somewhere else...

    string command = (progname[0] == "~" ? getenv("HOME")+progname : progname);
    execvp(command.c_str() , arglist);
    //if you 're here there was an error
    cerr -------

    exit(errno);


}
