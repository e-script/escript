/* 
 * File:   main.c
 * Author: chien
 *
 * Created on December 12, 2019, 10:14 AM
 */

#include "oop.h"
#include "escript.h"
#include "builtin.h"

int main(int param_count, char ** params) {
    if (param_count == 0) {
        fputs("Please input a filename", stderr);
    } else {
        char * filepath = params[1];

        struct Source * source = new(Source, filepath);

        if (source == NULL) {
            fputs("Unable to open source code", stderr);
        } else {
#ifdef VERBOSE
            printf("Running: %s\n", filepath);
#endif
            source->read(source);
#ifdef VERBOSE
            printf("Build source:\n%s\n", source->value);
#endif
            source->build(source);
#ifdef VERBOSE
            printf("Run:\n");
#endif
            struct Stack * contexts = new(Stack);
            struct Hash * context = new(Hash);
            context->set(context, "console", init_console());
            context->set(context, "network", init_network());
            contexts->append(contexts, context);
            void * result = source->run(source, contexts);
        }
    }
}