#include "../include/Board.h"
#include "../include/BoardView.h"

int main()
{
    Board board(10, 10);
    BoardView boardView(board);
    while (board.gameState() == RUNNING)
    {
        boardView.doGameCycle();
    }

    if (board.gameState() != INTERRUPTED)
        boardView.printGameResult();

    return 0;
}