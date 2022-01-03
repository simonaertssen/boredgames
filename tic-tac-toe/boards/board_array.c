// Represent the board using different data structures.

/*
Module imports.
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*
File imports.
*/
#include "board_array.h"

/*
Check whether the game is over.
The positions on the board are encoded as -1 and 1, so a simple sum should do.
*/
bool is_board_array_game_over(BOARDARRAY *board) {
    // Check every row
    for (short i = 0; i < BOARDSIZE; i += BOARDWIDTH) {
        if (abs(board[i] + board[i + 1] + board[i + 2]) == 3) return true;
    }

    // Check every column
    for (short i = 0; i < BOARDWIDTH; i++) {
        if (abs(board[i] + board[i + 3] + board[i + 6]) == 3)
            return true;
    }

    // Check main and off diagonal
    if (abs(board[0] + board[4] + board[8]) == 3) return true;
    if (abs(board[2] + board[4] + board[6]) == 3) return true;

    return false;
}

/*
Return a list of possible moves that can be played on the board.
*/
void *get_board_array_next_moves(BOARDARRAY *board, short *next_moves, short num_moves_played) {
    // short *next_moves[9];  // Don't use VLAs for this information, the player knows how many moves are still left as they decrease monotonically.
    short pos, move = 0;
    for (pos = 0; pos < BOARDSIZE; pos++) {
        if (board[pos] == 0) next_moves[move++] = pos;
    }
}
