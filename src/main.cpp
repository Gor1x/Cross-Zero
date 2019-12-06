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
    Board board(3, 3);

    if (contains(argc, argv, "curses"))
    {

        NCursesBoardView boardView(board);
        initscr();

        move(0, 0);

        raw();
        noecho();
        keypad(stdscr, true);

        start_color();
        init_pair(BACKGROUND_COLOR, COLOR_RED, COLOR_WHITE);
        init_pair(CURSOR_COLOR, COLOR_BLACK, COLOR_RED);

        while (board.gameState() == IN_PROGRESS)
        {
            boardView.doGameCycle();
        }

        if (board.gameState() == INTERRUPTED)
        {
            endwin();
        }

        boardView.printGameResult();
        printw("\nPrint any key to exit the game");
        getch();
        endwin();
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