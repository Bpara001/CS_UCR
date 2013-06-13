
#ifndef __PRINTJOB_H
#define __PRINTJOB_H

using namespace std;

class PrintJob {
private:
  int priority;
  int numPages;
  int jobNumber;

public:

  PrintJob()
  {
    priority = 0;
    numPages = 0;
    jobNumber = 0;
  }

  PrintJob( int setP, int numP, int setJ)
  {
    priority = setP;
    numPages = numP;
    jobNumber = setJ;
  }

  int getPriority ( )
  {
	  return priority;
  }
  int getPages ( )
  {
	  return numPages;
  }
  int getJobNumber ( )
  {
	  return jobNumber;
  }

  void setPriority(int n)
  {
	  priority = n;
  }
  void setPages(int n)
  {
	  numPages = n;
  }
  void setJobNumber(int n)
  {
	  jobNumber = n;
  }




// add additional functions/variables here

};

#endif
