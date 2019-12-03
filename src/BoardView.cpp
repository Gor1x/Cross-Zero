#include <iostream>
#include "../include/BoardView.h"

BoardView::BoardView(Board &board_) : board(board_) {
}

void BoardView::showBoard() const
{
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            std::cout << char(board.get(i, j));
        }
        std::cout << std::endl;
    }
}

void BoardView::doGameCycle()
{


}


