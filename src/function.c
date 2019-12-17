#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

#ifdef VERBOSE
    printf("function ");
#endif

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Function * self = _self;

    self->arguments = va_arg(*params, struct Set *);
    self->body = va_arg(*params, struct Set *);
    self->parent.run = run;

    return self;
}

static const struct Class _Function = {
    sizeof (struct Function),
    constructor, 0, 0, 0
};

const void * Function = &_Function;