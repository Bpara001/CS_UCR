#include <iostream>

using std::cout;
using std::endl;


int fac(int n)
{
   
    if (n == 1)
    {
        int* bar = 0;
        cout << *bar << endl;
    }
    return n * fac(n - 1);
}

int main()
{
    using std::cout;
    cout << fac(5) << endl;
    return 0;
}
