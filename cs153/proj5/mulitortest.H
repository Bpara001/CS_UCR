//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj5
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
//=================================================
#ifndef __MULITORTEST_H__
#define __MULITORTEST_H__

#include "mulitor.H"
#include <set>

inline int myrand(){
    static unsigned long next = 3;
    next = next * 1103515245 + 12345;
    unsigned x = (unsigned) (next/65536) % 32768;
    return x % 99;
}

inline void mydelay(){dispatcher.wakeme_in(1);}

template<typename T>
class ThreadSafeSet : Mulitor{
    set<T> myset;
public:

    int size(){
        SHARED_EXCLUSION
        cdbg2 << " BEGIN SHARING\n";
        mydelay();
        int temp = myset.size();
        cdbg2 << " END SHARING\n";
        return temp;
    }

    typename set<T>::iterator find(T x){

    }

    int erase(const T& x){
        OWNED_EXCLUSION;
        cdbg2 << " BEGIN OWNING \n";
        mydelay();
        int temp = myset.erase(x);
        cdbg2 <<" END OWNING\n";
        return temp;
    }

    void insert(T x){
        myset.insert(x);
    }

};

ThreadSafeSet<int> theset;

class Owner : Thread{
    int priority() {return INT_MAX-1;}
    void action(){
        cdbg2 << "New owner running\n";
        for(int i = 0; i < 120; ++i){
            theset.insert(myrand());
            theset.erase(myrand());
            mydelay();
        }
        cdbg2 << "done\n";
    }

    public:
     Owner(string name) : Thread(name) {}

};

class Sharer : Thread {
    int priority() {return INT_MAX-1;}
    void action(){
        cdbg2 << "New sharer running\n";
        for(int i = 0; i < 120; ++i){
            theset.size();
            mydelay();
        }
        cdbg2 << "done\n";
    }

    public:
     Sharer(string name) : Thread(name) {;}
};

Owner own1("Owner1");
Owner own2("Owner2");
Owner own3("Owner3");
Sharer share1("Sharer1");
Sharer share2("Sharer2");
Sharer share3("Sharer3");


#endif

