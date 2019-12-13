#include "escript.h"

static void * Expression_run(void * _self) {
    struct Expression * self = _self;

    struct Operand * operand;
    char * operator;

#ifndef RELEASE
    printf("expression(");
#endif

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand->run(operand);
        if (i < self->operators->size) {
            operator = self->operators->get(self->operators, i);
#ifndef RELEASE
            printf("operator_%s ", operator);
#endif
        }
    }

#ifndef RELEASE
    printf(") ");
#endif

    return NULL;
}

static void * Expression_constructor(void * _self, va_list * params) {
    struct Expression * self = _self;

    self->operands = va_arg(*params, struct Array *);
    self->operators = va_arg(*params, struct Array *);
    self->operand.run = Expression_run;

    return self;
}

static const struct Class _Expression = {
    sizeof (struct Expression),
    Expression_constructor, 0, 0, 0
};
const void * Expression = &_Expression;