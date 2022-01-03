#if !defined(BOARD_ARRAY_H)
#define BOARD_ARRAY_H

/*
Define the board as a macro wrapping around an array
*/
#define BOARDARRAY short
#define BOARDWIDTH 3
#define BOARDSIZE 9

/*
Function declarations
*/
bool is_board_array_game_over(BOARDARRAY *board);
void get_board_array_next_moves(BOARDARRAY *board, short *next_moves, short num_moves_played);

#endif  // BOARD_ARRAY_H