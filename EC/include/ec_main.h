#ifndef EC_MAIN_H
#undef EC_MAIN_H

typedef enum {
    EC_OBJECT_TYPE,
    EC_ARRAY_TYPE,
    EC_LIST_TYPE,
    EC_LIST_OBJECT_TYPE,
    EC_QUEUE_TYPE
} ECType;

typedef struct ECWorld {
    ECType          type;
    void*           obj;
    void*           garbage;
    void            (*Free_List) (void*);
    struct ECWorld* next;
} ECWorld;

#endif // EC_MAIN_H
