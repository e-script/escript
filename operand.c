#include "escript.h"

static void * Number_constructor(void * _self, va_list * params) {
    struct Number * self = _self;

    self->value = va_arg(*params, int);

    return self;
}

static const struct Class _Number = {
    sizeof (struct Number),
    Number_constructor, 0, 0, 0
};
const void * Number = &_Number;

static void *Reference_constructor(void * _self, va_list * params) {
    struct Reference * self = _self;

    self->name = va_arg(*params, char *);

    return self;
}

static const struct Class _Reference = {
    sizeof (struct Reference),
    Reference_constructor, 0, 0, 0
};
const void * Reference = &_Reference;

static void * Expression_constructor(void * _self, va_list * params) {
    struct Expression * self = _self;

    self->operands = va_arg(*params, struct Array *);
    self->operators = va_arg(*params, struct Array *);

    return self;
}

static const struct Class _Expression = {
    sizeof (struct Expression),
    Expression_constructor, 0, 0, 0
};
const void * Expression = &_Expression;

void * operand_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Array * operands = new(Array);
    struct Array * operators = new(Array);
    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))

    int fail = 0;

    while (hasNextToken()) {
        operand = NULL;

        if (nextTokenType() == TOKEN_NUMBER) {
            operand = new(Number, atoi(popNextToken()));
        } else if (nextTokenType() == TOKEN_NAME) {
            operand = new(Reference, popNextToken());
        }

        if (operand == NULL) {
            fail = 1;
            break;
        }

        operands->append(operands, operand);

        if (!hasNextToken()) {
            break;
        }

        if (nextTokenType() != TOKEN_OPERATOR) {
            fail = 1;
            break;
        }

        operators->append(operators, popNextToken());
    }

    if (!fail) {
        result = new(Expression, operands, operators);
    }

    return result;
}