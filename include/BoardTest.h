#ifndef HW_02_BOARDTEST_H
#define HW_02_BOARDTEST_H


#include "Test.h"

class BoardTest : Test
{
public:
    void runAllTests() override;

private:
    static void testIsWinX();
    static void testIsWinO();
    static void testDraw();
    static void testInterrupting();
    static void testInProgress();

    static void getTurnNumber1();
    static void getTurnNumber2();
    static void getTurnNumber3();

    static void moving1();
    static void moving2();
    static void moving3();
    static void moving4();


    static void getting1();
    static void getting2();
    static void getting3();


    static void width1();
    static void width2();
    static void width3();

    static void height1();
    static void height2();
    static void height3();
};


#endif //HW_02_BOARDTEST_H
