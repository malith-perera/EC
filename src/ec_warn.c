#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_warn.h"


void
EC_Warn_Print_Msg (char *msg, char *result)
{
    printf ("%-50s %s\n", msg, result);
}


void
EC_Warn_Print_Adr (char *msg, void *adr)
{
    printf ("%-50s %p\n", msg, adr);
}
