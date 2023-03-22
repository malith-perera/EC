#include "ec.h"


#ifndef EC_DEBUG_H
#define EC_DEBUG_H


void
EC_Debug_Print_Adr (char *msg, void *adr);


#ifdef EC_DEBUG
#define EC_DEBUG_PRINT_ADR(info, ec_memory) EC_Debug_Print_Adr (info, ec_memory)
#else
#define EC_DEBUG_PRINT_ADR(info, ec_memory)
#endif


#endif // EC_DEBUG_H
