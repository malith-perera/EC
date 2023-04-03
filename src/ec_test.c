#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_test.h"

void
EC_Test_Print_Title (const char *msg)
{
    EC_Set_Text_Color(stdout, EC_CYAN);
    printf ("%-*s\n", EC_MSG_WIDTH, msg);
    printf("\033[0m");
}


void
EC_Test_Print_Subtitle (char *msg)
{
    EC_Set_Text_Color(stdout, EC_LIGHTMAGENTA);
    printf ("%-*s\n", EC_MSG_WIDTH, msg);
    printf("\033[0m");
}


void
EC_Test_Print_Msg (char *msg, char *result, int line)
{
    printf ("%-7d: %-*s ", line, EC_MSG_WIDTH, msg);
    EC_Set_Text_Color(stdout, EC_LIGHTGREEN);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Test_Print_Msg_Error(char *msg, char *result)
{
    printf ("%-*s ", EC_MSG_WIDTH, msg);
    EC_Set_Text_Color(stdout, EC_RED);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Test_Print_Adr (char *msg, void *adr)
{
    printf ("%-*s %p\n", EC_MSG_WIDTH, msg, adr);
}


void
EC_Test_Print_Header (char *msg)
{
    int  len = strlen(msg);
    char buf[2048];

    sprintf(buf, "%0*d", len, 0);
    EC_Char_Substitute (buf, '0', '-');
    printf("%s\n", buf);

    printf ("%s\n", msg);

    sprintf(buf, "%0*d", len, 0);
    EC_Char_Substitute (buf, '0', '=');
    printf("%s\n", buf);

}
