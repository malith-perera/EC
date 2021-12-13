#ifndef EC_VAR_H
#define EC_VAR_H

#include "ec.h"

/* Function name macros */
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Free,)
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _Var,)
#define EC_VAR_COPY_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Copy,)

#define EC_VAR_UNLOCK_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _Unlock,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h

#define EC_VAR_STRUCT(TYPE)                 EC_CONCAT(TYPE, Var,)

#ifndef EC_VAR
#define EC_VAR(TYPE, VAR)                               \
typedef struct TYPE {                                   \
    VAR                                                 \
    EC_MEMORY_REF                                       \
} TYPE;                                                 \
                                                        \
typedef TYPE EC_VAR_STRUCT(TYPE);
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


#define EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)    \
TYPE*                                           \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                 \
(                                               \
    TYPE* a                                     \
);


#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)


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


#define EC_VAR_CREATE(TYPE)                                 \
    TYPE* var = (TYPE*) malloc (sizeof(TYPE));              \
                                                            \
    if (var == NULL)                                        \
    {                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);            \
        return NULL;                                        \
    }


#define EC_VAR_NEW_FUNCTION(TYPE)                           \
TYPE*                                                       \
EC_VAR_NEW_FUNCTION_NAME(TYPE)()                            \
{                                                           \
    EC_VAR_CREATE(TYPE)                                     /*TYPE* var is defined in this macro*/ \
                                                            \
    if (EC_MEMORY)                                          \
    {                                                       \
        EC_MEMORY_CREATE(TYPE, EC_VAR_TYPE)                 /* ec_memory_new is defined in this macro in ec_memory.h */ \
        var->ec_memory_ref = ec_memory_new;                 \
        var->lock = EC_LOCK;                                \
    }                                                       \
                                                            \
    return var;                                             \
}


// Copy variable b to a
#define EC_VAR_COPY_FUNCTION(TYPE)                          \
TYPE*                                                       \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                             \
(                                                           \
    TYPE* var                                               \
)                                                           \
{                                                           \
    TYPE* new_var = EC_VAR_NEW_FUNCTION_NAME(TYPE)();       \
    *new_var = *var;                                        \
                                                            \
    return new_var;                                         \
}


#define EC_VAR_FUNCTIONS(TYPE)  \
    EC_VAR_FREE_FUNCTION(TYPE)  \
    EC_VAR_NEW_FUNCTION(TYPE)   \
    EC_VAR_COPY_FUNCTION(TYPE)

#endif // EC_VAR_H
