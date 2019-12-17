/* 
 * File:   charaters.h
 * Author: chien
 *
 * Created on December 12, 2019, 7:31 PM
 */

#ifndef CHARATERS_H
#define CHARATERS_H

#include <stddef.h>
#include <string.h>

#define CHAR_SPACE      0
#define CHAR_LATINO     1
#define CHAR_DIGIT      2
#define CHAR_NAME       3
#define CHAR_OPERATOR   4
#define CHAR_BRACKET    5
#define CHAR_QUOTATION  6
#define CHAR_DELIMETER  7
#define CHAR_UNKNOWN    -1

#define TOKEN_NAME      0
#define TOKEN_NUMBER    1
#define TOKEN_STRING    2
#define TOKEN_OPERATOR  3
#define TOKEN_BRACKET   4
#define TOKEN_QUOTATION 5
#define TOKEN_DELIMETER 6
#define TOKEN_UNKNOWN   -1

int get_char_type(char c);

int get_token_type(char * token);

#endif /* CHARATERS_H */

