// Main file for the tic-tac-toe game.

#define _POSIX_C_SOURCE 200112L

/*
Module imports.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*
File imports.
*/
#include "./test_board_array.h"

int main(int argc, char** argv) {
    printf("Starting tic-tact-toe main.\n");

    // Select which type of main to run
    char optchar;
    while ((optchar = getopt(argc, argv, "t")) != -1) {
        switch (optchar) {
        case 't':
            printf("Starting tic-tact-toe test suite.\n");
            test_board_array();
        }
    }

    return 0;
}

