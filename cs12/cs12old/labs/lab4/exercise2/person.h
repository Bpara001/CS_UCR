//person.h

#ifndef __PERSON_H
#define __PERSON_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Person
{
 private:
  class Name
  {
  public:
    string first;
    string last;
  };
  Name name;
  int age;
  Person *mom;
  Person *dad;
 public:
  //add Person member function declarations here
  Person();
  Person(string first, string last, int a);
  Person(string first, string last, int a, Person*m, Person*d); 
  void display();

};

#endif
