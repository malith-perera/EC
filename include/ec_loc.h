#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#ifndef EC_LOC_H
#define EC_LOC_H

#define DEBUG 1

typedef enum {
    EMPTY,
    NONE_EMPTY,
    CODE_LINE,
    FIRST_SLASH,
    SINGLE_LINE,
    MULTI_LINE_IN,
    MULTI_LINE_IN_END,
    MULTI_LINE
} LineType;

#endif // EC_LOC_H
