#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_test.h"


void
EC_Test_Print_Title (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_BLUE);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m\n");
}


void
EC_Test_Print_Subtitle (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_CYAN);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Test_Print_End_Subtitle (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_BROWN);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m\n");
}



void
EC_Test_Print_Msg (char *msg, char *result)
{
    printf ("%-40s ", msg);
    EC_Set_Text_Color(stdout, EC_LIGHTGREEN);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Test_Print_Adr (char *msg, void *adr)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %p\n", msg, adr);
    printf("\033[0m");
}
