#include <cstring>
#include "../include/Board.h"
#include "../include/BoardView.h"


static bool contains(int argc, char ** argv, const char *needle)
{
    for (size_t i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], needle) == 0)
            return true;
    }
    return false;
}

int main(int argc, char ** argv)
{
    Board board(3, 3);

    bool silence = contains(argc, argv, "silent");

    BoardView boardView(board, silence);

    while (board.gameState() == IN_PROGRESS)
    {
        boardView.doGameCycle();
    }

    if (board.gameState() != INTERRUPTED)
        boardView.printGameResult();

    return 0;
}