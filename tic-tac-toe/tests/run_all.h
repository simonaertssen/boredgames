#if !defined(RUN_ALL)
#define RUN_ALL

// Custom macro to get test file info
// #define verify(ans) verify_info((ans), __FILE__, __LINE__)

/*
Imports
*/
#include <stdbool.h>

/*
A single function calls all possible functions in this directory.
*/
void run_all_tests();

#endif // RUN_ALL