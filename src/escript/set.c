#include "escript.h"

static void * run(void * _self, void * _context) {
    struct Set * self = _self;

#ifdef VERBOSE
    printf("set(");
    int i;
    for (i = 0; i < self->names->size; i++) {
        if (i == self->names->size - 1) {
            printf("name_%s ", (char*) self->names->get(self->names, i));
        } else {
            printf("name_%s, ", (char*) self->names->get(self->names, i));
        }
    }
    printf(") ");
#endif

    return NULL;
}

static void * constructor(void * _self, va_list * params) {
    struct Set * self = _self;

    self->names = va_arg(*params, struct Array *);

    self->parent.run = run;

    return self;
}

static const struct Class _Set = {
    sizeof (struct Set),
    constructor, 0, 0, 0
};

const void * Set = &_Set;