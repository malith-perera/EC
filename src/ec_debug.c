#include "ec_debug.h"


void
EC_Debug_Print_Adr (char *msg, void *adr)
{
    printf ("%-50s %p\n", msg, adr);
}
