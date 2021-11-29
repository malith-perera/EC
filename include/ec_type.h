#ifndef EC_TYPE_H
#define EC_TYPE_H

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
