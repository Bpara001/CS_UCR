#include <iostream>
#include <vector>
#include <instinct.h>

using namespace std;

void draw_points ( vector<Point> & dots)
{

  for(int i =0; i <dots.size(); ++i)
    {
      dots[i] = win.get_mouse("Click on Screen");
     //  dots.push_back(i);
     
      Message num (dots[i],i);
      num.move(1,-3);
      win << dots[i] << num;
    
      win.output_buffer(); 
   
    }
}

void line_create(const vector <Point> & dots , vector <Line> &line, 
		 Point a, Point b)
{

 int click1 = win.get_int("Enter the number of a dot");
 int click2 = win.get_int("Enter the number of another dot");



 for(int j = 0; j < dots.size(); ++j)
   {
     
     if( j == click1 )
       {
	 a = dots[j];	 
	 
	    }
     
     if( j == click2 )
       {
	 b = dots[j];
	      
       }
   }   
  
 Line draw (a,b,RED);
 line.push_back(draw);
   
}

 

void draw_lines (vector<Line> & line)
{
  for (int k =0; k < line.size(); ++k)
      {
	win << line[k];
	win.output_buffer(); 
      }
    
    
}

int instinct_main()

{
 
  win.coord(0,0,100,100);
  int size = 10;
  vector <Point> dots (size);
  vector <Line> line ;
  Point a (50,50);
  Point b (75,75);
  string again = "";
  
    draw_points(dots);
  
  while (again.substr(0,1) != "N" && again.substr(0,1) != "n" )
    {  
     
  // Line draw (a,b,ORANGE);
  //  line.push_back(draw);
   line_create (dots,line, a , b);

    draw_lines(line);
        again = win.get_string("Would you like to draw another line?");
   
    if (again.substr(0,1) != "Y" && again.substr(0,1) != "y" &&
	again.substr(0,1) != "N" &&  again.substr(0,1) != "n")
      {
	again = win.get_string("Invalid response! YES or NO");
      }
    }

 
  int choose = win.get_int("Restart program? 1 for yes, 2 for no");

  if(choose == 1)
  {
    
    win.clear_buffer();
    size = win.get_int("How many Points do you want?");
     if(choose != 2)
       {
	 instinct_main();
      
       }
  
  }

 return 0;
}
