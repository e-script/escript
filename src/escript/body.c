#include "oop.h"
#include "escript.h"

static void build(void * _self, void * _source) {
    struct Body * self = _self;
    struct Source * source = _source;

    self->operands = new(Stack);

    while (source->hasNextToken(source)) {
        struct Operand * operand = operand_build(_source);
        if (operand == NULL) {
            break;
        }
        self->operands->append(self->operands, operand);
    }
}

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Body * self = _self;
    struct Operand * operand;
    struct Stack * contexts = _contexts;

    struct Hash * context = new(Hash);

    contexts->append(contexts, context);

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand->run(operand, contexts);
#ifdef VERBOSE
        printf("\n");
#endif
    }

#ifdef VERBOSE
    printf("\n");
#endif

    result = context->get(context, "result");

    contexts->pop(contexts);

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Body * self = _self;

    self->build = build;
    self->run = run;

    return self;
}


static const struct Class _Body = {
    sizeof (struct Body),
    constructor, 0, 0, 0
};

const void * Body = &_Body;