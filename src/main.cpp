#include "../include/Board.h"
#include "../include/BoardView.h"

int main(int argc, char ** argv)
{
    Board board(3, 3);
    BoardView boardView(board, false);

    while (board.gameState() == IN_PROGRESS)
    {
        boardView.doGameCycle();
    }

    if (board.gameState() != INTERRUPTED)
        boardView.printGameResult();

    return 0;
}