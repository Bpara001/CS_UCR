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


// =================== main.cc ======================================

//
// main.cc
//

// applied monitors and thread classes for testing
#include "mulitortest.H"


class SharableInteger: public Monitor {
public:
  int data;
  SharableInteger() : data(0) {;}
  void increment() {
    EXCLUSION
    ++data;
  }
  string show() {
    EXCLUSION
    return itoa(data);
  }
} counter;                                        // single instance


class Incrementer : Thread {
  int priority() { return INT_MAX - 1; }            // high priority
  void action() {
    cdbg << "New incrementer running.\n";
    for(int i= 0; i < 120; ++i) {
      for(int i=0;i<12000000;++i) {}  // delay
      counter.increment();
      cdbg << " Counter : " << counter.show() << endl;
    }
    cdbg << Me() << " done\n";
  }
public:
  Incrementer( string name ) : Thread(name) {;}
};



//declare owners and sharers

int main()
{
      // shutting down the main thread
  interrupts.set( InterruptSystem::alloff );  // for this thread only
  pause();                           // stops until interrupt arrives
  assert( false );                            // and none ever should

    //return 0;
}
