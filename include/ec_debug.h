#include "ec.h"


#ifndef EC_DEBUG_H
#define EC_DEBUG_H


void
EC_Debug_Print_Adr (char *msg, void *adr);

#define EC_DEBUG_PRINT_ADR(msg, adr, line)                        \
    printf ("%-7s> %-*s %p\n", "", EC_MSG_WIDTH, msg, adr);


#endif // EC_DEBUG_H
