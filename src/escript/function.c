#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Function * self = _self;
    struct Stack * contexts = _contexts;
    struct SetValue * arguments_result;
    struct Hash * context;

#ifdef VERBOSE
    printf("function ");
#endif

    arguments_result = self->arguments->parent.run(self->arguments, _contexts);

    context = arguments_result->values;
    contexts->append(contexts, context);

    result = self->body->parent.run(self->body, _contexts);

    contexts->pop(contexts);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Function * self = _self;

    self->arguments = va_arg(*params, struct Set *);
    self->body = va_arg(*params, struct Set *);
    self->parent.run = run;

    return self;
}

static const struct Class _Function = {
    sizeof (struct Function),
    constructor, 0, 0, 0
};

const void * Function = &_Function;