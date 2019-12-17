#include "escript.h"

void * set_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Stack * operands = new(Stack);

    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    while (hasNextToken()) {
        if (nextTokenIs("}")) {
            break;
        }
        operand = operand_build(_source);
        if (operand == NULL) {
            fputs("operand is expected", stderr);
            exit(-1);
        }
        operands->append(operands, operand);
    }

    result = new(Set, operands);

    return result;
}

static void * array_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Stack * operands = new(Stack);

    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    while (hasNextToken()) {
        if (nextTokenIs("]")) {
            break;
        }
        operand = operand_build(_source);
        if (operand == NULL) {
            fputs("operand is expected", stderr);
            exit(-1);
        }
        operands->append(operands, operand);
    }

    result = new(Array, operands);

    return result;
}

static void * invoke_build(void * _source, char * name) {
    void * result = NULL;

    struct Source * source = _source;

    struct Stack * operands = new(Stack);
    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    matchToken("(");

    while (hasNextToken()) {
        if (nextTokenIs(")")) {
            result = new(Invoke, name, operands);
            break;
        }
        operand = operand_build(_source);
        if (operand == NULL) {
            fputs("')' is expected", stderr);
            exit(-1);
        }
        operands->append(operands, operand);
    }

    matchToken(")");

    return result;
}

void * locate_build(void * _source, char * name) {
    void * result = NULL;

    struct Source * source = _source;

    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    matchToken("[");

    operand = operand_build(_source);

    if (operand == NULL) {
        fputs("locate_expression_is_required", stderr);
        exit(-1);
    }

    result = new(Locate, name, operand);

    matchToken("]");

    return result;
}

void * operand_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Stack * operands = new(Stack);
    struct Stack * operators = new(Stack);
    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    int fail = 0;
    char * name;

    while (hasNextToken()) {
        operand = NULL;

        if (nextTokenType() == TOKEN_NUMBER) {
            operand = new(Number, atoi(popNextToken()));
        } else if (nextTokenType() == TOKEN_NAME) {
            name = popNextToken();
            if (hasNextToken() && nextTokenIs("(")) {
                operand = invoke_build(source, name);
            } else if (hasNextToken() && nextTokenIs("[")) {
                operand = locate_build(source, name);
            } else {
                operand = new(Reference, name);
            }
        } else if (nextTokenIs("{")) {
            matchToken("{");
            operand = set_build(source);
            matchToken("}");
        } else if (nextTokenIs("[")) {
            matchToken("[");
            operand = array_build(source);
            matchToken("]");
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