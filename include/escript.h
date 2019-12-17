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
 Stack
 */
struct Stack {
    const void * class;

    int size;
    int buffer_size;
    void ** elements;

    int (* append)(void * _self, void * element);
    void * (* get)(void * _self, size_t index);
    void * (* pop)(void * _self);
    void (* reverse)(void * _self);
};
const void * Stack;

struct Hash {
    const void * class;

    int size;
    struct Stack * keys;
    struct Stack * entries;

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

    void * (* run)(void * _self, void * _contexts);
};

struct Number {
    struct Operand parent;

    int value;
};
const void * Number;

struct Reference {
    struct Operand parent;

    char * name;
};
const void * Reference;

struct Set {
    struct Operand parent;

    struct Stack * operands;
};
const void * Set;

struct Array {
    struct Operand parent;

    struct Stack * operands;
};
const void * Array;

struct Expression {
    struct Operand parent;

    struct Stack * operands;
    struct Stack * operators;
};
const void * Expression;

struct Invoke {
    struct Operand parent;

    char * name;
    struct Stack * operands;
};
const void * Invoke;

struct Locate {
    struct Operand parent;

    char * name;
    struct Operand * operand;
};
const void * Locate;

void * set_build(void * _source);
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

struct SetValue {
    struct Value parent;

    struct Hash * values;
};

const void * SetValue;

struct ArrayValue {
    struct Operand parent;

    struct Stack * values;
};
const void * ArrayValue;

/*
 Function
 */
struct Function {
    struct Operand parent;

    struct Set * params;
    struct Set * body;
};
const void * Function;

/*
 Body
 */
struct Body {
    const void * class;

    struct Stack * operands;

    void (* build)(void * _self, void * _source);
    void * (* run)(void * _self, void * _contexts);
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

    struct Set * set;

    int (* checkFileExists)(char * filePath);
    int (* read)(void * _self);
    int (* hasNextToken)(void * _self);
    char * (* getNextToken)(void * _self);
    char * (* popNextToken)(void * _self);
    void (* matchToken)(void * _self, char * token);
    void (* build)(void * _self);
    void * (* run)(void * _self, void * _contexts);
};
const void * Source;


#endif /* ESCRIPT_H */

