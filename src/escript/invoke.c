#include "escript.h"

static char * cut(char * name) {
    char * result = NULL;

    int i;
    for (i = strlen(name) - 1; i >= 0; i--) {
        if (name[i] == '.') {
            result = calloc(sizeof (char), i + 1);
            memcpy(result, name, i);
        }
    }

    return result;
}

static void * get(void * _contexts, char * name) {
    void * result = NULL;

    struct Stack * contexts = _contexts;
    struct Hash * context;

    int i;

    if (name != NULL) {
        for (i = contexts->size - 1; i >= 0; i--) {
            context = contexts->get(contexts, i);
            if (context->contains(context, name)) {
                result = context->get(context, name);
                break;
            }
        }
    }

    return result;
}

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Invoke * self = _self;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct Function * function;
    struct Operand * operand;
    void * set_value;
    void * operand_result;
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
    operand = get(_contexts, self->name);

    if (operand == NULL) {
        fputs("unknown_invoke_reference", stderr);
        exit(-1);
    }

    if (classOf(operand) != Function) {
        fputs("reference_is_not_a_function", stderr);
        exit(-1);
    }
    function = (struct Function *) operand;

    set_value = get(_contexts, cut(self->name));

    /*run arguments*/
    context = new(Hash);
    context->set(context, "params", new(ArrayValue, params));
    contexts->append(contexts, context);

    /*get parent*/
    if (set_value != NULL) {
        context = new(Hash);
        context->set(context, "parent", set_value);
        contexts->append(contexts, context);
    }

    /*run body*/
    body_result = function->parent.run(function, _contexts);

    result = body_result->values->get(body_result->values, "result");

    if (set_value != NULL) {
        contexts->pop(contexts);
    }
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