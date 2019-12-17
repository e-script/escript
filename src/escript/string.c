#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;
    
    struct String * self = _self;
    
    result = new(StringValue, self->value);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct String * self = _self;

    self->value = va_arg(*params, char *);
    self->parent.run = run;

    return self;
}

static const struct Class _String = {
    sizeof (struct String),
    constructor, 0, 0, 0
};

const void * String = &_String;