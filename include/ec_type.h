#ifndef EC_TYPE_H
#define EC_TYPE_H

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


void
EC_Type_Get(ECType type);

#endif // EC_TYPE_H
