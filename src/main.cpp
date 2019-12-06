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
        init_pair(BACKGROUND_COLOR, COLOR_WHITE, COLOR_BLACK);
        init_pair(CURSOR_COLOR, COLOR_BLACK, COLOR_RED);
        init_pair(X_COLOR, COLOR_BLACK, COLOR_BLUE);
        init_pair(O_COLOR, COLOR_BLACK, COLOR_RED);


        while (board.gameState() == IN_PROGRESS)
        {
            boardView.doGameCycle();
        }

        if (board.gameState() == INTERRUPTED)
        {
            endwin();
        }

        boardView.printGameResult();
        printw("\nUse any key to exit the game");
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