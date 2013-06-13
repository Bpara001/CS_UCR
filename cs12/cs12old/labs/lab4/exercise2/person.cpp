//person.cpp
#include "person.h"

using namespace std;

Person::Person()
{
age = 0;
name.first = " ";
name.last = " ";
mom = NULL;
dad = NULL;
}

  Person::Person(string first,string last, int a)
  {
  name.first = first;
  name.last = last;
  age = a;
  mom = NULL;
  dad = NULL;
  }

  Person::Person(string first,string last, int a, Person *m, Person *d)
  {
  name.first = first;
  name.last = last;
  age = a;
  mom = m;
  dad = d;
  }

  void Person::display()
  {
cout << name.first << " " << name.last << endl;
cout << "age: " << " " << age << endl;
if (mom != NULL && dad != NULL)
{
cout << "Dad: " << dad->name.first << " " << dad->name.last << endl;
cout << "Mom: " << mom->name.first << " " << mom->name.last << endl;
}
  }



