#ifndef EC_MEMORY_H
#define EC_MEMORY_H

#include "ec.h"

/* ECMemoryLock types */
typedef enum {
    EC_UNLOCK,
    EC_LOCK,
    EC_NONE_LOCK
} ECMemoryLock;


/* EC_Memory to track memory */
typedef struct ECMemory {
    ECType              type;
    void*               var;
    ECMemoryLock        lock;
    void                (*Free_Func) (void*);
    void                (*Free_Var_Func) (void*);
    struct ECMemory*    previous;
    struct ECMemory*    next;
} ECMemory;


/* Define lock and mem_ref */
#ifdef EC_MEMORY
#define EC_MEMORY_REF           \
    ECMemory* ec_memory_ref;    \
    bool lock;
#else
#define EC_MEMORY_REF
#endif //EC_MEMORY


/* List of all allocated ec_memory */
ECMemory* ec_memory;


#define EC_MEMORY_CREATE                                                \
    ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));    \
                                                                        \
    if (ec_memory_new == NULL)                                          \
    {                                                                   \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                        \
        return NULL;                                                    \
    }


/* Clean all remaining ec_memory at the end of the program */
void
EC_Clean ();


/* Append to ec_memory */
void
EC_Memory_Append (ECMemory* ec_memory_new);


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


#define ec_memory_free(EC_VAR)                              \
    EC_VAR->ec_memory_ref->previous = EC_VAR->ec_memory_ref->next;      \
    free(EC_VAR->ec_memory_ref);                                  \
    free(EC_VAR);


#endif // EC_MEMORY_H
