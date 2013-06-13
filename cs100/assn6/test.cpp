//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn6
// Lab section: 022
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================


//!This is very important and should not be printed
//#include <iostream>

#include "custom.h"
#define MY_OBJECT_MACRO 1000
#define weirdmacro "WONGWORLD!"
#define LIST_LOOP                         \
    for (cons = listp; !NILP (cons); cons = XCDR (cons)) \
        if (!CONSP (cons))                                 \
            signal_error ("Invalid list format", listp);     \
        else

using namespace std;

  //main functioin
int main()
{
    /* yo yo yo what up dog what be hanging?
    yeah that be right
    im making a hello world program mo fos
    uh huh this should not be printing yoyo!
    */
    string s = "Program terminated";/*you should not see this
    none of this shit shouold be in the terminal
    if it is, then you're funcked!
     */
    cout << "Hello World " << s << endl;

    cout << MY_OBJECT_MACRO << endl;

    cout << weirdmacro << weirdmacro << " " << weirdmacro << endl;

    LIST_LOOP


    return 0;//exit program
}
