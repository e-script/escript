#include "charaters.h"

int get_char_type(char c) {
    if (c == '\r' || c == '\n' || c == '\t'
            || c == '\f' || c == ' ' || c == ';'
            || c == ',' || c == ':' || c == '?'
            || c == '\\' || c == '#' || c == '@'
            || c == '$') {
        return CHAR_SPACE;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
            || (c == '.')) {
        return CHAR_NAME;
    }
    if (c == '!' || c == '%'
            || c == '^' || c == '&' || c == '*' || c == '-' || c == '+'
            || c == '=' || c == '|' || c == '~'
            || c == '/' || c == '<' || c == '>') {
        return CHAR_OPERATOR;
    }
    if (c == '[' || c == ']' || c == '{' || c == '}'
            || c == '(' || c == ')') {
        return CHAR_BRACKET;
    }
    if (c == '"' || c == '`') {
        return CHAR_QUOTATION;
    }
    if (c == ',') {
        return CHAR_DELIMETER;
    }
    return CHAR_UNKNOWN;
}

static int getCharType2(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return CHAR_LATINO;
    }
    if (c >= '0' && c <= '9') {
        return CHAR_DIGIT;
    }
    return get_char_type(c);
}

int get_token_type(char * token) {
    size_t len = strlen(token);
    if (len > 0) {
        char c = token[0];

        if (getCharType2(c) == CHAR_DIGIT) {
            return TOKEN_NUMBER;
        }
        if (getCharType2(c) == CHAR_LATINO) {
            return TOKEN_NAME;
        }
        if (getCharType2(c) == CHAR_OPERATOR) {
            return TOKEN_OPERATOR;
        }
        if (getCharType2(c) == CHAR_BRACKET) {
            return TOKEN_BRACKET;
        }
        if (getCharType2(c) == CHAR_QUOTATION) {
            return TOKEN_QUOTATION;
        }
        if (getCharType2(c) == CHAR_DELIMETER) {
            return TOKEN_DELIMETER;
        }
        if (c == '\'') {
            return TOKEN_STRING;
        }
    }
    return TOKEN_UNKNOWN;
}