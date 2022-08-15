#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_warn.h"


void
EC_Warn_Print_Msg (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Warn_Print_Adr (char *msg, void *adr)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %p\n", msg, adr);
    printf("\033[0m");
}
