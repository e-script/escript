#ifndef OOP_H
#define OOP_H

#include <stddef.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void * (* constructor) (void * self, va_list * params);
    void * (* destructor) (void * self);
    void * (* clone) (const void * self);
    int (* differ) (const void * self, const void * other);
};

void * new(const void * _class, ...);
void delete(void * self);
int differ(const void * self, const void * other);
void * clone(const void * self);
size_t sizeOf(const void * self);
void * classOf(void * self);

#endif /* OOP_H */

