#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_error.h"


void
EC_Warn_Print_Msg (char *msg, char *result)
{
    setTextColor(stdout, EC_YELLOW);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Print_Warn (char *msg, void *adrs)
{
    setTextColor(stdout, EC_YELLOW);
    printf ("%-40s %p\n", msg, adrs);
    printf("\033[0m");
}
