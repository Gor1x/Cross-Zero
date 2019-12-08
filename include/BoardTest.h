#ifndef HW_02_BOARDTEST_H
#define HW_02_BOARDTEST_H


#include "Test.h"

class BoardTest : Test
{
public:
    void runAllTests() override;

private:
    static void testGameWinX();

    static void testGameWinO();

    static void testGameDraw();

    static void testGameInterrupted();

    static void testGameInProgress();

    static void getTurnNumberAfterOperations1();

    static void getTurnNumberAfterOperations2();

    static void getTurnNumberFirstTurn();

    static void movingNegativeCoordinates();

    static void movingBigCoordinates();

    static void movingOnNonEmptyField();

    static void movingGoodMove();


    static void gameWinHorizontal();

    static void gameWinMainDiagonal();

    static void gameWinSideDiagonal();

    static void gameWinVertical();


    static void gettingEmpty();

    static void gettingSignX();

    static void gettingSignO();


    static void width1();
    static void width2();
    static void width3();

    static void height1();
    static void height2();
    static void height3();

    static void winLastTurn();

};


#endif //HW_02_BOARDTEST_H
