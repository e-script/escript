#include "escript.h"

static void * run(void * _self, void * _context) {
    struct Number * self = _self;

#ifdef VERBOSE
    printf("number_%d ", self->value);
#endif

    return new(NumberValue, self->value);
}

static void * constructor(void * _self, va_list * params) {
    struct Number * self = _self;

    self->value = va_arg(*params, int);
    self->parent.run = run;

    return self;
}

static const struct Class _Number = {
    sizeof (struct Number),
    constructor, 0, 0, 0
};
const void * Number = &_Number;