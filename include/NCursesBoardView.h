#ifndef HW_02_NCURSESBOARDVIEW_H
#define HW_02_NCURSESBOARDVIEW_H

#include "Board.h"
#include <ncurses.h>


const size_t BACKGROUND_COLOR = 1;
const size_t CURSOR_COLOR = 2;
const size_t X_COLOR = 3;
const size_t O_COLOR = 4;


class NCursesBoardView
{
public:
    explicit NCursesBoardView(Board &board_);
    void doGameCycle();
    void showBoard() const;
    void printGameResult();

    void init();

private:

    class Cursor
    {

    public:

        Cursor(size_t height_, size_t width_, Board &board_);

        size_t getX() const;
        size_t getY() const;

        void move(int command);

        void remove();
        void draw();

        void drawColored(size_t i, size_t j, bool underCursor = false) const;

        void moveToPosition();

    private:

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        size_t currentX;
        size_t currentY;
        size_t width;
        size_t height;
        Board& board;
    };

    Board& board;
    Cursor cursor;
};


#endif //HW_02_NCURSESBOARDVIEW_H
