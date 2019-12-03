#include "../include/Board.h"

Board::GameField::GameField(size_t width_, size_t height_) : width(width_), height(height_), data(new char*[height])
{
    data[0] = new char[width * height];
    for (size_t i = 1; i < height; i++)
        data[i] = data[i - 1] + width;

}

Board::GameField::~GameField()
{
    delete[] data[0];
    delete[] data;
}

char Board::GameField::get(size_t x, size_t y) const
{
    return data[x][y];
}

Board::Board(size_t width, size_t height) : field(width, height)
{

}
