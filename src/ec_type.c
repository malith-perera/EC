#include <stdio.h>

#include "ec_type.h"

char* ec_type_names[] = {
    "EC_VAR",
    "EC_ARRAY",
    "EC_LIST",
    "EC_LIST_VAR",
    "EC_QUEUE",
    "EC_QUEUE_VAR",
    "EC_STACK",
    "EC_STACK_VAR"
};


void
EC_Type_Get(ECType type)
{
    printf("%s", ec_type_names[type]);
}
