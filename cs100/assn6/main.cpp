//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn6
// Lab section: 022
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <dirent.h>
using namespace std;

vector<string> used;
vector<pair<string,string> > defined;  //vector of macros that are #DEFINE
vector<string> paths;  //vector of the different paths that it needs to check

//! gets the local enviromental varible called UCRINCLUDE, puts into vector
void getenv()
{
    string s = getenv("UCRINCLUDE");
    while(s.find(":") != -1)
    {
        paths.push_back(s.substr(0,s.find(":"))); //push back up to first :
        s.erase(0,s.find(":")+1);   //cut up to first :
    }
    paths.push_back(s);     //push back last value
}

//! Helper function, looks for specific file(file) in directory (pathname),
//! returns string (s) if complete directory is found
//! otherwise, returns emtpy string ("")
void findFile(string pathname,string file,string &s)
{
    DIR *dir;
    struct dirent *entry;
    if( dir=opendir(pathname.c_str()) )
    {
        while(entry = readdir(dir))
        {
            if(strcmp(entry->d_name, ".")!=0&&strcmp(entry->d_name, "..")!=0)
                if(entry->d_name == file)
                {
                    s = pathname + "/" + file;
                    return;
                }
                else
                    findFile(pathname+ "/" + entry->d_name,file,s);
        }
        closedir(dir);
    }
}

//!Analyzes the file and adds apporipate extensions
void Analyzefile( const string &filename)
{
    ifstream file(filename.c_str());

    //Check1: make sure file is valid
    if(file.fail())
    {
        cerr <<"cannot open \""<<filename<<"\"; file does not exist" << endl;
        return;
    }

    //check each line and put into the vector
    string s;
    while(file)
    {
    getline(file,s);
///////////CASE#1: if we find '//' ////////////////////////////////////////////
        if(s.find("//") != -1)
        {
            //do nothing;
            cout << s.substr(0,s.find("//"));
        }

//////////CASE#2: if we find '/*'//////////////////////////////////////////////
        else if(s.find("/*") != -1)
        {
            cout << s.substr(0,s.find("/*")) << endl;
            bool flag = true;
            while(file && flag)
            {
                getline(file,s);
                if(s.find("*/") != -1)
                {
                    flag = false;
                }
            }
            if(s.size() != 0)
                cout << s.substr(s.find("*/")+2) << endl;
        }

///////////CASE#3 if we find '#include'////////////////////////////////////////
         else if(s.substr(0,9) == "#include ")
        {
            //if we find '#include <...>'
            if(s.substr(9,1) == "<")
            {
                string fullstring;
                bool flag = false;
                string argument = s.substr(10,s.find(">")-10);

                //remove the '/' characters from argument
                while(argument.find("/") != -1)
                    argument = argument.substr(argument.find("/")+1);

                //check to see if file is already used
                for(int i = 0; i < used.size(); i++)
                    if(used[i] == argument) flag = true;

                //if library has not been used,
                if(!flag)
                {
                    //check c++ these folders in this order
                    bool returnflag = true;
                    int l = 0;
                    while(returnflag)
                    {
                        findFile(paths[l]+"/",argument,fullstring);
                        if(fullstring != "") returnflag = false;
                        l++;
                    }

                    //Recursivly  call function, add current librrary
                    used.push_back(argument);
                    Analyzefile((fullstring));
                }
            }
            //if we find ' #include "..." '
            else if(s.substr(9,1) == "\"")
            {
                Analyzefile(s.substr(10,s.size()-11));
            }
        }

//////////CASE#4 if we find '#define'//////////////////////////////////////////
        else if(s.size()>7&&s.substr(0,8)=="#define ")
        {
            //Push into defined words
            pair<string,string> def(s.substr(8,s.find(" ",9)-8),s.substr(s.find(" ",9)+1));
            while(def.second.substr(def.second.size()-1,1) == "\\")
            {
                def.second.erase(def.second.size()-1,1);
                string ts1;
                getline(file,ts1);
                def.second = def.second + "\n" + ts1;
            }

            defined.push_back(def);
            //(s.substr(8,s.find(" ",9)-8),s.substr(s.find(" ",9) +1)));
        }

//////////CASE#5 if we find nothing spectacular////////////////////////////////
        else
        {
            //break s up into a vector seperated by spaces,
            vector<string>temp;
            while(s.find(" ") != -1)
            {
                temp.push_back(s.substr(0,s.find(" ")));
                s.erase(0,s.find(" ")+1);
            }
            temp.push_back(s); //pushback last string

            //check each string to see if it #define 'ed, & replace if found
            for(int i = 0; i < defined.size(); i++)
                for(int j =0; j < temp.size(); j++)
                    if(temp[j] == defined[i].first)temp[j] = defined[i].second;

            //output contents of space seperated strings
            for(int k =0; k< temp.size(); k++) cout << temp[k] << " ";
            cout << endl;
        }
    }
    file.close();  //close the file
}

//!////////////////////////////
//!/// MAIN FUNCTION //////////
//!////////////////////////////
int main(int argc, char ** argv)
{
	//Check for correct input
	if(argc != 2)
	{
		cerr<<"\nError:<executable> <SourceFile>"<<"\nex:a.out main.cpp"<<endl;
		exit(1);
	}
	getenv();  //populate
    Analyzefile(argv[1]);  //output file with appropriate extensions
    return 0;
}
