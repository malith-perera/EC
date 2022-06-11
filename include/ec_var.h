#ifndef EC_VAR_H
#define EC_VAR_H

#include "ec.h"

/* Function name macros */

/* EC_VAR_FREE_ALL_FUNCTION deletes only it's variable.
 * EC_VAR_FREE_FUNCTION deletes total variable and memory */
#define EC_VAR_FREE_ALL_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Free_All,)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Free,)
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Var,)
#define EC_VAR_COPY_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Copy,)
#define EC_VAR_COPY2_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Var_Copy2,)
#define EC_UNLOCK_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Var_Unlock,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h

#define EC_VAR_STRUCT(TYPE)                 EC_CONCAT(TYPE, Var,)

#ifndef EC_VAR
#define EC_VAR(TYPE, VAR)                           /* VAR should define and pass by user as a macro */\
typedef struct TYPE {                               \
    VAR                                             \
    EC_MEMORY_REF                                   \
} TYPE;                                             \
                                                    \
typedef TYPE EC_VAR_STRUCT(TYPE);
#endif // EC_VAR


/* Function prototype macros */
#define EC_VAR_FREE_ALL_FUNCTION_PROTOTYPE(TYPE)    \
void                                                \
EC_VAR_FREE_ALL_FUNCTION_NAME(TYPE)                 \
(                                                   \
    void *var                                       \
);


#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
void                                                \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                     \
(                                                   \
    void *var                                       \
);


#define EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)      \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void *var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
TYPE*                                           \
EC_VAR_NEW_FUNCTION_NAME(TYPE)();


#define EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)    \
TYPE*                                           \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                 \
(                                               \
    TYPE *var                                   \
);


#define EC_VAR_COPY2_FUNCTION_PROTOTYPE(TYPE)   \
TYPE*                                           \
EC_VAR_COPY2_FUNCTION_NAME(TYPE)                \
(                                               \
    TYPE *var_copy,                             \
    TYPE *var                                   \
);


#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_FREE_ALL_FUNCTION_PROTOTYPE(TYPE)    \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)          \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_COPY2_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_VAR_FREE_FUNCTION(TYPE)              \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE *) var;                     \
    if (v != NULL)                              \
    {                                           \
        v->ec_memory_ref_back->lock = EC_UNLOCK;\
        v->ec_memory_ref_back->var = NULL;      \
        free (v);                               \
        v = NULL;                               \
    }                                           \
}


/* we do not use this function */
#define EC_VAR_FREE_ALL_FUNCTION(TYPE)          \
void                                            \
EC_VAR_FREE_ALL_FUNCTION_NAME(TYPE)             \
(                                               \
    void *ec_mem                                \
)                                               \
{                                               \
    ECMemory *mem = (ECMemory *) ec_mem;        \
    if (mem != NULL)                            \
    {                                           \
        if (mem->var != NULL)                   \
        {                                       \
            free (mem->var);                    \
        }                                       \
        EC_Memory_Var_Free (mem);               \
    }                                           \
}


#define EC_UNLOCK_FUNCTION(TYPE)                \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE*) var;                      \
    v->ec_memory_ref_back->lock = EC_UNLOCK;    \
}


/* Create memory for any variable type ex: var, arry, list, list var */
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
    EC_VAR_CREATE(TYPE)                                     /* TYPE *var is defined in this macro */\
                                                            \
    if (EC_MEMORY)                                          \
    {                                                       \
        EC_MEMORY_CREATE(TYPE, EC_VAR_TYPE)                 /* ec_memory_new is defined in this macro in ec_memory.h */\
        ec_memory_new->Free_Func = EC_VAR_FREE_FUNCTION_NAME(TYPE);    \
        var->ec_memory_ref_back = ec_memory_new;            \
        var->ec_memory_ref_back->lock = EC_LOCK;            \
    }                                                       \
                                                            \
    return var;                                             \
}


// Copy variable var to var_copy
#define EC_VAR_COPY_FUNCTION(TYPE)                          \
TYPE*                                                       \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                             \
(                                                           \
    TYPE *var                                               \
)                                                           \
{                                                           \
    TYPE *var_copy = EC_VAR_NEW_FUNCTION_NAME(TYPE)();      \
    memcpy (var_copy, var, sizeof(TYPE));                   \
    return var_copy;                                        \
}


#define EC_VAR_COPY2_FUNCTION(TYPE)                         \
TYPE*                                                       \
EC_VAR_COPY2_FUNCTION_NAME(TYPE)                            \
(                                                           \
    TYPE *var_copy,                                         \
    TYPE *var                                               \
)                                                           \
{                                                           \
    *var_copy = *var;                                       \
}


#define EC_VAR_FUNCTIONS(TYPE)      \
    EC_VAR_FREE_ALL_FUNCTION(TYPE)  \
    EC_VAR_FREE_FUNCTION(TYPE)      \
    EC_UNLOCK_FUNCTION(TYPE)        \
    EC_VAR_NEW_FUNCTION(TYPE)       \
    EC_VAR_COPY_FUNCTION(TYPE)      \
    EC_VAR_COPY2_FUNCTION(TYPE)

#endif // EC_VAR_H
