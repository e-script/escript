/* 
 * File:   class.c
 * Author: chien
 *
 * Created on December 12, 2019, 10:05 AM
 */

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>

#include "oop.h"

void * new(const void * _class, ...) {
    const struct Class * class = _class;
    void * result = calloc(1, class->size);
    assert(result);
    *(const struct Class **) result = class;

    if (class->constructor) {
        va_list params;
        va_start(params, _class);
        result = class->constructor(result, & params);
        va_end(params);
    }

    return result;
}

void delete(void * self) {
    const struct Class ** cp = self;
    if (self && *cp && (* cp) -> destructor) {
        self = (* cp) -> destructor(self);
        free(self);
    }
}

int differ(const void * self, const void * other) {
    const struct Class * const * cp = self;
    assert(self && *cp && (* cp) -> differ);
    return (* cp) -> differ(self, other);
}

void * clone(const void * self) {
    const struct Class * const * cp = self;
    assert(self && *cp && (* cp) -> clone);
    return (* cp) -> clone(self);
}

size_t sizeOf(const void * self) {
    const struct Class * const * cp = self;
    assert(self && *cp);
    return (* cp) -> size;
}

void * classOf(void * self) {
    return * (struct Class **) self;
}