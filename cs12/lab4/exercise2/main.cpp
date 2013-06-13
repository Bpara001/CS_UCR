//main.cpp

#include "person.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  //create a family of 4 grandparents, 2 parents, and 3 children
  vector<Person *> family;

  //grandparents
  family.push_back( new Person( "Theo", "Doe", 70 ) );
  family.push_back( new Person( "Emily", "Doe", 72 ) );
  family.push_back( new Person( "Joe", "Schmoe", 64 ) );
  family.push_back( new Person( "Mary", "Schmoe", 62 ) );

  //parents
  family.push_back( new Person( "John", "Doe", 40, family[0], family[1] ) );
  family.push_back( new Person( "Jane", "Doe", 35, family[2], family[3] ) );

  //children
  family.push_back( new Person( "Josh", "Doe", 21, family[4], family[5] ) );
  family.push_back( new Person( "Mary", "Doe", 19, family[4], family[5] ) );
  family.push_back( new Person( "Julia", "Doe", 15, family[4], family[5] ) );

  //display entire family
  cout << endl << "Family Members: " << endl << endl;
  for ( unsigned int i = 0; i < family.size(); ++i )
    {
      family[i]->display();
      cout << endl;
    }

  //delete all dynamically allocated memory
  for(unsigned int i = 0; i < family.size(); ++i)
  {
  delete family[i];
  family[i] = NULL;
  }


  return 0;
}
