#include "escript.h"

static void * constructor(void * _self, va_list * params) {
    struct StringValue * self = _self;
    
    self->value = va_arg(*params, char *);

    return self;
}

static const struct Class _StringValue = {
    sizeof (struct StringValue),
    constructor, 0, 0, 0
};

const void * StringValue = &_StringValue;