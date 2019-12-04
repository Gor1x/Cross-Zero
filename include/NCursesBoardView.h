#ifndef HW_02_NCURSESBOARDVIEW_H
#define HW_02_NCURSESBOARDVIEW_H

#include "Board.h"

class NCursesBoardView
{
public:
    explicit NCursesBoardView(Board &board_);
    void doGameCycle();
    void showBoard() const;
    void printGameResult();

private:

    Board& board;
};


#endif //HW_02_NCURSESBOARDVIEW_H
