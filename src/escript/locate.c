#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;
    struct Locate * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    void * operand = NULL;
    void * operand_result;
    struct NumberValue * number_value;
    struct ArrayValue * array_value;

#ifdef VERBOSE
    printf("locate_%s ", self->name);
#endif

    operand_result = self->operand->run(self->operand, _contexts);
    if (classOf(operand_result) != NumberValue) {
        fputs("locate_expression_must_return_an_non_negative_integer", stderr);
        exit(-1);
    }
    number_value = operand_result;

    int i;
    for (i = contexts->size - 1; i >= 0; i--) {
        context = contexts->get(contexts, i);
        if (context->contains(context, self->name)) {
            operand = context->get(context, self->name);
            break;
        }
    }

    if (operand == NULL) {
        fputs("unknown_locate_reference", stderr);
        exit(-1);
    }

    if (classOf(operand) != ArrayValue) {
        fputs("locate_reference_is_not_an_array", stderr);
        exit(-1);
    }

    array_value = operand;
    
    result = array_value->values->get(array_value->values, number_value->value);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Locate * self = _self;

    self->name = va_arg(*params, char *);
    self->operand = va_arg(*params, struct Operand *);
    self->parent.run = run;

    return self;
}

static const struct Class _Locate = {
    sizeof (struct Locate),
    constructor, 0, 0, 0
};

const void * Locate = &_Locate;