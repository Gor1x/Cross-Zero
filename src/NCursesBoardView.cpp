#include "NCursesBoardView.h"


#define debug(x) mvprintw(10, 10, x); printw("\n");

NCursesBoardView::NCursesBoardView(Board &board_) : board(board_),
                                                    cursor(board.getHeight(),
                                                            board.getWidth(),
                                                                board)
{
    init();
    cursor.initCursorWindow();
    wmove(cursor.getWindow(), 0, 0);
}

void NCursesBoardView::showBoard() const
{

    wmove(cursor.getWindow(), 0, 0);
    for (size_t i = 0; i < board.getHeight(); i++)
    {
        for (size_t j = 0; j < board.getWidth(); j++)
        {
            cursor.drawColored(i, j, false);
        }
    }
    wrefresh(cursor.getWindow());
    cursor.draw();
}



void NCursesBoardView::doGameCycle()
{
    if (board.gameState() != IN_PROGRESS)
        return;

    wmove(cursor.getWindow(), 0, 0 );

    showBoard();


    char currentSign = (board.getTurnNumber() % 2)
                       ? 'O'
                       : 'X';


    while (true)
    {
        int key = getch();

        if (key == 'x')
        {
            board.makeMove(-1, -1, currentSign);
            break;
        }
        else if (key == ' ')
        {
            if (board.canMove(cursor.getX(), cursor.getY()))
            {
                board.makeMove(cursor.getX(), cursor.getY(), currentSign);
                break;
            }
        }
        else
        {
            cursor.moveCursor(key);
        }
    }
    cursor.draw();
}


void NCursesBoardView::printGameResult()
{
    showBoard();
    if (board.gameState() == X_WIN)
        wprintw(cursor.getWindow(), "X wins!");
    else if (board.gameState() == O_WIN)
        wprintw(cursor.getWindow(), "O wins!");
    else
        wprintw(cursor.getWindow(), "Draw.");

    wprintw(cursor.getWindow(), "\nUse any key to exit the game");
}

void NCursesBoardView::init()
{
    initscr();

    raw();
    noecho();
    keypad(stdscr, true);

    start_color();
    init_pair(BACKGROUND_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(CURSOR_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(X_COLOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(O_COLOR, COLOR_RED, COLOR_BLACK);
    attron(PAIR_NUMBER(BACKGROUND_COLOR));
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
    wmove(window, getX(), getY());
    drawColored(getX(), getY());
    wmove(window, getX(), getY());
    wrefresh(window);
}

void NCursesBoardView::Cursor::draw()
{
    wmove(window, getX(), getY());
    drawColored(getX(), getY(), true);
    wmove(window, getX(), getY());
    wrefresh(window);
}



void NCursesBoardView::Cursor::moveCursor(int command)
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


    wattron(window, COLOR_PAIR(color));

    if (char(board.get(i, j)) == '.')
        wprintw(window, " ");
    else
        wprintw(window, "%c", char(board.get(i, j)));

    wattroff(window, COLOR_PAIR(color));
}

WINDOW *NCursesBoardView::Cursor::getWindow() const
{
    return window;
}

NCursesBoardView::Cursor::~Cursor()
{
    delwin(window);
}

void NCursesBoardView::Cursor::initCursorWindow()
{
    move(1, 1);
    window = newwin(board.getHeight(), board.getWidth(), 1, 1);
    wrefresh(window);
}


