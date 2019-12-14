#include "escript.h"

static void set(void * _self, char * key, void * element) {
#ifdef VERBOSE
    printf("set_hash_%s ", key);
#endif
    struct Hash * self = _self;

    char * tmp_key;

    int found = 0;
    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, key) == 0) {
            self->entries->elements[i] = element;
            found = 1;
        }
    }
    if (!found) {
        self->keys->append(self->keys, key);
        self->entries->append(self->entries, element);
    }
}

/*
 Return 1 if contains
 */
static int contains(void * _self, char * key) {
#ifdef VERBOSE
    printf("contains_hash_%s ", key);
#endif
    int result = 0;

    struct Hash * self = _self;

    char * tmp_key;
    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, key) == 0) {
            result = 1;
            break;
        }
    }
    return result;
}

static void * get(void * _self, char * key) {
#ifdef VERBOSE
    printf("get_hash_%s ", key);
#endif
    void * result = NULL;

    struct Hash * self = _self;

    char * tmp_key;

    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, key) == 0) {
            result = self->entries->get(self->entries, i);
            break;
        }
    }

    return result;
}

static void * pop(void * _self, char * key) {
#ifdef VERBOSE
    printf("pop_hash_%s ", key);
#endif
    void * result = NULL;

    struct Hash * self = _self;

    char * tmp_key;

    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, key) == 0) {
            result = self->entries->get(self->entries, i);
            self->keys->elements[i] = self->keys->elements[0];
            break;
        }
    }

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Hash * self = _self;

    self->size = 0;
    self->keys = new(Array);
    self->entries = new(Array);

    /*init null*/
    self->keys->append(self->keys, "null");
    self->entries->append(self->entries, NULL);

    self->set = set;
    self->contains = contains;
    self->get = get;
    self->pop = pop;

    return self;
}

static const struct Class _Hash = {
    sizeof (struct Hash),
    constructor, 0, 0, 0
};

const void * Hash = &_Hash;