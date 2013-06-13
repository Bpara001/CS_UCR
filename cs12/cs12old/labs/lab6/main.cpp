
#include "instinct.h"
#include "board.h"


int instinct_main()
{
    win.coord(0,0,100,100);
    Board board(Point(50,50), 50);
    board.center(Point(50,50));
    board.show();
    board.draw();

    char c = 'X';
    while(true)
    {
        Point click = win.get_click("Click");

        if( board.makeChoice( click, c ) )
            if( c == 'X' )
                c = 'O';
            else
                c = 'X';
        
        win.clear_buffer();
        board.draw();
    }
    
    return 0;
}
