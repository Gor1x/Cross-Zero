#include <regex>
#include "../include/Board.h"


Board::Board(size_t width_, size_t height_) : width(width_), height(height_), currentState(RUNNING) {
    initData();
}

void Board::move(size_t x, size_t y, char sign)
{
    data[x][y] = POSITION_STATE(sign);
}

bool Board::canMove(size_t x, size_t y, char sign) const
{
    return x < height && y < width && get(x, y) == EMPTY;
}

GAME_STATE Board::gameState() const
{
    return currentState;
}

POSITION_STATE Board::get(size_t x, size_t y) const
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
    data = new POSITION_STATE* [height];
    data[0] = new POSITION_STATE[width * height];
    std::fill(data[0], data[0] + width * height, EMPTY);

    for (size_t i = 1; i < height; i++)
    {
        data[i] = data[i - 1] + width;
    }
}

int Board::countElements(size_t x, size_t y, const POSITION_STATE state, const int X_DELTA, const int Y_DELTA)
{
    int answer = 0;
    while (x < getHeight() && y < getWidth() && get(x, y) == state)
    {
        answer++;
        x = x + X_DELTA;
        y = y + Y_DELTA;
    }
    return answer;
}

void Board::checkIfStateChanged(size_t x, size_t y)
{
    const std::pair<int, int> direction[4] = {
            {+1, -1}, //sideDiagonal
            {+1, +1}, //mainDiagonal
            {+1, 0}, //vertical
            {0, +1}, //horizontal;
    };

    POSITION_STATE state = get(x, y);

    for (auto dir : direction)
    {
        int currentDirectionAnswer = countElements(x, y, state, dir.first, dir.second) +
                                     countElements(x, y, state, -dir.first, -dir.second) - 1;

        if (currentDirectionAnswer >= 5)
        {
            if (state == X_SIGN)
            {
                currentState = X_WIN;
            }
            else
            {
                currentState = O_WIN;
            }
            return;
        }
    }

}

void Board::interruptGame()
{
    currentState = INTERRUPTED;
}

int Board::getTurnNumber() const
{
    return turnNumber;
}

void Board::incrementTurnNumber()
{
    turnNumber++;
}


