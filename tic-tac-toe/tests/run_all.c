// Run all available tests.

/*
Module imports.
*/
#include <stdio.h>
#include <stdlib.h>

/*
File imports.
*/
#include "run_all.h"
#include "test_board_array.h"

/* verify_info
Get the information of the test if it did not return true.
*/
void verify_info(bool output, const char *file, int line){
	if (output != true){
		fprintf(stderr, "Test FAILED in file %s, line %d\n", file, line);
    	exit(1);
   }
}

/* run_all_tests
Gather all tests in this folder and run them.
*/
bool run_all_tests() {
    // Run board array tests.
    

    return true;
}


