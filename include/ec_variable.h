#ifndef EC_VARIABLE_H
#define EC_VARIABLE_H

#include "ec.h"

/* Function name macros */
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _Var,)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Free,)
#define EC_VAR_UNLOCK_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _Unlock,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h


#ifndef EC_VAR
#define EC_VAR(TYPE, VAR)                               \
typedef struct TYPE {                                   \
    VAR                                                 \
    EC_MEMORY_REF                                       \
} TYPE;
#endif // EC_VAR

/* Function prototype macros */

#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void* var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
TYPE*                                           \
EC_VAR_NEW_FUNCTION_NAME(TYPE)();



#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_VAR_FREE_FUNCTION(TYPE)      \
void                                    \
EC_VAR_FREE_FUNCTION_NAME(TYPE)         \
(                                       \
    void* var                           \
)                                       \
{                                       \
    TYPE* v = (TYPE*) var;              \
    free (v);                           \
    v = NULL;                           \
}


#define EC_VAR_NEW_FUNCTION(TYPE)                                           \
TYPE*                                                                       \
EC_VAR_NEW_FUNCTION_NAME(TYPE)()                                            \
{                                                                           \
    TYPE* var = (TYPE*) malloc (sizeof(TYPE));                              \
                                                                            \
    if (var == NULL)                                                        \
    {                                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                            \
        return NULL;                                                        \
    }                                                                       \
                                                                            \
    if (EC_MEMORY)                                                          \
    {                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));    \
                                                                            \
        if (ec_memory_new == NULL)                                          \
        {                                                                   \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                        \
            return NULL;                                                    \
        }                                                                   \
                                                                            \
        ec_memory_new->type = EC_VAR_TYPE;                                  \
        ec_memory_new->var = var;                                           \
        ec_memory_new->lock = EC_LOCK;                                      \
        ec_memory_new->Free_Func = EC_VAR_FREE_FUNCTION_NAME (TYPE);        \
        ec_memory_new->next = NULL;                                         \
                                                                            \
        EC_Memory_Append (ec_memory_new);                                   \
                                                                            \
        var->ec_memory_ref = ec_memory_new;                                       \
        var->lock = EC_LOCK;                                                \
    }                                                                       \
                                                                            \
    return var;                                                             \
}


#define EC_VAR_FUNCTIONS(TYPE)  \
    EC_VAR_FREE_FUNCTION(TYPE)  \
    EC_VAR_NEW_FUNCTION(TYPE)

#endif // EC_VARIABLE_H
