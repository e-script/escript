#include "escript.h"

static void * length(void * _self, void * _contexts) {
    void * result = NULL;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct ArrayValue * params;
    void * param;
    struct StringValue * string_value;

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
        param = params->values->get(params->values, 0);
        if (classOf(param) != StringValue) {
            fputs("argument must be a string", stderr);
            exit(-1);
        }
        string_value = param;
        context = new(Hash);
        context->set(context, "result", new(NumberValue, strlen(string_value->value)));
        result = new(SetValue, context);
    }

    return result;
}

static void * fromNumber(void * _self, void * _contexts) {
    void * result = NULL;

    struct Stack * contexts = _contexts;
    struct Hash * context;
    struct ArrayValue * params;
    void * param;
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
        param = params->values->get(params->values, 0);
        if (classOf(param) != NumberValue) {
            fputs("argument must be a number", stderr);
            exit(-1);
        }
        number_value = param;
        context = new(Hash);
        char * string = calloc(sizeof (char), 12); /*12 is maximum length of int*/
        snprintf(string, 12, "%d", number_value->value);
        context->set(context, "result", new(StringValue, string));
        result = new(SetValue, context);
    }

    return result;
}

void * init_string() {
    struct SetValue * result = NULL;

    struct Hash * hash = new(Hash);
    struct Set * tmp = new(Set, new(Stack));
    
    struct Function * function = new(Function, tmp, tmp);
    function->parent.run = length;
    hash->set(hash, "length", function);
    
    
    function = new(Function, tmp, tmp);
    function->parent.run = fromNumber;
    hash->set(hash, "fromNumber", function);

    result = new(SetValue, hash);

    return result;
}