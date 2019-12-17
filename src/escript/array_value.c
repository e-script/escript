#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct ArrayValue * self = _self;

    self->values = va_arg(*params, struct Stack *);
    self->parent.run = run;

    return self;
}

static const struct Class _ArrayValue = {
    sizeof (struct ArrayValue),
    constructor, 0, 0, 0
};

const void * ArrayValue = &_ArrayValue;