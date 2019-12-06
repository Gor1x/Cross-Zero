#include "NCursesBoardView.h"

NCursesBoardView::NCursesBoardView(Board &board_) : board(board_),
                                                    cursor(board.getWidth(),
                                                            board.getHeight(),
                                                                board)
{
}

void NCursesBoardView::showBoard() const
{
    mvprintw(0, 0, "");
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            POSITION_STATE current = board.get(i, j);

            int color;
            if (current == X_SIGN)
                color = X_COLOR;
            else if (current == O_SIGN)
                color = O_COLOR;
            else
                color = BACKGROUND_COLOR;

            attron(COLOR_PAIR(color));
            printw("%c", char(board.get(i, j)));
            attroff(COLOR_PAIR(color));
        }
        printw("\n");
    }
    refresh();
}



void NCursesBoardView::doGameCycle()
{
    if (board.gameState() != IN_PROGRESS)
        return;
    move(0, 0);
    showBoard();
    move(0, 0);


    char currentSign = (board.getTurnNumber() % 2)
                       ? 'O'
                       : 'X';

    while (true)
    {
        int key = getch();

        if (key == 'x')
        {
            board.move(-1, -1, currentSign);
            return;
        }
        else if (key == ' ')
        {
            if (board.canMove(cursor.getX(), cursor.getY()))
            {
                board.move(cursor.getX(), cursor.getY(), currentSign);
                return;
            }
        }
        else
        {
            cursor.move(key);
        }
    }

}

void NCursesBoardView::printGameResult()
{
    showBoard();
    if (board.gameState() == X_WIN)
        printw("X wins!");
    else if (board.gameState() == O_WIN)
        printw("O wins!");
    else
        printw("Draw.");
}

NCursesBoardView::Cursor::Cursor(size_t height_, size_t width_, Board &board_) : width(width_),
                                                                                    height(height_),
                                                                                    board(board_)
{
    currentX = currentY = 0;
}

size_t NCursesBoardView::Cursor::getX() const
{
    return currentX;
}

size_t NCursesBoardView::Cursor::getY() const
{
    return currentY;
}

void NCursesBoardView::Cursor::remove()
{
    ::move(getX(), getY());
    attron(PAIR_NUMBER(BACKGROUND_COLOR));
    printw("%c", char(board.get(getX(), getY())));
    ::move(getX(), getY());
    refresh();
}

void NCursesBoardView::Cursor::draw()
{
    ::move(getX(), getY());
    attron(PAIR_NUMBER(CURSOR_COLOR));
    printw("%c", char(board.get(getX(), getY())));
    attron(PAIR_NUMBER(BACKGROUND_COLOR));
    ::move(getX(), getY());
    refresh();
}

void NCursesBoardView::Cursor::move(int command)
{
    remove();
    switch (command)
    {
        case KEY_UP:
            moveUp();
            break;

        case KEY_LEFT:
            moveLeft();
            break;

        case KEY_RIGHT:
            moveRight();
            break;

        case KEY_DOWN:
            moveDown();
            break;
    }
    draw();
}

void NCursesBoardView::Cursor::moveUp()
{
    if (currentX > 0)
    {
        currentX--;
    }
}

void NCursesBoardView::Cursor::moveDown()
{
    if (currentX + 1 < height)
    {
        currentX++;
    }
}

void NCursesBoardView::Cursor::moveRight()
{
    if (currentY + 1 < width)
    {
        currentY++;
    }
}

void NCursesBoardView::Cursor::moveLeft()
{
    if (currentY > 0)
    {
        currentY--;
    }
}


