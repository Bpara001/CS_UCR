#include "manager.h"
#include "employee.h"

Manager::Manager()
  :department()
{
}

Manager::Manager(string name, double salary, string department)
  :Employee(name,salary),department(department)
{
}

string Manager::get_department() const
{
  return department;
}

void Manager::set_department(string n)
{
  department = n;
}

void Manager::print()
{

  cout <<"Department: " << department << endl;
  this -> Employee::print();
}

Manager::~Manager()
{
}
