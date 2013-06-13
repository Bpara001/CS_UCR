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

using namespace std;



int walk(string dir)
{
//print root directory,creat data(root) ptr, create lists, creat struct dirent
    cout << "./" << dir<<"/"<<endl;
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

//calculate and print total
    int total = 0;
    for (list<string>::iterator it=files.begin(); it != files.end(); it++)
    {
        string fullroot = dir + "/" + *it;
        lstat(fullroot.c_str(),&structstat);
        total += structstat.st_blocks;
    }

    cout << "total " << total/2 << endl;

//print all revelant inforation.
   for (list<string>::iterator it =files.begin(); it != files.end();it++)
   {
        string fullroot = dir + "/" + *it;
        lstat(fullroot.c_str(),&structstat);

///////////////////////////
/////PRINT PREMISSIONS/////
///////////////////////////

//check if it is a folder(directory)
        if(S_ISDIR(structstat.st_mode))
        {
            hardsub.push_back(*it);
            cout <<"d";
            *it = *it + "/";
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
            if((hardsub.back() + "/") != *it)
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

/////////////////////////////////
/////PRINT # LINKS TO FILE //////
/////////////////////////////////

        cout << " " << structstat.st_nlink;


/////////////////////////////////
/////PRINT USER NAME  ///////////
/////////////////////////////////

        struct passwd* userinfo = getpwuid(structstat.st_uid);
        cout << " " << userinfo->pw_name << " ";

/////////////////////////////////
/////PRINT GROUP NAME  //////////
/////////////////////////////////

        struct group *groupinfo;
        if ((groupinfo = getgrgid(structstat.st_gid)) != NULL)
            printf("%-8.8s",groupinfo->gr_name);
        else
            printf("%8d",structstat.st_gid);

/////////////////////////////////
/////PRINT FILE SIZE ///////////
/////////////////////////////////

        cout << " " << setw(5)<< structstat.st_size << " ";

/////////////////////////////////
/////PRINT last mod date  ///////
/////////////////////////////////;
        char buffer[256];
        time_t temptime;

        time(&temptime);
        strcpy(buffer,ctime(&temptime) +4 );
        buffer[strlen(buffer)-9]='\0';
        printf("%s",buffer);


/////////////////////////////////
/////PRINT FILE NAME  ///////////
/////////////////////////////////

        cout << " " <<  *it <<  endl;
   }

}


int main (int argc, char *argv[])
{

    // check to see if user entered a directory name
    if (argc < 2)
    {
            printf("Usage: %s <directory>\n", argv[0]);
            return 0;
    }



    // DIR *opendir(const char *name);
    // Open a directory stream to argv[1] and make sure
    // it's a readable and valid (directory) */

    DIR *dip;
    if (( dip = opendir(argv[1])) == NULL)
    {
            perror("opendir");
            return 0;
    }

    walk(argv[1]);

    cout << "\nDirectory stream is now open\n";


    // struct dirent *readdir(DIR *dir);
    //Read in the files from argv[1] and print */


        cout <<"\n\nreaddir() found a total of ----"  << " files\n";

    // int closedir(DIR *dir);
    //Close the stream to argv[1]. And check for errors.
    if (closedir(dip) == -1)
    {
        perror("closedir");
        return 0;
    }

    printf("\nDirectory stream is now closed\n");
    return 1;
    //}

}


