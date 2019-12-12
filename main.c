/* 
 * File:   main.c
 * Author: chien
 *
 * Created on December 12, 2019, 10:14 AM
 */

#include <stdio.h>

#include "oop.h"
#include "escript.h"

int main(int param_count, char ** params) {
    if (param_count == 0) {
        fputs("Please input a filename", stderr);
    } else {
        char * filepath = params[1];

        struct Source * source = new(Source, filepath);

        if (source == NULL) {
            fputs("Unable to open source code", stderr);
        } else {
            printf("Running: %s\n", filepath);
            source->read(source);
            printf("Build source:\n%s\n", source->value);
            source->build(source);
        }
    }
}