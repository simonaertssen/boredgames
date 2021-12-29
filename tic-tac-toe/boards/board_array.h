#if !defined(BOARD_ARRAY_H)
#define BOARD_ARRAY_H

/*
Define the board as a macro wrapping around an array
*/
#define BOARD short

/*
Function declarations
*/
bool game_over(BOARD *board);

#endif // BOARD_ARRAY_H