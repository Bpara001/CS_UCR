#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>
#include <iostream>
#include "employee.h"
using namespace std;

class Manager: public Employee
{
 private:
  string department;

 public:
  Manager();
  Manager(string,double,string);
  string get_department() const;
  void set_department(string);
  virtual void print();
  virtual ~Manager();

};
#endif
