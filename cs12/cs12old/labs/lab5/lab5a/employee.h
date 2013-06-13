#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>
#include <iostream>
using namespace std;

class Employee
{

 private:
  string name;
  double salary;

 public:
  Employee();
  Employee(string,double);
  string get_name() const;
  double get_salary() const;
  void set_salary(double);
  void set_name(string);
  void raise_salary(double);
  virtual void print();
  virtual ~Employee();
};

#endif
