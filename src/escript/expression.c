#include "escript.h"

void * map(void * _params, void * _body) {
    void * result = NULL;

    if (classOf(_params) != Set) {
        fputs("left operand of mapping operator must be a set", stderr);
        exit(-1);
    }
    if (classOf(_body) != Set) {
        fputs("right operand of mapping operator must be a set", stderr);
        exit(-1);
    }

#ifdef VERBOSE
    printf("function ");
#endif

    result = new(Function, _params, _body);

    return result;
}

void * assign(void * _reference, char * operator, void * _value, void * _contexts) {
    void * result = NULL;

    struct Reference * reference = _reference;
    struct Array * contexts = _contexts;
    if (classOf(_contexts) != Array) {
        fputs("invalid contexts", stderr);
        exit(-1);
    }
    struct Hash * context = contexts->get(contexts, contexts->size - 1);

    if (classOf(_reference) != Reference) {
        fputs("left value of = is not an identifier", stderr);
        exit(-1);
    }

#ifdef VERBOSE
    printf("reference_%s ", reference->name);
#endif

    context->set(context, reference->name, _value);

    result = reference;

    return result;
}

void * multiply(void * _a, char * operator, void * _b) {
    void * result = NULL;

    struct NumberValue * numberValueA, * numberValueB;

    if (classOf(_a) == NumberValue) {
        numberValueA = _a;
        if (classOf(_b) == NumberValue) {
            numberValueB = _b;
            if (strcmp(operator, "*") == 0) {
                result = new(NumberValue, numberValueA->value * numberValueB->value);
            } else if (strcmp(operator, "/") == 0) {
                result = new(NumberValue, numberValueA->value / numberValueB->value);
            } else {
                fputs("invalid operator", stderr);
                exit(-1);
            }
        } else {
            fputs("number expected", stderr);
            exit(-1);
        }
    }


    return result;
}

void * accumulate(void * _a, char * operator, void * _b) {
    void * result = NULL;

    struct NumberValue * numberValueA, * numberValueB;

    if (classOf(_a) == NumberValue) {
        numberValueA = _a;
        if (classOf(_b) == NumberValue) {
            numberValueB = _b;
            if (strcmp(operator, "+") == 0) {
                result = new(NumberValue, numberValueA->value + numberValueB->value);
            } else if (strcmp(operator, "-") == 0) {
                result = new(NumberValue, numberValueA->value - numberValueB->value);
            } else {
                fputs("invalid operator", stderr);
                exit(-1);
            }
        } else {
            fputs("number expected", stderr);
            exit(-1);
        }
    }

    return result;
}

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct Expression * self = _self;

    struct Operand * operand;
    void * function;
    char * operator;
    void * operand_result;
    int i;

    struct Array * firstOperands, * firstOperators,
            * secondOperands, * secondOperators;

    if (self->operands->size == 1 &&
            classOf(self->operands->get(self->operands, 0)) == Reference) {
        /*skip this expression, it's a comment word*/
    } else {

#ifdef VERBOSE
        printf("expression(");
#endif

        /*mapping operator*/
        firstOperands = self->operands;
        firstOperators = self->operators;
        secondOperands = new(Array);
        secondOperators = new(Array);
        secondOperands->append(secondOperands,
                firstOperands->get(firstOperands, firstOperands->size - 1));
        for (i = firstOperators->size - 1; i >= 0; i--) {
            operand = firstOperands->get(firstOperands, i);
            operator = firstOperators->get(firstOperators, i);
            if (strcmp(operator, "->") == 0) {
                function = map(
                        operand,
                        secondOperands->pop(secondOperands)
                        );
                secondOperands->append(secondOperands, function);
            } else {
                secondOperators->append(secondOperators, operator);
                secondOperands->append(secondOperands, operand);
            }
        }

        /*multiplication operator*/
        firstOperands = secondOperands;
        firstOperands->reverse(firstOperands);
        firstOperators = secondOperators;
        firstOperators->reverse(firstOperators);
        secondOperands = new(Array);
        secondOperators = new(Array);
        operand = firstOperands->get(firstOperands, firstOperands->size - 1);
        operand_result = operand->run(operand, _contexts);
        secondOperands->append(secondOperands, operand_result);
        for (i = firstOperators->size - 1; i >= 0; i--) {
            operand = firstOperands->get(firstOperands, i);
            operator = firstOperators->get(firstOperators, i);
            if (strcmp(operator, "=") != 0) {
                operand_result = operand->run(operand, _contexts);
            } else {
                operand_result = operand;
            }
            if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) {
                operand_result = multiply(
                        operand_result,
                        operator,
                        secondOperands->pop(secondOperands)
                        );
                secondOperands->append(secondOperands, operand_result);
#ifdef VERBOSE
                printf("operator_%s ", operator);
#endif
            } else {
                secondOperators->append(secondOperators, operator);
                secondOperands->append(secondOperands, operand_result);
            }
        }

        /*accumulation operator*/
        firstOperands = secondOperands;
        firstOperands->reverse(firstOperands);
        firstOperators = secondOperators;
        firstOperators->reverse(firstOperators);
        secondOperands = new(Array);
        secondOperators = new(Array);
        operand_result = firstOperands->get(firstOperands, firstOperands->size - 1);
        secondOperands->append(secondOperands, operand_result);
        for (i = firstOperators->size - 1; i >= 0; i--) {
            operand_result = firstOperands->get(firstOperands, i);
            operator = firstOperators->get(firstOperators, i);
            if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0) {
                operand_result = accumulate(
                        operand_result,
                        operator,
                        secondOperands->pop(secondOperands)
                        );
                secondOperands->append(secondOperands, operand_result);
#ifdef VERBOSE
                printf("operator_%s ", operator);
#endif
            } else {
                secondOperators->append(secondOperators, operator);
                secondOperands->append(secondOperands, operand_result);
            }
        }

        /*assignment operator*/
        firstOperands = secondOperands;
        firstOperands->reverse(firstOperands);
        firstOperators = secondOperators;
        firstOperators->reverse(firstOperators);
        secondOperands = new(Array);
        secondOperators = new(Array);
        operand_result = firstOperands->get(firstOperands, firstOperands->size - 1);
        secondOperands->append(secondOperands, operand_result);
        for (i = firstOperators->size - 1; i >= 0; i--) {
            operand_result = firstOperands->get(firstOperands, i);
            operator = firstOperators->get(firstOperators, i);
            if (strcmp(operator, "=") == 0) {
                operand_result = assign(
                        operand_result,
                        operator,
                        secondOperands->pop(secondOperands),
                        _contexts
                        );
                secondOperands->append(secondOperands, operand_result);
#ifdef VERBOSE
                printf("operator_%s ", operator);
#endif
            } else {
                fputs("undefined operator", stderr);
                exit(-1);
            }
        }
        result = secondOperands->pop(secondOperands);

#ifdef VERBOSE
        printf(")\n");
#endif
    }


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