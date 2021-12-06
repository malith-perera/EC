#ifndef EC_TYPE_H
#define EC_TYPE_H

/* portability */
#include <stdint.h>
typedef int32_t i32;

i32*
ec_int(i32 val)
{
    i32* var =  (i32*) malloc (sizeof(i32));
    *var = val;

    return var;
}
/*i32* x = ec_int(6);*/


#define int32(VAR) \
    int32_t* VAR = (int32_t*) malloc (sizeof(int32_t))
/*int32(y);*/
/**y = 7;*/

/* EC defined types
 * Related with ec_type_name[] in ec_type.c
 * If you change anything here change it too */
typedef enum {
    EC_VAR_TYPE,
    EC_ARRAY_TYPE,
    EC_LIST_TYPE,
    EC_LIST_VAR_TYPE,
    EC_QUEUE_TYPE,
    EC_QUEUE_VAR_TYPE,
    EC_STACK_TYPE,
    EC_STACK_VAR_TYPE
} ECType;


/* Return ECVarType in string
 * ECType type defined in ec_type.h*/
char*
EC_Type_Get_Name (ECType type);

#endif // EC_TYPE_H
