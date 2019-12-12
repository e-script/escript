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
#include "charaters.h"

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
 Operand
 */
struct Operand {
    const void * class;
};

struct Number {
    const void * class;

    int value;
};
const void * Number;

struct Reference {
    const void * class;

    char * name;
};
const void * Reference;

struct Expression {
    const void * class;

    struct Array * operands;
    struct Array * operators;
};
const void * Expression;

void * operand_build(void * _source);

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

    size_t offset;

    struct Body * body;

    int (* checkFileExists)(char * filePath);
    int (* read)(void * _self);
    int (* hasNextToken)(void * _self);
    char * (* getNextToken)(void * _self);
    char * (* popNextToken)(void * _self);
    void (* matchToken)(void * _self, char * token);
    void (* build)(void * _self);
};
const void * Source;

#endif /* ESCRIPT_H */

