#include "escript.h"

static void * Number_run(void * _self) {
    struct Number * self = _self;

    printf("number: %d ", self->value);

    return NULL;
}

static void * Number_constructor(void * _self, va_list * params) {
    struct Number * self = _self;

    self->value = va_arg(*params, int);
    self->operand.run = Number_run;

    return self;
}

static const struct Class _Number = {
    sizeof (struct Number),
    Number_constructor, 0, 0, 0
};
const void * Number = &_Number;

static void * Reference_run(void * _self) {
    struct Reference * self = _self;

    printf("reference: %s ", self->name);

    return NULL;
}

static void *Reference_constructor(void * _self, va_list * params) {
    struct Reference * self = _self;

    self->name = va_arg(*params, char *);
    self->operand.run = Reference_run;

    return self;
}

static const struct Class _Reference = {
    sizeof (struct Reference),
    Reference_constructor, 0, 0, 0
};
const void * Reference = &_Reference;

static void * Expression_run(void * _self) {
    struct Expression * self = _self;

    struct Operand * operand;
    char * operator;

    printf("expression: ");

    int i;
    for (i = 0; i < self->operands->size; i++) {
        operand = self->operands->get(self->operands, i);
        operand->run(operand);
        if (i < self->operators->size) {
            operator = self->operators->get(self->operators, i);
            printf("operator: %s ", operator);
        }
    }

    return NULL;
}

static void * Expression_constructor(void * _self, va_list * params) {
    struct Expression * self = _self;

    self->operands = va_arg(*params, struct Array *);
    self->operators = va_arg(*params, struct Array *);
    self->operand.run = Expression_run;

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

        if (!hasNextToken() || nextTokenType() != TOKEN_OPERATOR) {
            break;
        }

        operators->append(operators, popNextToken());
    }

    if (!fail) {
        result = new(Expression, operands, operators);
    }

    return result;
}