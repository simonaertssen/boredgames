// Test the different board implementations and functions

/*
Module imports.
*/
#include <stdbool.h>

/*
File imports.
*/
#include "run_all.h"
#include "./boards/board_array.h"

/* test_board_array
Gather all tests for this class and run them in a single function call.
*/
void test_board_array() {
    verify(test_game_over());
}

/* test_game_over
Test whether the game over functionality works correctly.
A game should end when three symbols can be found in a line.
*/
bool test_game_over() {
    BOARD board = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (game_over(&board)) return false;
}
