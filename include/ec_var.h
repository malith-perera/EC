#ifndef EC_VAR_H
#define EC_VAR_H

#include "ec.h"

/* Function name macros */
#define EC_VAR_FREE_VAR_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Free,)
#define EC_VAR_FREE_FUNC_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _Var_Free_Func,)
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
#define EC_VAR_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)    \
void                                                \
EC_VAR_FREE_VAR_FUNCTION_NAME(TYPE)                 \
(                                                   \
    void *var                                       \
);


#define EC_VAR_FREE_FUNC_FUNCTION_PROTOTYPE(TYPE)   \
void                                                \
EC_VAR_FREE_FUNC_FUNCTION_NAME(TYPE)                \
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
    EC_VAR_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)    \
    EC_VAR_FREE_FUNC_FUNCTION_PROTOTYPE(TYPE)   \
    EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)          \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_COPY2_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_VAR_FREE_FUNC_FUNCTION(TYPE)         \
void                                            \
EC_VAR_FREE_FUNC_FUNCTION_NAME(TYPE)            \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE*) var;                      \
    free (v);                                   \
    v = NULL;                                   \
}


#define EC_VAR_FREE_VAR_FUNCTION(TYPE)          \
void                                            \
EC_VAR_FREE_VAR_FUNCTION_NAME(TYPE)             \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE*) var;                      \
    ECMemory* ec_memory_ref_back = v->ec_memory_ref_back;\
    v->ec_memory_ref_back->Free_Var_Func(v);    \
    EC_Memory_Var_Free (ec_memory_ref_back);    \
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
    EC_VAR_CREATE(TYPE)                                     /*TYPE* var is defined in this macro*/\
                                                            \
    if (EC_MEMORY)                                          \
    {                                                       \
        EC_MEMORY_CREATE(TYPE, EC_VAR_TYPE)                 /* ec_memory_new is defined in this macro in ec_memory.h */\
        ec_memory_new->Free_Var_Func = EC_VAR_FREE_FUNC_FUNCTION_NAME(TYPE); \
        var->ec_memory_ref_back = ec_memory_new;            \
        var->ec_memory_lock = EC_LOCK;                      \
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
    EC_VAR_FREE_VAR_FUNCTION(TYPE)  \
    EC_VAR_FREE_FUNC_FUNCTION(TYPE)  \
    EC_UNLOCK_FUNCTION(TYPE)        \
    EC_VAR_NEW_FUNCTION(TYPE)       \
    EC_VAR_COPY_FUNCTION(TYPE)      \
    EC_VAR_COPY2_FUNCTION(TYPE)

#endif // EC_VAR_H
