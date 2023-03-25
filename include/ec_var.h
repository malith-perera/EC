#include "ec.h"
#define EC_VAR_DEBUG 1

#ifndef EC_VAR_H
#define EC_VAR_H

/* Function name macros */
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Var)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Free)
#define EC_VAR_CLONE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Var_Clone)
#define EC_VAR_COPY_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Copy)

/*------------*/
/* Structures */
/*------------*/


#define EC_VAR(TYPE, VAR)                       \
    typedef struct TYPE {                       \
        VAR                                     \
        EC_MEMORY_REF                           \
    } TYPE;                                     \
                                                \
    typedef struct TYPE EC_CONCAT(TYPE, Var);   /* optional StudentVar for Student */


/*---------*/
/* EC Free */
/*---------*/

#ifdef EC_MEMORY

#define EC_Free(var)                            \
    var->ec_mem->lock = EC_UNLOCK;              \
    free(var)

#define EC_Free_Mem(var)                        \
    var->ec_mem->lock = EC_UNLOCK;              \
    free(var)

#else // EC_MEMORY not defined  

#define EC_Free(var)                            \
    free(var)

#define EC_Free_Mem(var)                        \
    free(var)

#endif  // EC_MEMORY 


/* Function Prototypes */
#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void *var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
TYPE *                                          \
EC_VAR_NEW_FUNCTION_NAME(TYPE)(void);


#define EC_VAR_CLONE_FUNCTION_PROTOTYPE(TYPE)   \
TYPE *                                          \
EC_VAR_CLONE_FUNCTION_NAME(TYPE)                \
(                                               \
    TYPE *var                                   \
);


#define EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                 \
(                                               \
    TYPE *var_copy,                             \
    TYPE *var                                   \
);

/* Macro created functions */

#define EC_VAR_FREE_FUNCTION(TYPE)             \
void                                           \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                \
(                                              \
    void *var                                  \
)                                              \
{                                              \
    TYPE *v = (TYPE *) var;                    \
    EC_DEBUG_PRINT_ADR("ec var free", v);      \
    free (v);                                  \
    v = NULL;                                  \
}


/* Create memory for any variable type ex: var, arry, list, list var */
#define EC_VAR_CREATE(TYPE, var)                            \
    TYPE *var = (TYPE *) malloc (sizeof(TYPE));             \
    EC_ERROR_MEM_ALLOC(var, __FILE__, __LINE__)             /* when memory allocation failed */\
    EC_DEBUG_PRINT_ADR("Create: ec var", var);              /* only when EC_DEBUG */



#define EC_VAR_NEW_FUNCTION(TYPE)                                       \
TYPE *                                                                  \
EC_VAR_NEW_FUNCTION_NAME(TYPE)(void)                                    \
{                                                                       \
    EC_VAR_CREATE(TYPE, var)                                            /* var is created variable */\
                                                                        \
    EC_MEMORY_CREATE(ec_memory_new, EC_TYPE_VAR, var)                   \
                                                                        \
    ec_memory_new->Free_Func = EC_VAR_FREE_FUNCTION_NAME(TYPE);         \
                                                                        \
    return var;                                                         \
}


/*printf ("create var %p\n", var_copy);                              \*/
/*printf ("create mem %p\n", var_clone->ec_mem);                      \*/
// Clone variable var to var_clone
#define EC_VAR_CLONE_FUNCTION(TYPE)                         \
TYPE *                                                      \
EC_VAR_CLONE_FUNCTION_NAME(TYPE)                            \
(                                                           \
    TYPE *var                                               \
)                                                           \
{                                                           \
    TYPE *var_clone = EC_VAR_NEW_FUNCTION_NAME(TYPE)();     \
    memcpy (var_clone, var, sizeof(TYPE));                  \
    return var_clone;                                       \
}


#define EC_VAR_COPY_FUNCTION(TYPE)                          \
void                                                        \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                             \
(                                                           \
    TYPE *var_copy,                                         \
    TYPE *var                                               \
)                                                           \
{                                                           \
    *var_copy = *var;                                       \
}


/* All function prototypes */
#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)    \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
    EC_VAR_CLONE_FUNCTION_PROTOTYPE(TYPE)   \
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)


/* All functions */
#define EC_VAR_FUNCTIONS(TYPE)         \
    EC_VAR_FREE_FUNCTION(TYPE)         \
    EC_VAR_NEW_FUNCTION(TYPE)          \
    EC_VAR_CLONE_FUNCTION(TYPE)        \
    EC_VAR_COPY_FUNCTION(TYPE)


#endif // EC_VAR_H






















#if 0


/* Function name macros */

/* EC_VAR_FREE_ALL_FUNCTION deletes only it's variable.
 * EC_VAR_FREE_FUNCTION deletes total variable and memory */
#define EC_VAR_FREE_ALL_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _Var_Free_All)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Var_Free)
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Var)
#define EC_UNLOCK_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Var_Unlock)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h

#define EC_VAR_STRUCT(TYPE)                 EC_CONCAT(TYPE, Var)

#ifndef EC_VAR
#define EC_VAR(TYPE, VAR)                       /* VAR should define and pass by user as a macro */\
typedef struct TYPE {                           \
    VAR                                         \
    EC_MEMORY_REF                               \
} TYPE;                                         \
                                                \
typedef TYPE EC_VAR_STRUCT(TYPE);
#endif // EC_VAR


/* Function prototype macros */
#define EC_VAR_FREE_ALL_FUNCTION_PROTOTYPE(TYPE)\
void                                            \
EC_VAR_FREE_ALL_FUNCTION_NAME(TYPE)             \
(                                               \
    void *var                                   \
);


#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void *var                                   \
);


#define EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)      \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void *var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
TYPE *                                          \
EC_VAR_NEW_FUNCTION_NAME(TYPE)();






#define EC_VAR_FUNCTION_PROTOTYPES(TYPE)        \
    EC_VAR_FREE_ALL_FUNCTION_PROTOTYPE(TYPE)    \
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)        \
    EC_UNLOCK_FUNCTION_PROTOTYPE(TYPE)          \
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)         \


/* Function macros */
/* free var and unlock ec_memory */
#define EC_VAR_FREE_FUNCTION(TYPE)              \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE *) var;                     \
    if (DEBUG) EC_Test_Print_Adr ("ec var free", v);   \
    EC_Memory_Var_Free (v->ec_mem);             \
    free (v);                                   \
    v = NULL;                                   \
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
        if (mem->ec_var != NULL)                \
        {                                       \
            free (mem->ec_var);                 \
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
    TYPE *v = (TYPE *) var;                     \
    v->ec_mem->lock = EC_UNLOCK;                \
}


#define EC_VAR_FUNCTIONS(TYPE)      \
    EC_VAR_FREE_ALL_FUNCTION(TYPE)  \
    EC_VAR_FREE_FUNCTION(TYPE)      \
    EC_UNLOCK_FUNCTION(TYPE)        \
    EC_VAR_NEW_FUNCTION(TYPE)       \


#endif
