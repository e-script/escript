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
    void * (* get)(void * _self, size_t index);
};
const void * Array;

/*
 Operand
 */
struct Operand {
    const void * class;

    void * (* run)(void * _self);
};

struct Number {
    struct Operand operand;

    int value;
};
const void * Number;

struct Reference {
    struct Operand operand;

    char * name;
};
const void * Reference;

struct Expression {
    struct Operand operand;

    struct Array * operands;
    struct Array * operators;
};
const void * Expression;

struct Invoke {
    struct Operand operand;

    char * name;
    struct Array * operands;
};
const void * Invoke;

void * operand_build(void * _source);

/*
 Body
 */
struct Body {
    const void * class;

    struct Array * operands;

    void (* build)(void * _self, void * _source);
    void * (* run)(void * _self);
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
    void * (* run)(void * _self);
};
const void * Source;

#endif /* ESCRIPT_H */

