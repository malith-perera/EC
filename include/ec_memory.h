#ifndef EC_MEMORY_H
#define EC_MEMORY_H


#include "ec.h"

/* ECMemoryLock types */
typedef enum {
    EC_UNLOCK,      /* permit to free existing ec_memory and ec variables */
    EC_LOCK,        /* lock both ec memory and ec variables */
    EC_MEM_LOCK     /* ec variable freed out but ec memory locked */
} ECMemoryLock;


/* EC_Memory to track memory */
typedef struct ECMemory {
    ECType              type;
    void                *ec_var;
    ECMemoryLock        lock;
    void                (*Free_All) (void *);
    void                (*Free_Var_Func) (void *, void *);
    void                (*Free_Func) (void *);
    struct ECMemory     *previous;
    struct ECMemory     *next;
} ECMemory;


/* Define lock and mem_ref */
#ifdef EC_MEMORY
#define EC_MEMORY_REF       \
    ECMemory *ec_mem;
#else
#define EC_MEMORY_REF 0
#endif //EC_MEMORY


/* List of all allocated ec_memory */
ECMemory *ec_memory;


#define EC_MEMORY_CREATE(TYPE, ec_var_type, var)                        \
    ECMemory *ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));    \
    if (DEBUG) EC_Test_Print_Adr ("Create: ec memory ", ec_memory_new); \
                                                                        \
    if (ec_memory_new == NULL)                                          \
    {                                                                   \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                        \
        return NULL;                                                    \
    }                                                                   \
                                                                        \
    ec_memory_new->type = ec_var_type;                                  \
    ec_memory_new->ec_var = var;                                        /* var is from EC_VAR_CREATE */\
    ec_memory_new->lock = EC_LOCK;                                      \
    ec_memory_new->next = NULL;                                         \
                                                                        \
    EC_Memory_Push (ec_memory_new);


/* Clean all remaining ec_memory at the end of the program */
void
EC_Memory_Clean ();


void
EC_Memory_Var_Free (ECMemory *ec_mem);


/* Push to ec_memory */
void
EC_Memory_Push (ECMemory *ec_memory_new);


/* Delete memory if lock == EC_UNLOCK in ec_memory lock variable */
void
EC_Memory_Free_Unlock ();


/* Free ec_memory if lock == EC_UNLOCK but only one at a time */
void
EC_Memory_Free_Unlock_One ();


#define ec_unlock(EC_VAR)           \
    EC_VAR->lock = EC_UNLOCK;       \
    EC_VAR->mem-lock = EC_UNLOCK;


#define ec_arrary_free(EC_VAR)      \
    free(EC_VAR->index);


#define ec_memory_free(EC_VAR)                          \
    EC_VAR->ec_mem->previous = EC_VAR->ec_mem->next;    \
    free(EC_VAR->ec_mem);                               \
    free(EC_VAR);


#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func,)


#endif // EC_MEMORY_H
