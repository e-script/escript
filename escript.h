/* 
 * File:   Escript.h
 * Author: chien
 *
 * Created on December 12, 2019, 10:31 AM
 */

#ifndef ESCRIPT_H
#define ESCRIPT_H

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "oop.h"

/*
 Array
 */
struct Array {
    const void * class;

    int size;
    int buffer_size;
    void ** elements;

    int (* append)(void * _self, void * element);
};
const void * Array;


/*
 Body
 */
struct Body {
    const void * class;

    struct Array * operands;

    void (* build)(void * _self, void * _source);
};
const void * Body;

/*
 Source
 */

struct Source {
    const void * class;

    char * filePath;
    size_t length;
    char * value;

    struct Body * body;

    int (* checkFileExists)(char * filePath);
    int (* read)(void * _self);
    void (* build)(void * _self);
};
const void * Source;

#endif /* ESCRIPT_H */

