#ifndef HW_02_BOARD_H
#define HW_02_BOARD_H

#include <cstddef>

enum GAME_STATE {
    RUNNING,
    X_WIN,
    O_WIN,
    DRAW
};


enum FIELD_CHARACTER {
    X = 'X',
    O = 'O',
    EMPTY = '.'
};


class Board
{

public:
    Board(size_t width, size_t height);

    void move(size_t x, size_t y, char sign);

    bool canMove(size_t x, size_t y, char sign) const;

    GAME_STATE isWin() const;

    FIELD_CHARACTER get(size_t x, size_t y) const;

    size_t getWidth() const;

    size_t getHeight() const;


private:
    void initData();

private:

    size_t width;
    size_t height;
    FIELD_CHARACTER ** data;

    GAME_STATE currentState;

};


#endif //HW_02_BOARD_H
