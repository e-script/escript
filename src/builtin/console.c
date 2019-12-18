#include "escript.h"

static void * write(void * _self, void * _contexts) {
    void * result = NULL;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct ArrayValue * params;
    void * param;
    struct StringValue * string_value;
    struct NumberValue * number_value;

    /*get params*/
    int i;
    params = NULL;
    for (i = contexts->size - 1; i >= 0; i--) {
        context = contexts->get(contexts, i);
        params = context->get(context, "params");
        if (params != NULL) {
            break;
        }
    }

    if (params != NULL) {

        for (i = 0; i < params->values->size; i++) {
            param = params->values->get(params->values, i);
            if (classOf(param) == StringValue) {
                string_value = param;
                printf("%s", string_value->value);
            } else if (classOf(param) == NumberValue) {
                number_value = param;
                printf("%d", number_value->value);
            } else {
                fputs("invalid_argument_type", stderr);
                exit(-1);
            }
        }
    }

    result = new(SetValue, new(Hash));

    return result;
}

static void * writeln(void * _self, void * _contexts) {
    void * result = write(_self, _contexts);
    printf("\n");
    return result;
}

void * init_stdio() {
    struct SetValue * result = NULL;

    struct Hash * hash = new(Hash);
    struct Set * tmp = new(Set, new(Stack));
    struct Function * function = new(Function, tmp, tmp);

    function->parent.run = write;

    hash->set(hash, "write", function);

    function = new(Function, tmp, tmp);
    function->parent.run = writeln;

    hash->set(hash, "writeln", function);

    result = new(SetValue, hash);

    return result;
}