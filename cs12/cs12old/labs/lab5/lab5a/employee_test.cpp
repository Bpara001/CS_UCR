#include "employee.h"
#include "manager.h"
#include <iostream>

int main()
{
  Employee * e = new Employee();
  cout <<"Enter Employee Name" << endl;
  string n;
  cin >> n;
  e->set_name(n);
  cout <<"Enter Employee Salary" << endl;
  double s;
  cin >> s;
  e->set_salary(s);

  cout << endl;
  e -> print();
  cout << endl;

  cout <<"Change Employee Salary to: " << endl;
  cin >> s;
  e->set_salary(s);

  cout << endl;
  e-> print();
  cout << endl;


  Employee * m = new Manager();
  cout << "Enter Manager Name" << endl;
  cin >> n;
  m-> set_name(n);

  cout << "Enter Manager Salary" << endl;
  cin >> s;
  m-> set_salary(s);

  cout << "Enter Manager Department" << endl;
  string d;
  cin >> d;
  //m-> set_department(d);

  cout << endl;
  m -> print();
  cout << endl;

  cout << "Change manager Salary to:" << endl;
  cin >> s;
  m-> set_salary(s);

  cout << "Change Manager Department to: " << endl;
  cin >> d;
  //m-> set_department(d);

  cout << endl;
  m -> print();
  cout << endl;

delete e;
delete m;
e = NULL;
m = NULL;

return 0;

/*

string e_name;
double e_salary;

string m_name;
double m_salary;
string m_dept;

cout <<"Enter Employee Name" << endl;
cin >> e_name;
cout <<"Enter Employee Salary" << endl;
cin >> e_salary;

cout << endl;
Employee e = Employee(e_name,e_salary);
e.print();
cout << endl;

cout <<"Change the salary to" << endl;
cin >> e_salary;
e = Employee(e_name,e_salary);

cout << endl;
e.print();
cout << endl;

cout <<"Enter Manager Name" << endl;
cin >> m_name;
cout <<"Enter Manager Salary" << endl;
cin >> m_salary;
cout <<"Enter Manager Department" << endl;
cin >> m_dept;

cout << endl;
Manager m = Manager(m_name,m_salary,m_dept);
m.print();
cout << endl;

cout <<"Change the salary to " << endl;
cin >> m_salary;

cout <<"Change the Department"<< endl;
cin >> m_dept;

cout << endl;
m = Manager(m_name,m_salary,m_dept);
m.print();
cout << endl;

  return 0;
  */
}
