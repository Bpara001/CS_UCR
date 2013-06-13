#include "employee.h"




Employee::Employee()
  : name(),salary()
{
}

Employee::Employee(string name, double salary)
  :name(name),salary(salary)
{
}

string Employee::get_name() const
{
  return name;
}

double Employee::get_salary() const
{
  return salary;
}

void Employee::set_salary(double n)
{
  this->salary = n;
}

void Employee::set_name(string n)
{
  this->name = n;
}

void Employee::raise_salary(double n)
{
  this->salary += n;
}

void Employee::print()
{
  cout <<"Name: " << name << endl;
  cout <<" Salary: $" << salary << endl;
}

Employee::~Employee()
{
}
