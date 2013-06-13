
#include <iostream>
#include "heap.h"

// implement a max heap

using namespace std;

int
main ( ) {

  Heap heap;
  PrintJob* pj;  // priority, pages, jobnumber

  if ( ( pj = heap.highest ( ) ) != NULL )
    cout << "Failed test 1" << endl;
  else
    cout << "Passed test 1" << endl;
  cout << "--------------------------------------------------" << endl;

  //pj = heap.highest();


  heap.enqueue ( new PrintJob ( 1, 2, 3 ) );
  heap.print ( );
  if ( ( pj = heap.highest ( ) ) == NULL )
    cout << "Failed test 2" << endl;
  else if ( pj->getPages ( ) == 2 && pj->getPriority ( ) == 1
            && pj->getJobNumber ( ) == 3 )
    cout << "Passed test 2" << endl;
  else
    cout << "Failed test 2" << endl;
  cout << "--------------------------------------------------" << endl;

  heap.enqueue ( new PrintJob ( 2, 3, 4 ) );
  heap.enqueue ( new PrintJob ( 3, 4, 5 ) );
  cout << "Test 3" << endl;
  heap.print ( );
  cout << "--------------------------------------------------" << endl;
  heap.enqueue ( new PrintJob ( 4, 5, 6 ) );
  heap.enqueue ( new PrintJob ( 5, 6, 7 ) );
  heap.enqueue ( new PrintJob ( 6, 7, 8 ) );
  heap.enqueue ( new PrintJob ( 7, 8, 9 ) );
  heap.enqueue ( new PrintJob ( 8, 9, 10 ) );
  cout << "Test 4" << endl;
  heap.print ( );
  cout << "--------------------------------------------------" << endl;

  int passed = 0;
  for ( int i = 7; i > 0 ; i -- ) {
    if ( ( pj = heap.highest ( )  ) != NULL ) {
      if ( pj->getPages ( ) == i+1 && pj->getPriority ( ) == i 
            && pj->getJobNumber ( ) == i+2 )
        passed ++;
      heap.dequeue ( );
    }
  }

  cout << "Test 5" << endl;
  cout << "Passed " << passed << " of 7 dequeue operations" << endl;

  heap.print ( );
  heap.dequeue ( );

  return 1;
}
