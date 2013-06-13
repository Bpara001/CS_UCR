#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    // We are setting this pointer to not point at anything
    int* bar = 0;

    // Now try to print out what is in the bad pointer
    cout << *bar << endl;

    // And now try to set the bad pointer
    *bar = 42;

    return 0;
}
