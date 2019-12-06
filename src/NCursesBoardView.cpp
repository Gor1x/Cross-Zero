#include "NCursesBoardView.h"

NCursesBoardView::NCursesBoardView(Board &board_) : board(board_),
                                                    cursor(board.getHeight(),
                                                            board.getWidth(),
                                                                board)
{
    init();

}

void NCursesBoardView::showBoard() const
{
    move(0, 0);
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            cursor.drawColored(i, j, false);
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

    cursor.moveToPosition();



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

void NCursesBoardView::init()
{
    initscr();

    move(0, 0);

    raw();
    noecho();
    keypad(stdscr, true);

    start_color();
    init_pair(BACKGROUND_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(CURSOR_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(X_COLOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(O_COLOR, COLOR_RED, COLOR_BLACK);


    attron(PAIR_NUMBER(BACKGROUND_COLOR));

    auto local_win = newwin(board.getHeight() + 2, board.getWidth() + 2, 0, 0);
    box(local_win, 0, 0);
    wrefresh(local_win);/* 0, 0 gives default characters
     * for the vertical and horizontal
     * lines */
   // wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wmove(local_win, 0, 0);
    //wprintw(local_win, "kek");
    wrefresh(local_win); /* Show that box */
    delwin(local_win);
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
    drawColored(getX(), getY());
    ::move(getX(), getY());
    refresh();
}

void NCursesBoardView::Cursor::draw()
{
    ::move(getX(), getY());
    drawColored(getX(), getY(), true);
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

void NCursesBoardView::Cursor::drawColored(size_t i, size_t j, bool underCursor) const
{
    POSITION_STATE current = board.get(i, j);

    int color;
    if (underCursor)
    {
        color = CURSOR_COLOR;
    }
    else
    {
        if (current == X_SIGN)
            color = X_COLOR;
        else if (current == O_SIGN)
            color = O_COLOR;
        else
            color = BACKGROUND_COLOR;
    }
    attron(COLOR_PAIR(color));

    if (char(board.get(i, j)) == '.')
        printw(" ");
    else
        printw("%c", char(board.get(i, j)));

    attroff(COLOR_PAIR(color));
}

void NCursesBoardView::Cursor::moveToPosition()
{
    ::move(currentX, currentY);
    drawColored(currentX, currentY, true);
    ::move(currentX, currentY);
}



