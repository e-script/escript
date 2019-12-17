#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Array * self = _self;

    struct Stack * operand_results = new(Stack);
    struct Operand * operand;
    void * operand_result;

#ifdef VERBOSE
    printf("array( ");
#endif

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand_result = operand->run(operand, _contexts);
        operand_results->append(operand_results, operand_result);
    }

#ifdef VERBOSE
    printf(") ");
#endif

    result = new(ArrayValue, operand_results);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Array * self = _self;

    self->operands = va_arg(*params, struct Stack *);
    self->parent.run = run;

    return self;
}

static const struct Class _Array = {
    sizeof (struct Array),
    constructor, 0, 0, 0
};

const void * Array = &_Array;