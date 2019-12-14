#include "escript.h"

static void * constructor(void * _self, va_list * params) {
    struct NumberValue * self = _self;

    self->value = va_arg(* params, int);

    return self;
}

static const struct Class _NumberValue = {
    sizeof (struct NumberValue),
    constructor, 0, 0, 0
};

const void * NumberValue = &_NumberValue;