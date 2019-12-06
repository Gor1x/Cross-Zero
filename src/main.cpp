#include <cstring>
#include "Board.h"
#include "StdioBoardView.h"
#include <NCursesBoardView.h>

static bool contains(size_t argc, char ** argv, const char *needle)
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
    Board board(10, 10);

    if (contains(argc, argv, "curses"))
    {
        NCursesBoardView boardView(board);

        while(true);
        while (board.gameState() == IN_PROGRESS)
        {
            boardView.doGameCycle();
        }

        if (board.gameState() == INTERRUPTED)
        {
            endwin();
        }
        else
        {
            boardView.printGameResult();
            printw("\nUse any key to exit the game");
            getch();
            endwin();
        }
    }
    else
    {
        bool silence = contains(argc, argv, "silent");

        StdioBoardView boardView(board, silence);

        while (board.gameState() == IN_PROGRESS)
        {
            boardView.doGameCycle();
        }

        if (board.gameState() != INTERRUPTED)
            boardView.printGameResult();
    }


    return 0;
}