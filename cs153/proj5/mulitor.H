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

#ifndef __MULITOR_H__
#define __MULITOR_H__

#include "ucrthreads.H"

#define OWNED_EXCLUSION MulSentry exclusion(this); exclusion.touch();
#define SHARED_EXCLUSION MulSentry exclusion(this,false); exclusion.touch();
#define cdbg2 cout << "\nLn " << __LINE__ << " of " << setw(8) << __FUNCTION__ << " by " << report()


class SharableLock : Monitor{
    enum{available,owned,shared} state;
    int accessCount;
    Condition okToShare;
    Condition okToOwn;

public:

    SharableLock()
        :accessCount(0),state(available),okToShare(this),okToOwn(this){}

    void acquire(bool exclusive = true){
        EXCLUSION
        if(exclusive){  //client wants exclusion
            while(state != available ) okToOwn.wait();
            state = owned;
        }
        else {  //client willing to share
            if(okToOwn.awaited() ) okToShare.wait(); //Arriving sharers defer to aspiring owners.
            while(state == owned) okToShare.wait();
            state = shared;
        }
        ++accessCount;
    }

    void release(){
        EXCLUSION
        --accessCount;
        if(state == owned){
            assert(accessCount == 0);
            state = available;
            if(okToShare.awaited()) {
                okToShare.broadcast();
            }
            else {
                okToOwn.signal();
            }
        }
        else {
            assert(state == shared);
            if(accessCount == 0) {
                state = available;
                okToOwn.signal();
            }
        }
    }
};

//Define a base class mulitor that is to sharablelock as monitor is to lock
class Mulitor : SharableLock{

    friend class MulSentry;
    friend class Condition;
    sigset_t mask;
public:
    void lock(bool ex = true)   { SharableLock::acquire(); }
    void unlock() { SharableLock::release(); }
    Mulitor( sigset_t mask = InterruptSystem::alrmoff )
        : mask(mask)
    {}
};

//finally, redefine sentry to work with multiors as well as monitors
class MulSentry{

     Mulitor&  mon;           // Reference to local monitor, *this.
      const sigset_t old;    // Place to store old interrupt status.
    public:
      void touch() {}          // To avoid unused-variable warnings.
      MulSentry( Mulitor* m,bool ex = true )
        : mon( *m ),
          old( interrupts.block(mon.mask) )
      {
        mon.lock(ex);
      }
      ~MulSentry() {
        mon.unlock();
        interrupts.set( old );
      }
};


#endif
