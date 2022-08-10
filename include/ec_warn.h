#ifndef EC_WARN_H
#define EC_WARN_H

#include "ec.h"

#define EC_GET_NAME(ec_var_name)  #ec_var_name

void
EC_Warn_Print_Msg (char *test, char *result);


void
EC_Print_Warn (char *msg, void *adrs);


#define EC_UNLOCK_FUNCTION(TYPE)                \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE *) var;                     \
    v->ec_mem->lock = EC_UNLOCK;                \
}


#define EC_Warn_List_Var_Not_Exist(ec_var_name, ec_list_name) \
    EC_Set_Text_Color(stdout, EC_LIGHTRED);     \
    printf ("Warning: ");                       \
    printf ("\033[0m");                         \
    printf ("list variable %s is not exist in %s\n list", EC_GET_NAME (ec_var_name), EC_GET_NAME (ec_list_name));


/*#define getName(var, str)  sprintf(str, "%s", #var)*/
/*char str[20];*/
/*getName(myVar, str);*/
/*printf("%s", str)*/


#endif // EC_WARN_H
