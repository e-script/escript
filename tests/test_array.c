/*
 * File:   test_array.c
 * Author: chien
 *
 * Created on December 12, 2019, 6:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "escript.h"

/*
 * Simple C Test Suite
 */

void test1() {
    printf("%%TEST_STARTED%% test1 (test_array)\n");

    int a = 5, b = 6;

    struct Array * array = new(Array);
    array->append(array, &a);
    array->append(array, &b);
    if (array->size != 2) {
        printf("%%TEST_FAILED%% time=0 testname=test1 (test_array) "
                "message=Wrong array size\n");
    }
    if (array->buffer_size != 4)
    {
        printf("%%TEST_FAILED%% time=0 testname=test1 (test_array) "
                "message=Wrong buffer size\n");
    }

    printf("%%TEST_FINISHED%% time=0 test1 (test_array) \n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% test_array\n");
    printf("%%SUITE_STARTED%%\n");

    test1();

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
