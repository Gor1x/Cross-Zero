#include <cstdio>
#include "../include/BoardView.h"


BoardView::BoardView(Board &board_, bool isSilent) : board(board_), SILENCE(isSilent) {
}

void BoardView::showBoard() const
{
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            printf("%c", char(board.get(i, j)));
        }
        printf("\n");
    }
}

void BoardView::doGameCycle()
{
    if (board.gameState() != IN_PROGRESS)
        return;

    if (!SILENCE)
        showBoard();

    char currentSign = (board.getTurnNumber() % 2)
                       ? 'O'
                       : 'X';

    size_t x, y;
    readCoordinates(x, y, currentSign);

    board.move(x, y, currentSign);
}

void BoardView::readCoordinates(size_t &x, size_t &y, char currentSign)
{
    printf("%c move: ", currentSign);
    scanf("%zu %zu", &x, &y);

    if (x == -1 && y == -1)
    {
        return;
    }
    if (!board.canMove(x, y))
    {
        printf("Bad move!\n");
        readCoordinates(x, y, currentSign);
        return;
    }
    printf("\n");

}

void BoardView::printGameResult()
{
    showBoard();
    if (board.gameState() == X_WIN)
        printf("X wins!");
    else if (board.gameState() == O_WIN)
        printf("O wins!");
    else
        printf("Draw.");
}



