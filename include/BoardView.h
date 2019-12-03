#ifndef HW_02_BOARDVIEW_H
#define HW_02_BOARDVIEW_H


#include "Board.h"

class BoardView
{
public:
    explicit BoardView(Board &board_);
    void doGameCycle();
    void showBoard() const;
    void printGameResult();

private:

    void applyMove(size_t x, size_t y, char currentSign);
    void readCoordinates(size_t &x, size_t &y, char currentSign);

    Board& board;
};


#endif //HW_02_BOARDVIEW_H
