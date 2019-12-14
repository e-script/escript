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
    void * (* pop)(void * _self);
};
const void * Array;

struct Hash {
    const void * class;

    int size;
    struct Array * keys;
    struct Array * entries;

    void (* set)(void * _self, char * key, void * element);
    int (* contains)(void * _self, char * key);
    void * (* get)(void * _self, char * key);
    void * (* pop)(void * _self, char * key);
};
const void * Hash;

/*
 Operand
 */
struct Operand {
    const void * class;

    void * (* run)(void * _self, void * _context);
};

struct Number {
    struct Operand parent;

    int value;
};
const void * Number;

struct Reference {
    struct Operand parent;

    char * name;
    int first;
};
const void * Reference;

struct Set {
    struct Operand parent;

    struct Array * names;
};
const void * Set;

struct Expression {
    struct Operand parent;

    struct Array * operands;
    struct Array * operators;
};
const void * Expression;

struct Invoke {
    struct Operand parent;

    char * name;
    struct Array * operands;
};
const void * Invoke;

void * operand_build(void * _source);

/*
 Value
 */
struct Value {
    const void * class;
};

struct NumberValue {
    struct Value parent;
    int value;
};
const void * NumberValue;

/*
 Body
 */
struct Body {
    const void * class;

    struct Array * operands;

    void (* build)(void * _self, void * _source);
    void * (* run)(void * _self, void * _context);
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
    void * (* run)(void * _self, void * _context);
};
const void * Source;


void * assign(void * _reference, char * operator,void * _value, void * _context);
void * operate(void * _a, char * operator,void * _b);

#endif /* ESCRIPT_H */
