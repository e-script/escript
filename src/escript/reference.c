#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Reference * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;

#ifdef VERBOSE
    printf("reference_%s ", self->name);
#endif
    
    int i;
    for (i = contexts->size - 1; i >= 0; i--)
    {
        context = contexts->get(contexts, i);
        if (context->contains(context, self->name))
        {
            result = context->get(context, self->name);
            break;
        }
    }

    if (result == NULL) {
        fputs("unknown_reference", stderr);
        exit(-1);
    }

    return result;
}

static void *constructor(void * _self, va_list * params) {
    struct Reference * self = _self;

    self->name = va_arg(*params, char *);
    self->parent.run = run;

    return self;
}

static const struct Class _Reference = {
    sizeof (struct Reference),
    constructor, 0, 0, 0
};
const void * Reference = &_Reference;