#include "escript.h"

static void * Number_run(void * _self) {
    struct Number * self = _self;

#ifndef RELEASE
    printf("number_%d ", self->value);
#endif

    return NULL;
}

static void * Number_constructor(void * _self, va_list * params) {
    struct Number * self = _self;

    self->value = va_arg(*params, int);
    self->operand.run = Number_run;

    return self;
}

static const struct Class _Number = {
    sizeof (struct Number),
    Number_constructor, 0, 0, 0
};
const void * Number = &_Number;