#include "escript.h"

static void * run(void * _self, void * _context) {
    void * result = NULL;

    struct Reference * self = _self;

    struct Hash * context = _context;

#ifdef VERBOSE
    printf("reference_%s ", self->name);
#endif
    result = context->get(context, self->name);

    if (result == NULL) {
        fputs("unknown_reference", stderr);
        exit(-1);
    }

    return result;
}

static void *constructor(void * _self, va_list * params) {
    struct Reference * self = _self;

    self->name = va_arg(*params, char *);
    self->first = 0;
    self->parent.run = run;

    return self;
}

static const struct Class _Reference = {
    sizeof (struct Reference),
    constructor, 0, 0, 0
};
const void * Reference = &_Reference;