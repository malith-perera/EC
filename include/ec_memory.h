#include "ec.h"


#ifndef EC_MEMORY_H
#define EC_MEMORY_H


/* ECMemoryLock types */
typedef enum {
    EC_UNLOCK,      /* permit to free existing ec_memory and ec variables */
    EC_LOCK,        /* lock both ec memory and ec variables */
    EC_MEM_LOCK     /* ec variable freed out but ec memory locked */
} ECMemoryLock;


/* EC_Memory to track memory */
typedef struct ECMemory {                                           
    char                *file;
    int                 line;
    char                *func;
    ECType              type;                                   
    void                *var;
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
#define EC_MEMORY_REF
#endif //EC_MEMORY


/* List of all allocated ec_memory */
static ECMemory *ec_memory;

#ifdef EC_MEMORY

#define EC_MEMORY_CREATE(ec_memory_new, ec_type, ec_var)            /* ec_type -> ECType ... ec_var -> assigning ec_variable to ec_memory_new */\
        ECMemory *ec_memory_new = EC_Memory_Create (ec_type);       \
        EC_ERROR_MEM_ALLOC(ec_memory_new, __FILE__, __LINE__)       /* when memory allocation failed */\
        ec_memory_new->var = ec_var;                                \
        ec_var->ec_mem = ec_memory_new;

#else

#define EC_MEMORY_CREATE(ec_memory_new, ec_var)

#endif // EC_MEMORY


ECMemory *
EC_Memory_Create(ECType ec_type);


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


#endif // EC_MEMORY_H
