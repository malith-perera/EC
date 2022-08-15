#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_test.h"


void
EC_Test_Print_Title (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_BLUE);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Test_Print_Msg (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Test_Print_Adr (char *msg, void *adr)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %p\n", msg, adr);
    printf("\033[0m");
}
