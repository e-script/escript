#include "oop.h"
#include "escript.h"

static void build(void * _self, void * _source) {
    struct Body * self = _self;
    struct Source * source = _source;
    
    printf("build body\n");
    
    self->operands = new(Array);
}

static void * constructor(void * _self, va_list * params) {
    struct Body * self = _self;

    self->build = build;

    return self;
}


static const struct Class _Body = {
    sizeof (struct Body),
    constructor, 0, 0, 0
};

const void * Body = &_Body;