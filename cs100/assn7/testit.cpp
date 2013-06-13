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
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//! Helper function, finds all filenames within specific directory
//! Puts all found names into a vector of strings
void getFile(string pathname,vector<string> &v)
{
    DIR *dir;
    struct dirent *entry;
    if( dir=opendir(pathname.c_str()) )
    {
        while(entry = readdir(dir))
            if(entry->d_name != "." && entry->d_name != "..")
                v.push_back(entry->d_name);
        closedir(dir);
        v.erase(v.begin(),v.begin()+2);
        sort(v.begin(),v.end());
    }
}

//!//////////////////
//! MAIN FUNCTION ///
//!//////////////////
//! Program: testit, accepts arguments testit progname directorypath
int main(int argc, char** argv)
{
    //Check#1: for correct arguments
    if(argc != 3){
        cerr<< "Invalid arguments: testit programname directorypath" << endl;
        exit(1);}
    //Declare some useful constants,fill vector of filenames
    string prog = argv[1];
    string dpath = argv[2];
    vector<string> v;
    getFile((dpath + "/inputs/"),v);
    string tempfile = "T_zxycw1337Testit_tempDiffData.txt";

    //Check#2: for at least 1 input file
    if(v.empty()){
        cerr<<"No input files." << endl;
        exit(1);}

    //get current directory
    char *path=NULL;
    size_t size;
    path=getcwd(path,size);
    string currentpath = path;

//////1.Clear the folders testfiles/outputs and testfiles/errs
    system(("rm -rf "+dpath +"/outputs").c_str());
    system(("rm -rf "+dpath +"/errs").c_str());
    system(("mkdir "+dpath +"/outputs").c_str());
    system(("mkdir "+dpath +"/errs").c_str());

/////////////////////////////////////////////////////////////////////////
/////Repeat executing the program for all input files in testfiles/inputs
/////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < v.size(); i++)
    {
//////////2.execute the program (./quicksort < testfiles/intputs/tst1.txt)
        string inputs = " < "+dpath+"/inputs/"+v[i];

//////////3.Redirect its output. (stdout to testfiles/outputs/tst1.txt and stderr
        //to testfiles/errs/tst1.tt
        string output =" > "+dpath+"/outputs/"+v[i];
        string outerr =" 2> "+dpath+"/errs/"+v[i];
        system((prog+inputs+output+outerr).c_str());

//////////4.Run diff command to compare testfiles/outputs/tst1.txt with
        //testfiles/corrects/tst1.txt
        string correct = dpath+"/corrects/"+v[i];
        //make tempfile, pray file does not exist(so declare strange name)


        //CHECK#3: if 'correct' file exists
        ifstream file(correct.c_str());
        if(file.fail()){
            cerr << correct << " FILE DOES NOT EXIST. ABORTING"<<endl;
            exit(1);}
        file.close();

        //Redirect OUTPUT to tempfile
        system(("diff "+output.substr(3)+" "+correct+" > "+tempfile).c_str());

//////////5.If the result from diff command is non-empty (meaning files are
        //different), print the filename test1.txt, and the resutl to terminal
        file.open(tempfile.c_str());        //open tempfile
        string filestring;
        getline(file,filestring);
        if(!file.fail())                    //if tempfile isnt empty, print
        {
            cout << v[i] << "->DIFF::" << endl;
            while(!file.fail())
            {
                cout << filestring << endl;
                getline(file,filestring);
            }
        }

        file.close();

//////////6.if the errno is set, then print the filename tst1.txt and the error
        //message to terminal
        file.open((currentpath +"/"+outerr.substr(4)).c_str()); //open err_file
        getline(file,filestring);       //check if empty
        if(!file.fail())                //if not empty, print stuff
        {
            cout << v[i] << "->ERROR::" << endl;
            while(!file.fail())
            {
                cout << filestring << endl;
                getline(file,filestring);
            }
            file.close();
        }
        else {file.close();
        system(("rm -f "+outerr.substr(4)).c_str());}//if empty, delete

    }
    system(("rm -f "+tempfile).c_str()); //delete tempfile

    return 0;
}
