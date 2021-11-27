#ifndef EC_MEMORY_H
#define EC_MEMORY_H

#include "ec.h"

typedef struct ECMemory {
    ECType              type;
    void*               var;
    void*               memory;
    void                (*Free_Func) (void*);
    bool                lock;
    struct ECMemory*    next;
} ECMemory;

ECMemory* ec_memory;

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
