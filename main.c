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
#ifndef RELEASE
            printf("Running: %s\n", filepath);
#endif
            source->read(source);
#ifndef RELEASE
            printf("Build source:\n%s\n", source->value);
#endif
            source->build(source);
#ifndef RELEASE
            printf("Run:\n");
#endif
            source->run(source);
        }
    }
}