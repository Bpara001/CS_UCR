#include <iostream>
#include <vector>
#include <instinct.h>

using namespace std;

int instinct_main()

{
 
  win.coord(0,0,100,100);
 

  vector <Point> dots (6);
  vector <Line> line ;
  Point a (50,50);
  Point b (75,75);

    for(int i =0; i <dots.size(); ++i)
    {
      dots[i] = win.get_mouse("Click on Screen");
     //  dots.push_back(i);
     
      Message num (dots[i],i);
      num.move(1,-3);
      win << dots[i] << num;
     
     win.output_buffer(); 
    }
 
    int click1 = win.get_int("Enter the numer of a dot");
    int click2 = win.get_int("Enter the numer of another dot");

    for(int j = 0; j < dots.size(); ++j)
    {
    
      if( j == click1 )
	{
	   a = dots[j];	 
	  cout << "hi\n";
	}
    
      if( j == click2 )
	{
	   b = dots[j];
	  cout << "bye\n";
	}
    
    }
    // a = dots[0];
    // b = dots[1];
    Line draw (a,b,RED);
   
    win << draw;

    win.output_buffer(); 

    return 0;
}
