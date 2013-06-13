#include <iostream>
using namespace std;

int main()
{

int i = 1;
double d = 2.00;
string s = "string";


int* i_ptr = &i;
double* d_ptr = &d;
string* s_ptr = &s;

cout << i_ptr << endl;
cout << *i_ptr << endl;
cout << d_ptr << endl;
cout << *d_ptr << endl;
cout << s_ptr << endl;
cout << *s_ptr << endl;

double* dptr4 = NULL;
cout << dptr4 << endl;

dptr4 = new double;
*dptr4 = 3.00;
cout << *dptr4 << endl;
delete dptr4;
dptr4 = NULL;




return 0;
}
