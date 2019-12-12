#include "escript.h"

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

    while (hasNextToken()) {
        if (nextTokenIs(")")) {
            result = new(Invoke, name, operands);
            break;
        }
        operand = operand_build(_source);
        if (operand == NULL) {
            fputs("')' is expected", stderr);
            break;
        }
        operands->append(operands, operand);
        if (nextTokenIs(",")) {
            popNextToken();
        } else if (!nextTokenIs(")")) {
            fputs("')' is expected2", stderr);
            break;
        }
    }

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
                matchToken("(");
                operand = invoke_build(source, name);
                matchToken(")");
            } else {
                operand = new(Reference, name);
            }
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