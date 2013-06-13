#include "board.h"

Board::Board()
:size(), pos()
{
}

Board::Board(const Point & ul_corner, const double size)
: size(this->size), pos(ul_corner)
{
int count = 0;
double x = ul_corner.get_x(); 
double y = ul_corner.get_y();

for(int i = 0; i < 3; i++)
{
        for(int j = 0; j < 3; j++)
	{
	ttt_cells[count] = Cell(Point(x + (j *(size / 3)),y - (i *(size / 3))),
	size);
	count ++;
	}
}


}

void Board::draw() const
{
  for(int i = 0; i < 9; i++)
  {
     ttt_cells[i].Cell::draw();
  }
  drawGridLines();
}

void Board::move( const double x_displace, const double y_displace)
{
	for(int i = 0; i < 9; i++)
	{
		ttt_cells[i].Cell::move(x_displace,y_displace);
	}
}

/*bool Board::isWon() const
{
   for(int i = 0; i < 9; i++)
   {
   }

}
*/

void Board::reset()
{
  for(int i = 0; i < 9; i ++)
  {
      ttt_cells[i].reset();
  }
}

bool Board::makeChoice( const Point & click, const char fill )
{

	for(int i = 0; i < 9; i ++)
	{
	   if(ttt_cells[i].is_clicked(click))
	   {
	      if(ttt_cells[i].Cell::isX() || ttt_cells[i].Cell::isO())
	      {
	      return false;
              }
		if(ttt_cells[i].Cell::isEmpty() && fill == 'X')
		{
		    ttt_cells[i].Cell::setAsX();		
	        }
		if(ttt_cells[i].Cell::isEmpty() && fill == 'O')
		{
		    ttt_cells[i].Cell::setAsO();
		}
	       return true;

	   }
	}
  return false;
}




void Board:: drawGridLines() const
{
double x = pos.get_x(); 
double y = pos.get_y();
double adjust = size / 3;

Line a = Line(Point(x, y - adjust),Point(x+adjust,y-adjust));
Line b = Line(Point(x, y - (adjust * 2)),Point(x+adjust,y-(adjust * 2)));
Line c = Line(Point(x + adjust, y),Point(x + adjust, y -(adjust * 2)));
Line d = Line(Point(x + (adjust*2), y),Point(x + (adjust* 2), y -(adjust*2)));

win << a << b << c << d;



}

