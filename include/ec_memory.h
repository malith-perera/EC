#ifndef EC_MEMORY_H
#define EC_MEMORY_H

#include <stdbool.h>
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
#define EC_MEMORY_REF     \
    ECMemory* mem_ref;    \
    bool lock;
#else
#define EC_MEMORY_REF
#endif //EC_MEMORY

void
EC_Clean ();

#endif // EC_MEMORY_H
