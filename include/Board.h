#ifndef HW_02_BOARD_H
#define HW_02_BOARD_H

#include <cstddef>

enum GAME_STATE {
    RUNNING,
    X_WIN,
    O_WIN,
    DRAW,
    INTERRUPTED
};


enum POSITION_STATE {
    X_SIGN = 'X',
    O_SIGN = 'O',
    EMPTY = '.'
};


class Board
{
public:
    int getTurnNumber() const;

    void incrementTurnNumber();

    Board(size_t width, size_t height);

    void move(size_t x, size_t y, char sign);

    bool canMove(size_t x, size_t y, char sign) const;

    GAME_STATE gameState() const;

    void interruptGame();

    POSITION_STATE get(size_t x, size_t y) const;

    size_t getWidth() const;

    size_t getHeight() const;

    void checkIfStateChanged(size_t x, size_t y);

private:
    void initData();

    int countElements(size_t x, size_t y, const POSITION_STATE state, const int X_DELTA, const int Y_DELTA);

private:

    size_t width;
    size_t height;
    POSITION_STATE ** data;

    GAME_STATE currentState;
    int turnNumber = 0;

};


#endif //HW_02_BOARD_H
