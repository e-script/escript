#include "escript.h"

static void * run(void * _self, void * _context) {
    struct Invoke * self = _self;

    struct Operand * operand;

#ifdef VERBOSE
    printf("invoke_%s(", self->name);
#endif
    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand->run(operand, _context);
    }
#ifdef VERBOSE
    printf(") ");
#endif

    return NULL;
}

static void * constructor(void * _self, va_list * params) {
    struct Invoke * self = _self;

    self->name = va_arg(*params, char *);
    self->operands = va_arg(*params, struct Array *);
    self->parent.run = run;

    return self;
}

static const struct Class _Invoke = {
    sizeof (struct Invoke),
    constructor, 0, 0, 0
};

const void * Invoke = &_Invoke;