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
    // First test some boards where the games did not end yet.
    for (short p = -1; p < 2; p += 2) {
        {
            BOARD board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            CuAssertBoolEquals(tc, false, game_over(board));
        }
        {
            BOARD board[9] = {0, p, p, p, 0, p, p, p, 0};
            CuAssertBoolEquals(tc, false, game_over(board));
        }
    }

    // Then test some boards where the game definitely has ended.
    for (short p = -1; p < 2; p += 2) {
        {
            BOARD board[9] = {p, p, p, 0, 0, 0, 0, 0, 0};
            CuAssertBoolEquals(tc, true, game_over(board));
        }
        {
            BOARD board[9] = {0, 0, p, 0, 0, p, 0, 0, p};
            CuAssertBoolEquals(tc, true, game_over(board));
        }
        {
            BOARD board[9] = {0, 0, p, 0, p, 0, p, 0, 0};
            CuAssertBoolEquals(tc, true, game_over(board));
        }
        {
            BOARD board[9] = {p, 0, 0, 0, p, 0, 0, 0, p};
            CuAssertBoolEquals(tc, true, game_over(board));
        }
    }
}

/* test_board_array
Gather all tests for this class and run them in a single function call.
*/
CuSuite *board_array_test_suite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_game_over);
    return suite;
}
