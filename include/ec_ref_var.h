#ifndef EC_REF_VAR_H
#define EC_REF_VAR_H

#include "ec.h"

/* Function name macros */
#define EC_REF_VAR_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Ref_Free_var,)
#define EC_REF_VAR_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Ref_Var,)
#define EC_REF_VAR_COPY_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Ref_Var_Copy,)

#define EC_REF_VAR_UNLOCK_FUNCTION_NAME(TYPE)       EC_CONCAT(TYPE, _Ref_Unlock,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h

#define EC_REF_VAR_STRUCT(TYPE)                 EC_CONCAT(TYPE, RefVar,)

#ifndef EC_REF_VAR
#define EC_REF_VAR(TYPE)                            \
typedef struct EC_REF_VAR_STRUCT(TYPE) {            \
    TYPE* ref;                                      \
    EC_MEMORY_REF                                   \
} EC_REF_VAR_STRUCT(TYPE);
#endif // EC_REF_VAR

/* Function prototype macros */

#define EC_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                                \
EC_REF_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                                   \
    void* var                                       \
);


#define EC_REF_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
EC_REF_VAR_STRUCT(TYPE)*                            \
EC_REF_VAR_NEW_FUNCTION_NAME(TYPE)                  \
();


#define EC_REF_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)    \
EC_REF_VAR_STRUCT(TYPE)*                            \
EC_REF_VAR_COPY_FUNCTION_NAME(TYPE)                 \
(                                                   \
    EC_REF_VAR_STRUCT(TYPE)* var                    \
);

#define EC_REF_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_REF_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \
    EC_REF_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_REF_VAR_FREE_FUNCTION(TYPE)      \
void                                        \
EC_REF_VAR_FREE_FUNCTION_NAME(TYPE)         \
(                                           \
    void* var                               \
)                                           \
{                                           \
    TYPE* v = (TYPE*) var;                  \
    free (v);                               \
    v = NULL;                               \
}


#define EC_REF_VAR_NEW_FUNCTION(TYPE)                                       \
EC_REF_VAR_STRUCT(TYPE)*                                                    \
EC_REF_VAR_NEW_FUNCTION_NAME(TYPE)()                                        \
{                                                                           \
    EC_REF_VAR_STRUCT(TYPE)* var = (EC_REF_VAR_STRUCT(TYPE)*)               \
        malloc (sizeof(EC_REF_VAR_STRUCT(TYPE)));                           \
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
        ec_memory_new->Free_Func = EC_REF_VAR_FREE_FUNCTION_NAME (TYPE);    \
        ec_memory_new->next = NULL;                                         \
                                                                            \
        EC_Memory_Append (ec_memory_new);                                   \
                                                                            \
        var->ec_memory_ref = ec_memory_new;                                 \
        var->lock = EC_LOCK;                                                \
    }                                                                       \
                                                                            \
    return var;                                                             \
}


// Copy variable b to a
#define EC_REF_VAR_COPY_FUNCTION(TYPE)                                          \
EC_REF_VAR_STRUCT(TYPE)*                                                        \
EC_REF_VAR_COPY_FUNCTION_NAME(TYPE)                                             \
(                                                                               \
    EC_REF_VAR_STRUCT(TYPE)* var                                                \
)                                                                               \
{                                                                               \
    EC_REF_VAR_STRUCT(TYPE)* new_var = EC_REF_VAR_NEW_FUNCTION_NAME(TYPE)();    \
    *new_var = *var;                                                            \
                                                                                \
    return new_var;                                                             \
}


#define EC_REF_VAR_FUNCTIONS(TYPE)  \
    EC_REF_VAR_FREE_FUNCTION(TYPE)  \
    EC_REF_VAR_NEW_FUNCTION(TYPE)   \
    EC_REF_VAR_COPY_FUNCTION(TYPE)

#endif // EC_REF_VAR_H
