#include "escript.h"

void * assign(void * _reference, char * operator, void * _value, void * _contexts) {
    void * result = NULL;

    struct Reference * reference = _reference;
    struct Array * contexts = _contexts;
    struct Hash * context = contexts->get(contexts, contexts->size - 1);

    context->set(context, reference->name, _value);

    result = reference;

    return result;
}

void * operate(void * _a, char * operator, void * _b) {
    void * result = NULL;

    struct NumberValue * numberValueA, * numberValueB;

    if (classOf(_a) == NumberValue) {
        numberValueA = _a;
        if (classOf(_b) == NumberValue) {
            numberValueB = _b;
            if (strcmp(operator, "+") == 0) {
                result = new(NumberValue, numberValueA->value + numberValueB->value);
            } else if (strcmp(operator, "-") == 0) {
                result = new(NumberValue, numberValueA->value - numberValueB->value);
            } else if (strcmp(operator, "*") == 0) {
                result = new(NumberValue, numberValueA->value * numberValueB->value);
            } else if (strcmp(operator, "/") == 0) {
                result = new(NumberValue, numberValueA->value / numberValueB->value);
            } else {
                fputs("invalid operator", stderr);
                exit(-1);
            }
        } else {
            fputs("number expected", stderr);
            exit(-1);
        }
    }


    return result;
}