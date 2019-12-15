#include "escript.h"

static void * set_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Array * operands = new(Array);

    void * operand;

#define hasNextToken()(source->hasNextToken(source))
#define popNextToken()(source->popNextToken(source))
#define nextTokenType()(get_token_type(source->getNextToken(source)))
#define nextTokenIs(token)(strcmp(source->getNextToken(source), token) == 0)
#define matchToken(token)(source->matchToken(source, token))

    matchToken("{");

    while (hasNextToken()) {
        if (nextTokenIs("}")) {
            result = new(Set, operands);
            break;
        }
        operand = operand_build(_source);
        if (operand == NULL) {
            fputs("operand is expected", stderr);
            exit(-1);
        }
        operands->append(operands, operand);
        if (nextTokenIs(",")) {
            popNextToken();
        } else if (!nextTokenIs("}")) {
            fputs("'}' is expected", stderr);
            exit(-1);
        }
    }

    matchToken("}");

    return result;
}

static void * invoke_build(void * _source, char * name) {
    void * result = NULL;

    struct Source * source = _source;

    struct Array * operands = new(Array);
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
        if (nextTokenIs(",")) {
            popNextToken();
        } else if (!nextTokenIs(")")) {
            fputs("')' is expected", stderr);
            exit(-1);
        }
    }

    matchToken(")");

    return result;
}

void * operand_build(void * _source) {
    void * result = NULL;

    struct Source * source = _source;

    struct Array * operands = new(Array);
    struct Array * operators = new(Array);
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
            } else {
                operand = new(Reference, name);
            }
        } else if (nextTokenIs("{")) {
            operand = set_build(source);
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