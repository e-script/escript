#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Expression * self = _self;

    struct Operand * operand;
    char * operator = NULL;

    void * operand_result;

#ifdef VERBOSE
    printf("expression(");
#endif

    int i;
    for (i = self->operands->size - 1; i >= 0; i--) {
        operand = self->operands->get(self->operands, i);
        if (operator != NULL) {
            if (strcmp(operator, "=") == 0) {
                /*result not change*/
                assign(operand, operator, result, _contexts);
            } else {
                operand_result = operand->run(operand, _contexts);
                result = operate(operand_result, operator, result);
            }
        } else {
            operand_result = operand->run(operand, _contexts);
            result = operand_result;
        }
        if (i > 0) {
            operator = self->operators->get(self->operators, i - 1);
#ifdef VERBOSE
            printf("operator_%s ", operator);
#endif
        } else {
            operator = NULL;
        }
    }

#ifdef VERBOSE
    printf(") ");
#endif

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Expression * self = _self;

    self->operands = va_arg(*params, struct Array *);
    self->operators = va_arg(*params, struct Array *);
    self->parent.run = run;

    return self;
}

static const struct Class _Expression = {
    sizeof (struct Expression),
    constructor, 0, 0, 0
};
const void * Expression = &_Expression;