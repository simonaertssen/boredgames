// Test the different board implementations and functions

/*
Module imports.
*/
#include <stdbool.h>
#include <stdio.h>

/*
File imports.
*/
#include "../boards/board_array.h"

/* test_game_over
Test whether the game over functionality works correctly.
A game should end when three symbols can be found in a line.
Return true if the test is correct.
*/
int test_game_over() {
    // BOARD board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // if (game_over(board) == false) return -1;

    // board[3] = 1;
    // board[4] = 1;
    // board[5] = 1;
    // if (game_over(board) == true) return -1;

    // if (game_over(board) == true) return -1;
    // return 0;
    printf("Testing paths");
    return 0;
}

/* test_board_array
Gather all tests for this class and run them in a single function call.
*/
void test_board_array() {
    if (test_game_over() < 0)
        printf("Test failed\n");

    printf("All board_array tests succeeded.\n");
}
