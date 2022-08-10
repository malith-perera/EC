#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_error.h"


/*printf("%s", getName(myVar));*/
/*#define getName(var, str)  sprintf(str, "%s", #var)*/
/*char str[20];*/
/*getName(myVar, str);*/
/*printf("%s", str)*/


void
EC_Warn_Print_Msg (char *msg, char *result)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %s\n", msg, result);
    printf("\033[0m");
}


void
EC_Print_Warn (char *msg, void *adrs)
{
    EC_Set_Text_Color(stdout, EC_YELLOW);
    printf ("%-40s %p\n", msg, adrs);
    printf("\033[0m");
}


/*void*/
/*EC_Warn_List_Var_Not_Exist (ec_var_name)*/
/*{*/
    /*EC_Set_Text_Color(stdout, EC_YELLOW);*/
    /*printf ("Warning : ", msg, result);*/
    /*printf ("\033[0m");*/
    /*printf ("EC list variable %s not exist\n", EC_GET_NAME (ec_var_name));*/
/*}*/
