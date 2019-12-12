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
                self->offset = 0;
                result = 0;
            }
        }
    }
    fclose(file);

    return result;
}

/*
 Return 1 if success
 */
static int hasNextToken(void * _self) {
    int result = 0;
    
    struct Source * self = _self;

    size_t newOffset = self->offset;
    while (newOffset < self->length && get_char_type(self->value[newOffset]) == CHAR_SPACE) {
        newOffset += 1;
    }
    if (newOffset < self->length) {
        result = 1;
    }

    return result;
}

static char * getNextToken(void * _self) {
    char * result;

    struct Source * self = _self;

    /* skip spaces */
    size_t startOffset = self->offset;
    while (startOffset < self->length && get_char_type(self->value[startOffset]) == CHAR_SPACE) {
        startOffset += 1;
    }
    /* check end of source */
    if (startOffset == self->length) {
        return NULL;
    }

    /* detect token */
    size_t finishOffset = startOffset + 1;
    while (finishOffset < self->length
            && get_char_type(self->value[finishOffset]) == get_char_type(self->value[startOffset])) {
        finishOffset += 1;
    }

    /* copy token */
    result = (char *) malloc(finishOffset - startOffset + 1);
    memcpy(result, &self->value[startOffset], finishOffset - startOffset);
    result[finishOffset - startOffset + 1] = 0;

    return result;
}

static char * popNextToken(void * _self) {
    char * result;

    struct Source * self = _self;

    /* skip spaces */
    while (self->offset < self->length
            && get_char_type(self->value[self->offset]) == CHAR_SPACE) {
        self->offset += 1;
    }
    /* check end of source */
    if (self->offset == self->length) {
        return NULL;
    }

    /* detect token */
    size_t newOffset = self->offset + 1;
    while (newOffset < self->length
            && get_char_type(self->value[newOffset]) == get_char_type(self->value[self->offset])) {
        newOffset += 1;
    }

    /* copy token */
    result = (char *) malloc(newOffset - self->offset + 1);
    memcpy(result, &self->value[self->offset], newOffset - self->offset);
    result[newOffset - self->offset + 1] = 0;

    /* move offset */
    self->offset = newOffset;

    return result;
}

static void matchToken(void * _self, char * token) {
    struct Source * self = _self;

    if (strcmp(token, self->getNextToken(_self)) != 0) {
        fputs("%s is required", stderr);
        return;
    }
    self->popNextToken(_self);
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
    self->hasNextToken = hasNextToken;
    self->getNextToken = getNextToken;
    self->popNextToken = popNextToken;
    self->matchToken = matchToken;
    self->build = build;

    return self;
}

static const struct Class _Source = {
    sizeof (struct Source),
    constructor,
    0, 0, 0
};

const void * Source = &_Source;