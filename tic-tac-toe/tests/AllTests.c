// Main test file for CuTest.

/*
Module imports.
*/
#include <stdio.h>

/*
File imports.
*/
#include "AllTests.h"
#include "../../testing/CuTest.h"

CuSuite* board_array_test_suite();
    
void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
        
    CuSuiteAddSuite(suite, board_array_test_suite());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}