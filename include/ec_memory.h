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

void
EC_Clean ();

#endif // EC_MEMORY_H
