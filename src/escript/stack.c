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

static void * get(void * _self, size_t index) {
    void * result = NULL;

    struct Array * self = _self;
    if (index >= 0 && index < self->size) {
        result = self->elements[index];
    }

    return result;
}

static void * pop(void * _self) {
    struct Array * self = _self;

    void * result = get(_self, self->size - 1);

    if (result != NULL) {
        self->elements[self->size - 1] = NULL;
        self->size -= 1;
    }

    return result;
}

static void reverse(void * _self) {
    struct Array * self = _self;
    
    void * tmp;

    int i;
    for (i = 0; i < self->size / 2; i++) {
        tmp = self->elements[i];
        self->elements[i] = self->elements[self->size - 1 - i];
        self->elements[self->size - 1 - i] = tmp;
    }
}

static void * constructor(void * _self, va_list * params) {
    struct Array * self = _self;

    self->size = 0;
    self->buffer_size = 1;
    self->elements = calloc(sizeof (void *), self->buffer_size);

    self->append = append;
    self->get = get;
    self->pop = pop;
    self->reverse = reverse;

    return self;
}

static const struct Class _Array = {
    sizeof (struct Array),
    constructor, 0, 0, 0
};

const void * Array = &_Array;