#ifndef EC_VAR_H
#define EC_VAR_H

#include "ec.h"

/* Function name macros */
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Free,)
#define EC_VAR_FREE_ONE_FUNCTION_NAME(TYPE) EC_CONCAT(TYPE, _Var_Free_One,)
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _Var,)
#define EC_VAR_COPY_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Copy,)
#define EC_VAR_COPY2_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _Var_Copy2,)

#define EC_UNLOCK_FUNCTION_NAME(TYPE)       EC_CONCAT(TYPE, _Var_Unlock,)

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


#define EC_VAR_FREE_ONE_FUNCTION_PROTOTYPE(TYPE)    \
void                                                \
EC_VAR_FREE_ONE_FUNCTION_NAME(TYPE)                 \
(                                                   \
    void* var                                       \
);


#define EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)  \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)               \
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
    TYPE* var                                   \
);


#define EC_VAR_COPY2_FUNCTION_PROTOTYPE(TYPE)   \
TYPE*                                           \
EC_VAR_COPY2_FUNCTION_NAME(TYPE)                \
(                                               \
    TYPE* var_copy,                             \
    TYPE* var                                   \
);


#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_FREE_ONE_FUNCTION_PROTOTYPE(TYPE)    \
    EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)          \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_COPY2_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_VAR_FREE_ONE_FUNCTION(TYPE)          \
void                                            \
EC_VAR_FREE_ONE_FUNCTION_NAME(TYPE)             \
(                                               \
    void* var                                   \
)                                               \
{                                               \
    TYPE* v = (TYPE*) var;                      \
    free (v);                                   \
    v = NULL;                                   \
}


#define EC_VAR_FREE_FUNCTION(TYPE)              \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void* var                                   \
)                                               \
{                                               \
    TYPE* v = (TYPE*) var;                      \
    EC_Memory_Var_Free (v->ec_memory_ref);      \
    v->ec_memory_ref = NULL;                    \
    free (v);                                   \
    v = NULL;                                   \
}


#define EC_UNLOCK_FUNCTION(TYPE)                \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void* var                                   \
)                                               \
{                                               \
    TYPE* v = (TYPE*) var;                      \
    v->ec_memory_ref->lock = EC_UNLOCK;         \
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
        ec_memory_new->Free_Func = EC_VAR_FREE_ONE_FUNCTION_NAME(TYPE);       /**** this works */\
        ec_memory_new->Free_Var_Func = EC_VAR_FREE_ONE_FUNCTION_NAME(TYPE);   /**** this not work */ \
        var->ec_memory_ref = ec_memory_new;                 \
        var->lock = EC_LOCK;                                \
    }                                                       \
                                                            \
    return var;                                             \
}


// Copy variable var to var_copy
#define EC_VAR_COPY_FUNCTION(TYPE)                          \
TYPE*                                                       \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                             \
(                                                           \
    TYPE* var                                               \
)                                                           \
{                                                           \
    TYPE* var_copy = EC_VAR_NEW_FUNCTION_NAME(TYPE)();      \
    memcpy (var_copy, var, sizeof(TYPE));                   \
    return var_copy;                                        \
}


#define EC_VAR_COPY2_FUNCTION(TYPE)                         \
TYPE*                                                       \
EC_VAR_COPY2_FUNCTION_NAME(TYPE)                            \
(                                                           \
    TYPE* var_copy,                                         \
    TYPE* var                                               \
)                                                           \
{                                                           \
    *var_copy = *var;                                       \
}


#define EC_VAR_FUNCTIONS(TYPE)      \
    EC_VAR_FREE_FUNCTION(TYPE)      \
    EC_VAR_FREE_ONE_FUNCTION(TYPE)  \
    EC_UNLOCK_FUNCTION(TYPE)        \
    EC_VAR_NEW_FUNCTION(TYPE)       \
    EC_VAR_COPY_FUNCTION(TYPE)      \
    EC_VAR_COPY2_FUNCTION(TYPE)

#endif // EC_VAR_H
