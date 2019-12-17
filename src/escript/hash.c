#include "escript.h"

static char * get_front_key(char * key) {
    char * result = NULL;

    int i;
    for (i = 0; i < strlen(key); i++) {
        if (key[i] == '.') {
            result = calloc(sizeof (char), i + 1);
            memcpy(result, key, i);
            result[i] = 0;
            break;
        }
    }

    if (result == NULL) {
        result = key;
    }

    return result;
}

static void set(void * _self, char * key, void * element) {
#ifdef VERBOSE
    printf("set_hash_%s ", key);
#endif
    struct Hash * self = _self;
    struct SetValue * child;

    char * front_key = get_front_key(key);
    char * tmp_key;

    int found = 0;
    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, front_key) == 0) {
            if (front_key == key) {
                self->entries->elements[i] = element;
            } else {
                child = self->entries->elements[i];
                if (classOf(child) != SetValue) {
                    fputs("reference is not a set", stderr);
                    exit(-1);
                }
                child->values->set(child->values, key + strlen(front_key) + 1, element);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        self->keys->append(self->keys, front_key);
        if (front_key == key) {
            self->entries->append(self->entries, element);
        } else {
            child = new(SetValue, new(Hash));
            child->values->set(child->values, key + strlen(front_key) + 1, element);
            self->entries->append(self->entries, child);
        }
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
    struct SetValue * child;

    char * front_key = get_front_key(key);
    char * tmp_key;
    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, front_key) == 0) {
            if (front_key == key) {
                result = 1;
            } else {
                child = self->entries->elements[i];
                if (classOf(child) != SetValue) {
                    fputs("reference is not a set", stderr);
                    exit(-1);
                }
                result = child->values->contains(child->values, key + strlen(front_key) + 1);
            }
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
    struct SetValue * child;

    char * front_key = get_front_key(key);
    char * tmp_key;

    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, front_key) == 0) {
            if (front_key == key) {
                result = self->entries->get(self->entries, i);
            } else {
                child = self->entries->elements[i];
                if (classOf(child) != SetValue) {
                    fputs("reference is not a set", stderr);
                    exit(-1);
                }
                result = child->values->get(child->values, key + strlen(front_key) + 1);
            }
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
    struct SetValue * child;

    char * front_key = get_front_key(key);
    char * tmp_key;

    int i;
    for (i = 0; i < self->keys->size; i++) {
        tmp_key = self->keys->get(self->keys, i);
        if (strcmp(tmp_key, key) == 0) {
            if (front_key == front_key) {
                result = self->entries->get(self->entries, i);
                self->keys->elements[i] = self->keys->elements[0];
            } else {
                child = self->entries->elements[i];
                if (classOf(child) != SetValue) {
                    fputs("reference is not a set", stderr);
                    exit(-1);
                }
                result = child->values->pop(child->values, key + strlen(front_key) + 1);
            }
            break;
        }
    }

    return result;
}

static void * constructor(void * _self, va_list * params) {
    struct Hash * self = _self;

    self->size = 0;
    self->keys = new(Stack);
    self->entries = new(Stack);

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