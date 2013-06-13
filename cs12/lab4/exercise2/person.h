//person.h

#ifndef __PERSON_H
#define __PERSON_H

#include <string>
#include <vector>

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

 Person();
 Person(string first, string last, int age);
 Person(string frist, string last, int age, Person*mom, Person*dad);
 void display();

  //add Person member function declarations here

};

#endif
