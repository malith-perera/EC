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

ECMemory* ec_memory;
ECMemory* ec_garbage;

#ifdef EC_MEMORY
#define EC_MEMORY_LOCK      \
    ECMemory* mem_ref;      \
    bool lock;
#endif //EC_MEMORY

#ifndef EC_MEMORY
#define EC_MEMORY_LOCK
#endif //EC_MEMORY

void
EC_Clean ();

#endif // EC_MEMORY_H
