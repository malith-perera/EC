#ifndef EC_VARIABLE_H
#define EC_VARIABLE_H

#include "ec.h"

#define EC_VAR_NEW_FUNCTION_NAME(TYPE)  EC_CONCAT(TYPE,_Var,)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE) EC_CONCAT(TYPE, _Free,)

/* Function prototypes */
#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void* var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
TYPE*                                               \
EC_VAR_NEW_FUNCTION_NAME(TYPE)();


/* Functions */
#define EC_VAR_FREE_FUNCTION(TYPE)      \
void                                    \
EC_VAR_FREE_FUNCTION_NAME(TYPE)         \
(                                       \
    void* var                           \
)                                       \
{                                       \
    TYPE* p = (TYPE*) var;              \
    free (p);                           \
    p = NULL;                           \
}


#define EC_VAR_NEW_FUNCTION(TYPE)                                                   \
TYPE*                                                                               \
EC_VAR_NEW_FUNCTION_NAME(TYPE)()                                                    \
{                                                                                   \
    TYPE* var = (TYPE*) malloc (sizeof(TYPE));                                      \
                                                                                    \
    if (var == NULL)                                                                \
    {                                                                               \
        printf ("Cannot allocate memory to create variable\n");                     \
        return NULL;                                                                \
    }                                                                               \
                                                                                    \
    if (EC_MEMORY)                                                                  \
    {                                                                               \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));            \
                                                                                    \
        if (ec_memory_new == NULL)                                                  \
        {                                                                           \
            printf ("Cannot allocate memory to create ec_memory_new\n");            \
            return NULL;                                                            \
        }                                                                           \
                                                                                    \
        ec_memory_new->type = EC_VAR_TYPE;                                          \
        ec_memory_new->var = var;                                                   \
        ec_memory_new->memory = NULL;                                               \
        ec_memory_new->Free_Func = EC_VAR_FREE_FUNCTION_NAME (TYPE);                \
        ec_memory_new->next = NULL;                                                 \
                                                                                    \
        if (ec_memory != NULL)                                                      \
        {                                                                           \
            ec_memory_new->next = ec_memory;                                        \
            ec_memory = ec_memory_new;                                              \
        }                                                                           \
        else                                                                        \
        {                                                                           \
            ec_memory = ec_memory_new;                                              \
        }                                                                           \
    }                                                                               \
                                                                                    \
    return var;                                                                     \
}


#define EC_VAR_FUNCTIONS(TYPE)  \
    EC_VAR_FREE_FUNCTION(TYPE)  \
    EC_VAR_NEW_FUNCTION(TYPE)


#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)    \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)


#endif // EC_VARIABLE_H