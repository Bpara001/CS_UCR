#include <iostream>
#include <vector>
#include <instinct.h>

using namespace std;

int instinct_main()

{
 
  win.coord(0,0,100,100);
  vector <Point> dots (6);


  // Point click = win.get_mouse("Click on Screen", CYAN);
 
//   Circle c (click,1,CYAN);
//   win << c;

  for(int i =0; i <dots.size(); ++i)
    {
      dots[i] = win.get_mouse("Click on Screen");
     //  dots.push_back(i);
     
      Message num (dots[i],i+1);
      num.move(1,-2);
      win << dots[i] << num;
     
     win.output_buffer(); 
    }

//   for(int i =0; i <dots.size(); ++i)
//     {
    
//      win << dots[i];
//     }

//win.output_buffer(); 
  return 0;
}
