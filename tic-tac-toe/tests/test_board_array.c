// Test the different board implementations and functions

/*
Module imports.
*/
#include <stdbool.h>
#include <stdio.h>

/*
File imports.
*/
#include "../../testing/CuTest.h"
#include "../boards/board_array.h"

/* test_game_over
Test whether the game over functionality works correctly.
A game should end when three symbols can be found in a line.
Return true if the test is correct.
*/
void test_game_over(CuTest *tc) {
    printf("Testing paths");

    BOARD board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool expected = false;
    bool actual = game_over(board);
    CuAssertBoolEquals(tc, expected, actual);

    // board[3] = 1;
    // board[4] = 1;
    // board[5] = 1;
    // if (game_over(board) == true) return -1;

    // if (game_over(board) == true) return -1;
    // return 0;
}

/* test_board_array
Gather all tests for this class and run them in a single function call.
*/
CuSuite* board_array_test_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_game_over);
    return suite;
}
    