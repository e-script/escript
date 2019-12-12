#include "escript.h"

static int append(void * _self, void * element) {
    int result = -1;

    struct Array * self = _self;
    void ** tmp;

    self->elements[self->size] = element;
    self->size += 1;

    if (self->size == self->buffer_size) {
        self->buffer_size *= 2;
        tmp = self->elements;
        self->elements = calloc(sizeof (void *), self->buffer_size);
        if (self->elements) {
            memcpy(self->elements, tmp, sizeof (void *) * self->size);
        }
        if (!self->elements) {
            self->elements = tmp;
            self->buffer_size /= 2;
            self->size -= 1;
            self->elements[self->size] = 0;
        }
    }

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Array * self = _self;

    self->size = 0;
    self->buffer_size = 1;
    self->elements = calloc(sizeof (void *), self->buffer_size);

    self->append = append;

    return self;
}

static const struct Class _Array = {
    sizeof (struct Array),
    constructor, 0, 0, 0
};

const void * Array = &_Array;