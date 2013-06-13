//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj1
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

/**
*   Class: Observer
*   Serves as container to calculate various values in the kernal
*/
class Observer
{
  private:
    // no private variables/functions; so user can eaisly get container values.
  public:
  string cpu;
  string version;
  int uptime;
  int usertime;
  int systemtime;
  int idletime;
  int disk_io;
  int ctxt;
  string lastboot;
  int processes;
  int memtotal;
  int memfree;

/**
*  Defualt Constructor
*  Initalize all values to 0 or ???
*/
  Observer()
  :cpu("???"),version("???"),uptime(0),usertime(0),systemtime(0),idletime(0),
   disk_io(0),ctxt(0),lastboot("???"),processes(0),memtotal(0), memfree(0)
   {}

/**
*  Finds all varibles for this assignment and reports them individually
*  Calls on each function, seperated by their /proc/ directory
*/
   void report(){
       report_cpu();
       report_version();
       report_uptime();
       report_diskstats();
       report_stat();
       report_meminfo();
       report_loadavg();
   }

/**
*  Finds the string value for cpu in /proc/cpuinfo
*  Reports the CPU type and model (for the first CPU only)
*/
   void report_cpu(){
       //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/cpuinfo";
       myfile.open(filename.c_str());
       string line;

       //logic for reporting cpu info
       for(int i = 0; i < 5; i++) getline(myfile,line);
       cpu = line.substr(line.find(":")+1);
       cout << "\nCPU type and model: "<< cpu <<endl<<endl;
       myfile.close();
   }

/**
*  Finds the string value for the Kernal version in /proc/version
*  Reports the kernal version
*/
   void report_version(){
       //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/version";
       myfile.open(filename.c_str());
       string line;

       //logic for reporting kernal version
       getline(myfile,line);
       version = line.substr(0,line.find("("));
       cout << "Linux kernel version: "<< version << endl<<endl;
       myfile.close();
   }

/**
*  Finds the int value for the total uptime in seconds in /proc/uptime
*  Reports the amount of time since the system was lasst booted in the format:
*  dd:hh:mm:ss, where dd represents the number of days, etc
*/
   void report_uptime(){
       //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/uptime";
       myfile.open(filename.c_str());
       string line;

       //logic for reporting the uptime
       getline(myfile,line);
       uptime = atoi(line.substr(0,line.find(" ")).c_str());
       cout << "Amount of time since the system was last booted: "
            << (uptime/86400) <<":"<< (uptime%86400)/3600 <<":"
            << ((uptime%86400)%3600)/60<<":"<<((uptime%86400)%3600)%60<< endl
            << endl;
       myfile.close();
   }

/**
* Finds and reports all varibles found in the /proc/stat direcotry
*  Reports the amount of time the cpu has spent in usermode, system mode, idle
*  Reports the number of context switches that the kernal has performed
*  Reports the timm when the system was last booted
*  Reports the number of processes that have been created since the system was last booted
*  To follow exact format, also reports disk_io (but does not calculate it)
*/
   void report_stat(){

        //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/stat";
       myfile.open(filename.c_str());
       string line;

       //Logic for reporting systemtime, usertime, and idle time
       getline(myfile,line);
       int pos1 = 4;
       string temp1 = line.substr(pos1+1);
       int pos2 = temp1.find(" ");
       string temp2 = temp1.substr(pos2+1);
       int pos3 = temp2.find(" ");
       string temp3 = temp2.substr(pos3+1);
       int pos4 = temp3.find(" ");
       string temp4 = temp3.substr(pos4+1);
       int pos5 = temp4.find(" ");
       string temp5 = temp4.substr(pos5+1);
       usertime = (atoi(line.substr(pos1+1,pos2).c_str()))/100;
       systemtime= (atoi(line.substr(pos3+pos2+pos1+3,pos4).c_str()))/100;
       idletime = (atoi(line.substr(pos4+pos3+pos2+pos1+4,pos5).c_str()))/100;
       cout << "CPU time in usermode,in systemmode,and idle(seconds): "
            << usertime <<" "<<systemtime<<" "<<idletime<<" "<< endl << endl;

        //to follow formating, reports disk_io
        cout << "disk_io: " << disk_io << endl << endl;

        //logic for getting number of context switches
        while(line.substr(0,4) != "ctxt") getline(myfile,line);
        ctxt = atoi(line.substr(5).c_str());
        cout << "Number of context switches: "<<ctxt << endl << endl;

        //logic for getting lastboot
        getline(myfile,line);
        int seconds = atoi((line.substr(5)).c_str());
        time_t rawtime(seconds);
        cout << "Last booted on " << ctime(&rawtime) << endl;

        //logic for getting processes
        getline(myfile,line);
        processes = atoi((line.substr(10)).c_str());
        cout<<"Number of processes having been created: "<<processes<<endl
            <<endl;
        myfile.close();
   }

/**
* Finds and reports all relevant varibles in /proc/diskstats
*  Reports the number of disk requests made for the disk sda,
*  completed reads plus comopleted writes
*  To follow formating, does not print disk_io, (but does calculate it)
*/
    void report_diskstats(){
        //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/diskstats";
       myfile.open(filename.c_str());
       string line;

       //logic for finding disk_io
       getline(myfile,line);
       while(line.find("sda") > 30) getline(myfile,line);
       line = line.substr(line.find("sda")+4);
       int temp1 = atoi(line.substr(0, line.find(" ")).c_str());
       for(int i = 0; i < 4; i++) line = line.substr(line.find(" ")+1);
       disk_io = temp1 + atoi(line.substr(0, line.find(" ")).c_str());
       //cout << "disk_io: " << disk_io << endl << endl; //for formating issues
       myfile.close();
    }


/**
*  Finds and reports all relevant varibles in the /proc/meminfo
*  Reports the amount of memory configured into the system
*  Reports the amount of memory currently available
*/
    void report_meminfo(){
        //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/meminfo";
       myfile.open(filename.c_str());
       string line;

       //logic for finding the total memory
       getline(myfile,line);
       line = line.substr(line.find(" "));
       while(line.substr(0,1) == " ") line = line.substr(1);
       memtotal = atoi(line.substr(0,line.find(" ")).c_str());
       cout << "MemTotal: " << memtotal << " kB"<< endl << endl;

       //logic for finding the free memory
       getline(myfile,line);
       line = line.substr(line.find(" "));
       while(line.substr(0,1) == " ") line = line.substr(1);
       memfree = atoi((line.substr(0,line.find(" "))).c_str());
       cout << "MemFree: " << memfree << " kB" << endl << endl;
       myfile.close();
    }

/**
*  Finds and reports all relevant variables in the /proc/avgload
*  Reports the load average over the last 1, 5 and 15 minutes respectivley
*/
    void report_loadavg(){
        //Reads the file, sets up the ifstream
       ifstream myfile;
       string filename = "/proc/loadavg";
       myfile.open(filename.c_str());
       string line;

       //logic for reporting the load averages
       getline(myfile,line);
       cout << "Load average over the last 1,5 and 15 minutes respectivley:" << endl;
       cout << line.substr(0,line.find(" ")) << endl;
       line = line.substr(line.find(" ")+1);
       cout << line.substr(0,line.find(" ")) << endl;
       line = line.substr(line.find(" ")+1);
       cout << line.substr(0,line.find(" ")) << endl;
       myfile.close();
    }
};


/**
*  Main
*  creates executable that takes periodic snapshots of kernel's state for a
*  given interval It takes command-line arguments, period and
*  interval respectivley
*/
int main(int argc, char** argv){
    //Check for correct user input
    if(argc != 3){
        cout << "Usage: " << argv[0] << "<period><interval>\n";
        exit(-2);
    }

    //Converts char's to int values
    int period = atoi(argv[1]);
    int interval = atoi(argv[2]);

    //declare the Obeserver struct
    Observer observer;

    //Reports the snapshot
    for(int i = 0; i != interval/period; ++i){
        observer.report();
        sleep(period);
    }

    return 0;
}

