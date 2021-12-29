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
// None

int main(int argc, char** argv) {
    printf("Starting tic-tact-toe main.\n");

    // Select which type of main to run
    char optchar;
    while ((optchar = getopt(argc, argv, "t")) != -1) {
        switch (optchar) {
        case 't':

        }
    }

    return 0;
}