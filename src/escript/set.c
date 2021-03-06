#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Set * self = _self;
    struct Operand * operand;
    struct Expression * expression;

    struct Stack * contexts = _contexts;
    struct Hash * context = new(Hash);
    contexts->append(contexts, context);

#ifdef VERBOSE
    printf("set(\n");
#endif

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        if (classOf(operand) == Expression) {
            expression = self->operands->get(self->operands, i);
            if (expression->operands->size == 1
                    && classOf(expression->operands->get(expression->operands, 0)) == Reference) {
                /*skip comment word*/
                continue;
            }
        }
        operand->run(operand, contexts);
    }

#ifdef VERBOSE
    printf(")\n");
#endif

    contexts->pop(contexts);

    result = new(SetValue, context);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Set * self = _self;

    self->operands = va_arg(*params, struct Stack *);

    self->parent.run = run;

    return self;
}

static const struct Class _Set = {
    sizeof (struct Set),
    constructor, 0, 0, 0
};

const void * Set = &_Set;