#include "escript.h"

static void * run(void * _self, void * _contexts) {
    void * result = NULL;

    struct String * self = _self;

    result = new(StringValue, self->value);

    return result;
}

static void * fix_string(char * string) {
    int len = strlen(string);
    char * result = calloc(sizeof (char), len - 1);

    int i;
    int size = 0;
    int escape = 0;
    for (i = 1; i < len - 1; i++) {
        if (string[i] == '\\' && !escape) {
            escape = 1;
        } else {
            if (escape) {
                if (string[i] == 'r') {
                    result[size] = '\r';
                } else if (string[i] == 'n') {
                    result[size] = '\n';
                } else if (string[i] == 't') {
                    result[size] = '\t';
                } else if (string[i] == 'f') {
                    result[size] = '\f';
                } else if (string[i] == '\'') {
                    result[size] = '\'';
                } else if (string[i] == '\\') {
                    result[size] = '\\';
                } else {
                    fputs("invalid escape", stderr);
                    exit(-1);
                }
            } else {
                result[size] = string[i];
            }
            size += 1;
            escape = 0;
        }
    }

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct String * self = _self;

    self->value = fix_string(va_arg(*params, char *));
    self->parent.run = run;

    return self;
}

static const struct Class _String = {
    sizeof (struct String),
    constructor, 0, 0, 0
};

const void * String = &_String;