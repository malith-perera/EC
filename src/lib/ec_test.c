#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_test.h"


void
EC_Test_Print_Header (char *txt)
{
    int  len = strlen(txt);
    char buf[2048];

    sprintf(buf, "%0*d", len, 0);
    EC_Char_Substitute (buf, '0', '-');
    printf("%s\n", buf);

    printf ("%s\n", txt);

    sprintf(buf, "%0*d", len, 0);
    EC_Char_Substitute (buf, '0', '=');
    printf("%s\n", buf);

}


void
EC_Test_Print_Title (const char *func, const char *file)
{
    EC_Set_Text_Color(stdout, EC_CYAN);
    printf ("Func: %-*s\n", EC_MSG_WIDTH, func);
    printf ("File: %s\n", file);
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
EC_Test(char *test_number_text)
{
    char command[16];

    printf("%s\n", test_number_text);

    if (atoi(test_number_text) != 0 || strcmp(test_number_text, "0") == 0)
    {
        sprintf(command, "./test %s", test_number_text);

        if (system(command) == 0)
        {
            printf("Test: PASS\n");
        }
        else
        {
            printf("Test: FAIL\n");
        }
    }
    else
    {
        printf("\n");
        EC_Test_Help();
    }
}

void
EC_Test_Help()
{
    printf("Use:\n");
    printf("ec test                Test All\n");
    printf("ec test test_number    Test selected test\n");
}
