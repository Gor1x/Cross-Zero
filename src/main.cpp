#include "../include/Board.h"
#include "../include/BoardView.h"

int main()
{
    Board board(1, 1);
    BoardView boardView(board);
    while (board.gameState() == IN_PROGRESS)
    {
        boardView.doGameCycle();
    }

    if (board.gameState() != INTERRUPTED)
        boardView.printGameResult();

    return 0;
}