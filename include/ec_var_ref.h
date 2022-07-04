#ifndef EC_VAR_REF_H
#define EC_VAR_REF_H

#include "ec.h"

/* Function name macros */
#define EC_VAR_REF_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Free_Var_Ref,)
#define EC_VAR_REF_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Var_Ref,)
#define EC_VAR_REF_COPY_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Ref_Copy,)

#define EC_VAR_REF_UNLOCK_FUNCTION_NAME(TYPE)       EC_CONCAT(TYPE, _Unlock_Ref,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h

#define EC_VAR_REF_STRUCT(TYPE)                     EC_CONCAT(TYPE, RefVar,)

#ifndef EC_VAR_REF
#define EC_VAR_REF(TYPE)                            \
typedef struct EC_VAR_REF_STRUCT(TYPE) {            \
    TYPE* ref;                                      \
    EC_MEMORY_REF                                   \
} EC_VAR_REF_STRUCT(TYPE);
#endif // EC_VAR_REF

/* Function prototype macros */

#define EC_VAR_REF_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                                \
EC_VAR_REF_FREE_FUNCTION_NAME(TYPE)                 \
(                                                   \
    void* var                                       \
);


#define EC_VAR_REF_NEW_FUNCTION_PROTOTYPE(TYPE)     \
EC_VAR_REF_STRUCT(TYPE)*                            \
EC_VAR_REF_NEW_FUNCTION_NAME(TYPE)                  \
();


#define EC_VAR_REF_COPY_FUNCTION_PROTOTYPE(TYPE)    \
EC_VAR_REF_STRUCT(TYPE)*                            \
EC_VAR_REF_COPY_FUNCTION_NAME(TYPE)                 \
(                                                   \
    EC_VAR_REF_STRUCT(TYPE)* var                    \
);


#define EC_VAR_REF_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_REF_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_VAR_REF_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_VAR_REF_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_VAR_REF_FREE_FUNCTION(TYPE)      \
void                                        \
EC_VAR_REF_FREE_FUNCTION_NAME(TYPE)         \
(                                           \
    void* var                               \
)                                           \
{                                           \
    TYPE* v = (TYPE*) var;                  \
    free (v);                               \
    v = NULL;                               \
}


#define EC_VAR_REF_NEW_FUNCTION(TYPE)                                       \
EC_VAR_REF_STRUCT(TYPE)*                                                    \
EC_VAR_REF_NEW_FUNCTION_NAME(TYPE)()                                        \
{                                                                           \
    EC_VAR_REF_STRUCT(TYPE)* var = (EC_VAR_REF_STRUCT(TYPE)*)               \
        malloc (sizeof(EC_VAR_REF_STRUCT(TYPE)));                           \
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
        ec_memory_new->Free_Func = EC_VAR_REF_FREE_FUNCTION_NAME (TYPE);\
        ec_memory_new->next = NULL;                                         \
                                                                            \
        EC_Memory_Push (ec_memory_new);                                     \
                                                                            \
        var->ec_mem = ec_memory_new;                                        \
        var->ec_mem->lock = EC_LOCK;                                        \
    }                                                                       \
                                                                            \
    return var;                                                             \
}


// Copy variable b to a
#define EC_VAR_REF_COPY_FUNCTION(TYPE)                                          \
EC_VAR_REF_STRUCT(TYPE)*                                                        \
EC_VAR_REF_COPY_FUNCTION_NAME(TYPE)                                             \
(                                                                               \
    EC_VAR_REF_STRUCT(TYPE)* var                                                \
)                                                                               \
{                                                                               \
    EC_VAR_REF_STRUCT(TYPE)* new_var = EC_VAR_REF_NEW_FUNCTION_NAME(TYPE)();    \
    *new_var = *var;                                                            \
                                                                                \
    return new_var;                                                             \
}


#define EC_VAR_REF_FUNCTIONS(TYPE)  \
    EC_VAR_REF_FREE_FUNCTION(TYPE)  \
    EC_VAR_REF_NEW_FUNCTION(TYPE)   \
    EC_VAR_REF_COPY_FUNCTION(TYPE)

#endif // EC_VAR_REF_H
