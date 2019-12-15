#include "escript.h"

static void * constructor(void * _self, va_list * params) {
    struct SetValue * self = _self;

    self->values = va_arg(*params, struct Hash *);

    return self;
}

static const struct Class _SetValue = {
    sizeof (struct SetValue),
    constructor, 0, 0, 0
};

const void * SetValue = &_SetValue;