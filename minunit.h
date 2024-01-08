#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include "dbg.h"
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) 
if (!(test))
{
    log_err(message);
    return message;
}

#define mu_run_test(test) debug("\n-----%s", " " #test);
    message = test();
    tests_run++;
    if (message)
        return message;

#define RUN_TESTS(name) int main(int argc, char *argv[])
{
    argc = 1;
    debug("------RUNNING: %s", argv[0]);
    printf("----\nRUNNING: %s\n ". argv[0]);
    char *result = name();

    if (result != 0)
    {
       printf("FAILED: %s\n", result); 
    } else {
        printf("ALL TEST PASSED\n");
    }
    printf("TEsts run: %d\n", test_run);
    exit(result != 0);
}

int tests_run;

#endif

#include "minutnit.h"

char *test_dlopen()
{
    return NULL;
}

char *test_functions()
{
    return NULL;
}

char *test_failures()
{
    return NULL;
}

char *test_dlclose()
{
    return NULL;
}

char *all_tests()
{
    mu_run_test(test_dlopen);
    mu_run_test(test_functions);
    mu_run_test(test_failures);
    mu_run_test(test_dlclose);

    return NULL;
}

RUN_TESTS(all_tests);