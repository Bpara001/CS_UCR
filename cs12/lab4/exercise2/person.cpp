//person.cpp
#include "person.h"
#include <iostream>
using namespace std;





Person::Person()
:age(0),mom(NULL),dad(NULL)
{
    name.first = "";
    name.last = "";
}

Person::Person(string f, string l, int a)
:age(a),mom(NULL),dad(NULL)
{
    name.first =f;
    name.last = l;
}

Person::Person(string f, string l, int a, Person*m, Person*d)
{
    name.first = f;
    name.last = l;
    mom = m;
    dad = d;
    age = a;
}

void Person::display()
{
    cout <<"Name: " << name.first <<" " << name.last << endl;
    cout <<"Age: " << age << endl;

    if(dad != NULL && mom != NULL)
    {
        cout <<"Dad: " << dad->name.first <<" " << dad->name.last << endl;
        cout <<"Mom: " << mom->name.first <<" " << mom->name.last << endl;
    }

    else
    {
        cout <<"This person has no living parents" << endl;
    }
}






