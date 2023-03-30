#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_test.h"

void
EC_Test_Print_Title (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_BLUE);
    printf ("%-50s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Test_Print_Subtitle (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_CYAN);
    printf ("%-50s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Test_Print_End_Subtitle (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_BROWN);
    printf ("%-50s %s\n", msg, result);
    printf("\033[0m");
}



void
EC_Test_Print_Msg (char *msg, char *result)
{
    printf ("%-50s ", msg);
    EC_Set_Text_Color(stdout, EC_LIGHTGREEN);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Test_Print_Msg_Error(char *msg, char *result)
{
    printf ("%-50s ", msg);
    EC_Set_Text_Color(stdout, EC_RED);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Test_Print_Adr (char *msg, void *adr)
{
    printf ("%-50s %p\n", msg, adr);
}
