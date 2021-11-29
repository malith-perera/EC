#include <stdio.h>

#include "ec_type.h"

/* Related with ECType in ec_type.h
 * If you change anything here change it too */
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


char*
EC_Type_Get_Name (ECType type)
{
    return ec_type_names[type];
}
