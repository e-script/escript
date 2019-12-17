#include "escript.h"

static void * run(void * _self, void * _contexts) {
    struct Invoke * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct Function * function;
    struct Operand * operand;
    void * operand_result;
    struct SetValue * param_result;
    struct Stack * operand_results = new(Stack);/*

#ifdef VERBOSE
    printf("invoke_%s(", self->name);
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

    for (i = contexts->size - 1; i >= 0; i--) {
        context = contexts->get(contexts, i);
        if (context->contains(context, self->name)) {
            operand = context->get(context, self->name);
            break;
        }
    }

    if (operand == NULL) {
        fputs("unknown_invoke_reference", stderr);
        exit(-1);
    }

    if (classOf(operand) != Function) {
        fputs("reference_is_not_a_function", stderr);
        exit(-1);
    }
    
    operand_result = function->params->parent.run(function->params, _contexts);
    if (classOf(operand_result) != SetValue)
    {
        fputs("params_set_does_not_return_a_set_value", stderr);
        exit(-1);
    }
    
    param_result = operand_result;
    
    */

    return NULL;
}

static void * constructor(void * _self, va_list * params) {
    struct Invoke * self = _self;

    self->name = va_arg(*params, char *);
    self->operands = va_arg(*params, struct Stack *);
    self->parent.run = run;

    return self;
}

static const struct Class _Invoke = {
    sizeof (struct Invoke),
    constructor, 0, 0, 0
};

const void * Invoke = &_Invoke;