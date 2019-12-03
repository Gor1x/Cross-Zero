#include <iostream>
#include "../include/Board.h"
#include "../include/BoardView.h"

int main()
{
    Board board(10, 10);
    BoardView boardView(board);
    boardView.showBoard();

    return 0;
}