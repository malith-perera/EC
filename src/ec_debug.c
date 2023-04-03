#include "ec_debug.h"


void
EC_Debug_Print_Adr (char *msg, void *adr)
{
    printf ("%-*s %p\n", EC_MSG_WIDTH, msg, adr);
}
