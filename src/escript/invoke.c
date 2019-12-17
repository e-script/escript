#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Invoke * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct Function * function;
    struct Operand * operand;
    void * operand_result;
    struct SetValue * arguments_result;
    struct SetValue * body_result;
    struct Stack * params;
    int i;

#ifdef VERBOSE
    printf("invoke_%s(", self->name);
#endif
    /*run params*/
    params = new(Stack);
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand_result = operand->run(operand, _contexts);
        params->append(params, operand_result);
    }

    /*get function*/
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
    function = (struct Function *) operand;

    /*run arguments*/
    context = new(Hash);
    context->set(context, "params", new(ArrayValue, params));
    contexts->append(contexts, context);

    arguments_result = function->arguments->parent.run(function->arguments, _contexts);

    context = arguments_result->values;
    contexts->append(contexts, context);

    /*run body*/
    body_result = function->body->parent.run(function->body, _contexts);

    result = body_result->values->get(body_result->values, "result");

    contexts->pop(contexts);
    contexts->pop(contexts);

    return result;
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