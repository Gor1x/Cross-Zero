#include <iostream>
#include "../include/BoardView.h"

using std::cout;
using std::endl;

BoardView::BoardView(Board &board_) : board(board_) {
}

void BoardView::showBoard() const
{
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            cout << char(board.get(i, j));
        }
        cout << endl;
    }
}

void BoardView::doGameCycle()
{
    if (board.gameState() != RUNNING)
        return;

    showBoard();

    char currentSign = (board.getTurnNumber() % 2)
                       ? 'X'
                       : 'O';

    size_t x, y;
    readCoordinates(x, y, currentSign);

    if (x == -1 && y == -1)
    {
        board.interruptGame();
        return;
    }

    applyMove(x, y, currentSign);
}

void BoardView::applyMove(size_t x, size_t y, char currentSign)
{
    board.incrementTurnNumber();
    board.move(x, y, currentSign);
    board.checkIfStateChanged(x, y);
}

void BoardView::readCoordinates(size_t &x, size_t &y, char currentSign)
{
    cout << currentSign <<" move: ";
    std::cin >> x >> y;
    if (x == -1 && y == -1)
    {
        return;
    }
    if (!board.canMove(x, y, currentSign))
    {
        cout << "Bad move!" << endl;
        readCoordinates(x, y, currentSign);
        return;
    }
    cout << endl;

}

void BoardView::printGameResult()
{
    if (board.gameState() == X_WIN)
        cout << "X wins!" << endl;
    else if (board.gameState() == O_WIN)
        cout<< "O wins!" << endl;
    else
        cout <<"Draw." << endl;
}



