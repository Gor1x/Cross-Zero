#ifndef HW_02_BOARDVIEW_H
#define HW_02_BOARDVIEW_H


#include "Board.h"

class BoardView
{
public:
    explicit BoardView(Board &board_);
    void doGameCycle();
    void showBoard() const;

private:

    int turnNumber = 0;
    Board& board;
};


#endif //HW_02_BOARDVIEW_H
