//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn1
// Lab section: 0?
// TA: ?
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

//uses ascii sorting.

#include <iostream>
#include <stdio.h>
#include <list>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <string>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>
#include <math.h>

using namespace std;


////////////////////////////////
/////WALK FUNCTION /////////////
////////////////////////////////
int walk(string dir)
{
//print root directory,creat data(root) ptr, create lists, creat struct dirent
    cout  << dir<<":"<<endl;
    DIR *dptr;
    dptr = opendir(dir.c_str());
    struct dirent *structptr;
    list<string>files;
    list<string>hardsub;

//populate list of all files,ignore hidden files,sort
    while((structptr = readdir(dptr)) != NULL)
    {
        string check = structptr->d_name;
        if(check.substr(0,1) != ".")
            files.push_back(check);
    }
    closedir(dptr);
    struct stat structstat;
    files.sort();

//calculate and print total
    int total = 0;
    for (list<string>::iterator it=files.begin(); it != files.end(); it++)
    {
        string fullroot = dir + "/" + *it;
        lstat(fullroot.c_str(),&structstat);
        total += (structstat.st_blocks);
    }
    cout << "total " << total/2 << endl;

//calculate max # of digits for size
    int maxdigits = 0;
    for (list<string>::iterator it=files.begin(); it != files.end(); it++)
    {
        string fullroot = dir + "/" + *it;
        lstat(fullroot.c_str(),&structstat);
        int n = static_cast<int>(floor(log10(structstat.st_size)));
        if(n > maxdigits)
            maxdigits = n;
    }
    maxdigits += 1;


/////PRINT ALL RELAVENT INFORMATION/////////
   for (list<string>::iterator it =files.begin(); it != files.end();it++)
   {
        bool directoryflag = false;
        string fullroot = dir + "/" + *it;
        lstat(fullroot.c_str(),&structstat);

/////PRINT PREMISSIONS/////
//check if it is a folder(directory)
        if(S_ISDIR(structstat.st_mode))
        {
            hardsub.push_back(*it);
            cout <<"d";
            *it = *it + "/";
            directoryflag = true;
        }
        else
            cout <<"-";
//check premissions of owner
        if(structstat.st_mode & S_IREAD)
            cout <<"r";
        else
            cout <<"-";
        if(structstat.st_mode & S_IWRITE)
            cout <<"w";
        else
            cout <<"-";
        if(structstat.st_mode & S_IEXEC)
        {
            cout <<"x";
            if(!directoryflag)
                *it = *it + "*";
        }
        else
            cout <<"-";
//check premissions of group
        if(structstat.st_mode & S_IRGRP)
            cout <<"r";
        else
            cout <<"-";
        if(structstat.st_mode & S_IWGRP)
            cout <<"w";
        else
            cout <<"-";
        if(structstat.st_mode & S_IXGRP)
            cout <<"x";
        else
            cout <<"-";
//check premissions of others
       if(structstat.st_mode & S_IROTH)
            cout <<"r";
        else
            cout <<"-";
        if(structstat.st_mode & S_IWOTH)
            cout <<"w";
        else
            cout <<"-";
        if(structstat.st_mode & S_IXOTH)
            cout <<"x";
        else
            cout <<"-";


/////PRINT # LINKS TO FILE //////
        cout << " " << structstat.st_nlink;


/////PRINT USER NAME  ///////////
        struct passwd* userinfo = getpwuid(structstat.st_uid);
        cout << " " << userinfo->pw_name << " ";


/////PRINT GROUP NAME  //////////
        struct group *groupinfo;
        groupinfo = getgrgid(structstat.st_gid);
        cout << groupinfo->gr_name << " ";

/////PRINT FILE SIZE ///////////
        cout << setw(maxdigits)<< structstat.st_size << " ";

//////PRINT last mod date  ///////
        char buffer[30];
        strcpy(buffer,ctime(&structstat.st_mtime) +4 );
        buffer[strlen(buffer)-9]='\0';
        printf("%s",buffer);

//////PRINT FILE NAME  ///////////
        cout << " " <<  *it <<  endl;
   }


//recursivly call function on subfolders
    hardsub.sort();
    for (list<string>::iterator it =hardsub.begin(); it != hardsub.end();it++)
    {
        cout << endl;
        walk((dir + "/" + *it));
    }

}


////////////////////////////////
///////MAIN FUNCTION////////////
////////////////////////////////
int main (int argc, char *argv[])
{

//check valid input
    if (argc < 2)
    {
            printf("Usage: %s <directory>\n", argv[0]);
            return 0;
    }


//create DIR, check input is valid
    DIR *dip;
    if (( dip = opendir(argv[1])) == NULL)
    {
            perror("opendir");
            return 0;
    }

//RUN THE VISITOR FUNCTION
    walk(argv[1]);

//check for closing errors
    if (closedir(dip) == -1)
    {
        perror("closedir");
        return 0;
    }

    return 1;

}


