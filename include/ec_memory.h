#ifndef EC_MEMORY_H
#define EC_MEMORY_H

#include "ec.h"

typedef struct ECMemory {
    ECType              type;
    void*               var;
    void*               memory;
    void                (*Free_Func) (void*);
    struct ECMemory*    next;
} ECMemory;

#ifdef EC_MEMORY
#define EC_MEMORY_REF     \
    ECMemory* mem_ref;    \
    bool lock;
#else
#define EC_MEMORY_REF
#endif //EC_MEMORY

ECMemory* ec_memory;

//ECMemoryList* ec_memory_list;

void
EC_Clean ();


#define ec_unlock(EC_VAR)       \
    EC_VAR->lock = false;       \
    EC_VAR->mem-lock = false;


#define ec_arrary_free(EC_VAR)      \
    free(EC_VAR->index);


#define ec_memory_free(EC_VAR)                              \
    EC_VAR->mem_ref->previous = EC_VAR->mem_ref->next;      \
    free(EC_VAR->mem_ref);                                  \
    free(EC_VAR);


#endif // EC_MEMORY_H
