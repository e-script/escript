#include "oop.h"
#include "escript.h"

static void build(void * _self, void * _source) {
    struct Body * self = _self;
    struct Source * source = _source;

    self->operands = new(Array);

    while (source->hasNextToken(source)) {
        struct Operand * operand = operand_build(_source);
        if (operand == NULL) {
            break;
        }
        self->operands->append(self->operands, operand);
    }
}

static void * run(void * _self, void * _context) {
    void * result = NULL;

    void * operand_result;
    struct Reference * reference_result;

    struct Body * self = _self;
    struct Operand * operand;
    struct Hash * context = _context;
    struct Array * allocated_reference = new(Array);

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand_result = operand->run(operand, _context);
        if (operand_result != NULL && classOf(operand_result) == Reference) {
            reference_result = operand_result;
            if (reference_result->first) {
                allocated_reference->append(allocated_reference, reference_result);
            }
            if (strcmp(reference_result->name, "result") == 0) {
                result = reference_result->parent.run(reference_result, _context);
            }
        }
#ifdef VERBOSE
        printf("\n");
#endif
    }

    /*deallocate body variable*/
    for (i = 0; i < allocated_reference->size; i++) {
        reference_result = allocated_reference->get(allocated_reference, i);
        context->pop(context, reference_result->name);
    }
#ifdef VERBOSE
    printf("\n");
#endif

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