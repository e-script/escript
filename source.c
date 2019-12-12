#include "escript.h"

/*
 return 0 if file exists
 */
static int checkFileExists(char * filePath) {
    struct stat buffer;
    return stat(filePath, &buffer);
}

/*
 * return 0 if read success
 */
static int read(void * _self) {
    int result = -1;

    struct Source * self = _self;

    FILE * file;
    size_t count;

    /* open file */
    file = fopen(self->filePath, "r");

    if (file == NULL) {
        fputs("File error", stderr);
    } else {
        /* get file size */
        fseek(file, 0, SEEK_END);
        self->length = ftell(file);
        fseek(file, 0, SEEK_SET);

        /* allocate result memory */
        self->value = (char *) malloc(sizeof (char) * self->length + 1);
        if (self->value == NULL) {
            fputs("Memory error", stderr);
        } else {
            /* read file to memory */
            count = fread(self->value, 1, self->length, file);
            if (count != self->length) {
                fputs("Reading error", stderr);
            } else {
                self->value[self->length] = 0;
                result = 0;
            }
        }
    }
    fclose(file);

    return result;
}

static void build(void * _self) {
    struct Source * self = _self;

    self->body = new(Body);
    self->body->build(self->body, self);
}

static void * constructor(void * _self, va_list * params) {
    struct Source * self = _self;

    self->filePath = va_arg(*params, char *);

    self->checkFileExists = checkFileExists;
    self->read = read;
    self->build = build;

    return self;
}

static const struct Class _Source = {
    sizeof (struct Source),
    constructor,
    0, 0, 0
};

const void * Source = &_Source;