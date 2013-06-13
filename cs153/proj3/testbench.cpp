//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj3
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
//=================================================

#include "popen.H"

int main(){


///IMPORTANT! test each function SEPERATLY, otherwise there are errors!


//Tests 'write option' of Popen
    std:: cout << "\nTESTING Popen, write argument:" << std::endl;
    FILE* f;
    if(  (f = (Popen("wc","w")) ) == NULL ){
        exit(-1);
    }
    std::string s = "hello\n";
    fwrite(s.c_str(),1,s.size(),f);
    Pclose(f);

/*
//Tests 'read option' of Popen
    std::cout << "\nTESTING Popen, read argument:" << std::endl;
    char *cmd = "ls *";
    char buf[BUFSIZ];
    FILE *ptr;
    if ((ptr = Popen(cmd, "r")) != NULL)
    while (fgets(buf, BUFSIZ, ptr) != NULL) (void) printf("%s", buf);
    (void) Pclose(ptr);
*/


    return 0;
}
