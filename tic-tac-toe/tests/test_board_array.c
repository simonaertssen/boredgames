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
#include "../players.h"

/* test_is_game_over
Test whether the game_over functionality works correctly by 
feeding some board states and testing with the expected value.
*/
void test_is_game_over(CuTest *tc) {
    // First test some boards where the games did not end yet.
    for (short p = -1; p < 2; p += 2) {
        {
            BOARDARRAY board[BOARDSIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            CuAssertBoolEquals(tc, false, is_board_array_game_over(board));
        }
        {
            BOARDARRAY board[BOARDSIZE] = {0, p, p, p, 0, p, p, p, 0};
            CuAssertBoolEquals(tc, false, is_board_array_game_over(board));
        }
    }

    // Then test some boards where the game definitely has ended.
    for (short p = -1; p < 2; p += 2) {
        {
            BOARDARRAY board[BOARDSIZE] = {p, p, p, 0, 0, 0, 0, 0, 0};
            CuAssertBoolEquals(tc, true, is_board_array_game_over(board));
        }
        {
            BOARDARRAY board[BOARDSIZE] = {0, 0, p, 0, 0, p, 0, 0, p};
            CuAssertBoolEquals(tc, true, is_board_array_game_over(board));
        }
        {
            BOARDARRAY board[BOARDSIZE] = {0, 0, p, 0, p, 0, p, 0, 0};
            CuAssertBoolEquals(tc, true, is_board_array_game_over(board));
        }
        {
            BOARDARRAY board[BOARDSIZE] = {p, 0, 0, 0, p, 0, 0, 0, p};
            CuAssertBoolEquals(tc, true, is_board_array_game_over(board));
        }
    }
}

/* test_get_next_moves
Test whether the board returns the right possible positions. 
These are encoded as a list of shorts.
*/
void test_get_next_moves(CuTest *tc) {
    BOARDARRAY board[BOARDSIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    short next_moves[BOARDSIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};  // Don't use VLAs for this information, the player knows how many moves are still left as they decrease monotonically.
    short num_moves_played, player_sign;

    for (num_moves_played = 0; num_moves_played < BOARDSIZE; num_moves_played++) {
        // See if the next available move is the first available move
        get_board_array_next_moves(board, next_moves, num_moves_played);
        CuAssertShortEquals(tc, num_moves_played, next_moves[0]);

        // Play the first available move
        board[next_moves[0]] = 1;
    }
}

/* test_board_array
Gather all tests for this class and run them in a single function call.
*/
CuSuite *board_array_test_suite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_is_game_over);
    SUITE_ADD_TEST(suite, test_get_next_moves);
    return suite;
}
