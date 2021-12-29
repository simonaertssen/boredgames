// Represent the board using different data structures

/*
Module imports.
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/*
File imports.
*/
#include "board_array.h"

/*
Check whether the game is over.
The positions on the board are encoded as -1 and 1, so a simple sum should do.
*/
bool game_over(BOARD *board) {

    // Check every row
    for (short i = 0; i < 3; i++) {
        if (abs(board[i] + board[i+1] + board[i+2]) == 3)
            return true;
    }

    // Check every column
    for (short i = 0; i < 3; i++) {
        if (abs(board[i] + board[i+3] + board[i+6]) == 3)
            return true;
    }

    // Check main and off diagonal
    if (abs(board[0] + board[4] + board[8]) == 3) return true;
    if (abs(board[2] + board[4] + board[6]) == 3) return true;

    return false;
}

