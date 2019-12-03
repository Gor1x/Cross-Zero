#ifndef HW_02_BOARD_H
#define HW_02_BOARD_H

#include <cstddef>

class Board
{
    Board(size_t width, size_t height);

private:

    class GameField
    {
    public:
       ~GameField();
        GameField(size_t width_, size_t height_);

        char get(size_t x, size_t y) const;

    private:

        size_t width;
        size_t height;
        char** data;

    };

    GameField field;


};


#endif //HW_02_BOARD_H
