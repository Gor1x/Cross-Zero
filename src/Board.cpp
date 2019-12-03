#include <regex>
#include "../include/Board.h"


Board::Board(size_t width_, size_t height_) : width(width_), height(height_), currentState(RUNNING) {
    initData();
}

void Board::move(size_t x, size_t y, char sign)
{
    data[x][y] = FIELD_CHARACTER(sign);
}

bool Board::canMove(size_t x, size_t y, char sign) const
{
    return x < height && y < width && get(x, y) == EMPTY;
}

GAME_STATE Board::isWin() const
{
    return currentState;
}

FIELD_CHARACTER Board::get(size_t x, size_t y) const
{
    return data[x][y];
}

size_t Board::getWidth() const
{
    return width;
}

size_t Board::getHeight() const
{
    return height;
}

void Board::initData()
{
    data = new FIELD_CHARACTER* [height];
    data[0] = new FIELD_CHARACTER[width * height];
    std::fill(data[0], data[0] + width * height, EMPTY);

    for (size_t i = 1; i < height; i++)
    {
        data[i] = data[i - 1] + width;
    }
}

