#include "BoardTest.h"
#include "Board.h"

void BoardTest::runAllTests()
{
    testIsWinX();
    testIsWinO();
    testDraw();
    testInterrupting();
    testInProgress();

    getTurnNumber1();
    getTurnNumber2();
    getTurnNumber3();

    moving1();
    moving2();
    moving3();
    moving4();

    getting1();
    getting2();
    getting3();


    width1();
    width2();
    width3();

    height1();
    height2();
    height3();

    showFinalResult();
}

void BoardTest::testIsWinO()
{
    Board board(5, 5);
    board.makeMove(0, 0, 'O');
    board.makeMove(0, 1, 'O');
    board.makeMove(0, 2, 'O');
    board.makeMove(0, 3, 'O');
    board.makeMove(0, 4, 'O');
    DO_CHECK(board.gameState() == O_WIN);
}

void BoardTest::testIsWinX()
{
    Board board(5,5);
    for (size_t i = 0; i < 5; i++)
        board.makeMove(i, i, 'X');
    DO_CHECK(board.gameState() == X_WIN);
}

void BoardTest::testDraw()
{
    size_t n = 3;
    Board board(n, n);

    int turn = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            board.makeMove(i, j, (turn++) % 2 ? 'O' : 'X');

    DO_CHECK(board.gameState() == DRAW);
}

void BoardTest::testInterrupting()
{
    Board board(10, 10);
    board.makeMove(-1, -1, 'X');
    DO_CHECK(board.gameState() == INTERRUPTED);
}

void BoardTest::testInProgress()
{
    Board board(4, 5);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            board.makeMove(i, j, 'X');
    DO_CHECK(board.gameState() == IN_PROGRESS);
}

void BoardTest::getTurnNumber1()
{
    Board board(10, 10);
    for (size_t i = 0; i < 4; i++)
    {
        board.makeMove(i, i, 'X');
    }

    DO_CHECK(board.getTurnNumber() == 5);
}

void BoardTest::getTurnNumber2()
{
    Board board(10, 10);
    for (size_t i = 2; i < 8; i += 2)
    {
        board.makeMove(i, i, 'X');
    }

    DO_CHECK(board.getTurnNumber() == 4);
}

void BoardTest::getTurnNumber3()
{
    Board board(10, 10);
    DO_CHECK(board.getTurnNumber() == 1);
}

void BoardTest::moving1()
{
    Board board(10, 10);
    DO_CHECK(!board.canMove(-1, -1));
}

void BoardTest::moving2()
{
    Board board(10, 10);
    DO_CHECK(!board.canMove(10, 10));
}

void BoardTest::moving3()
{
    Board board(10, 10);
    board.makeMove(0, 0, 'X');
    DO_CHECK(!board.canMove(0, 0));
}

void BoardTest::moving4()
{
    Board board(10, 10);
    DO_CHECK(board.canMove(0, 0));
}

void BoardTest::getting1()
{
    Board board(10, 10);
    DO_CHECK(board.get(0, 0) == EMPTY);
}

void BoardTest::getting2()
{
    Board board(10, 10);
    board.makeMove(0, 0, 'X');
    DO_CHECK(board.get(0, 0) == X_SIGN);
}

void BoardTest::getting3()
{
    Board board(10, 10);
    board.makeMove(5, 5, 'O');
    DO_CHECK(board.get(5, 5) == O_SIGN);
}

void BoardTest::width1()
{
    Board board(7, 3);
    DO_CHECK(board.getWidth() == 3);
}

void BoardTest::width2()
{
    Board board(5, 18);
    DO_CHECK(board.getWidth() == 18);
}

void BoardTest::width3()
{
    Board board(32, 14);
    DO_CHECK(board.getWidth() == 14);
}

void BoardTest::height1()
{
    Board board(7, 3);
    DO_CHECK(board.getHeight() == 7);
}

void BoardTest::height2()
{
    Board board(5, 18);
    DO_CHECK(board.getHeight() == 5);
}

void BoardTest::height3()
{
    Board board(32, 14);
    DO_CHECK(board.getHeight() == 32);
}











