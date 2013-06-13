#include <iostream>
#include <vector>
#include <instinct.h>
#include <cmath>
#include <iomanip>

using namespace std;

int random(int lower,int higher)
{
  int rand_num;
  rand_num = rand()%((higher-lower+1)+lower);
  return rand_num;
}
void create_bricks(vector<Rect> &  brick , Point start,int rows, int column,
		    double width, double height, double hor_gap,
		   double vert_gap,Color color)

{
  for (int i = 0; i < rows; ++i)
    {
      Rect rect (start,width,height,color,true);
      rect.move (0,i*(vert_gap+height));

      for (int i = 0; i < column; ++i)
	{ 
	  brick.push_back(rect);
	  rect.move(hor_gap+width,0);
	}
    }
}

//

void draw_bricks (vector<Rect> & brick)
{
  for (int i =0; i <brick.size(); ++i )
    { 
      win << brick[i];
    }
}

int instinct_main()
{
  win.coord(-100,-100,100,100);  
  double width  = 22;
  double height = 10;
  Point start (-90,50);
  int size = 16; 
  int x=-90;
  int y=50;
//deals with making and craeting rectamgles

  int columns = 8;
  int rows = 1; 
  Color color ; 
  double hor_gap = 1.5 ;
  double vert_gap = 1.5 ;

  vector <Rect> rect; 

		 
create_bricks( rect ,start ,rows, columns,
	       width,  height,hor_gap ,vert_gap,BLACK);

  draw_bricks (rect);
 
 win.output_buffer();
 
 while(!win.is_key_down("esc")) // for(;;)
   {
      
    win.clear_buffer();
     for (int j=0;j<rect.size();++j)
       {
	 win << rect[j];


   }
      
     if( win.is_key_down("u"))
       {
	 for (int i = 0; i < rect.size(); ++i)
	   {
	     rect[i].move(0,0.2);
	     win << rect[i];
	   
	   }
       }
     
     if( win.is_key_down("d"))
       {
	 for(int i =0; i < rect.size();++i)
	   
	   { 
	     rect[i].move(0,-0.2);
	     win << rect[i];
	    
	   }
       }
     
     if( win.is_key_down("r"))
       {
	 for(int i =0; i < rect.size(); ++i)
	   {
	    rect[i].set_color(RED);
	     rect[i].set_filled_in(true);
	    
	     win << rect[i];
	    
	   }
       }
     
     if( win.is_key_down("b"))
       {
	 
      for(int i =0; i < rect.size(); ++i)
	{
	  rect[i].set_filled_in(true);
	 rect[i].set_color(BLUE);
	  win << rect[i];
	 
	}
       }
  
     win.output_buffer();
     }

    
 

 return 0;
}
