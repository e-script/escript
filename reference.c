#include "escript.h"

static void * Reference_run(void * _self) {
    struct Reference * self = _self;

#ifndef RELEASE
    printf("reference_%s ", self->name);
#endif

    return NULL;
}

static void *Reference_constructor(void * _self, va_list * params) {
    struct Reference * self = _self;

    self->name = va_arg(*params, char *);
    self->operand.run = Reference_run;

    return self;
}

static const struct Class _Reference = {
    sizeof (struct Reference),
    Reference_constructor, 0, 0, 0
};
const void * Reference = &_Reference;