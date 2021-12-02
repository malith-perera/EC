#ifndef EC_QUEUE_H
#define EC_QUEUE_H

#include "ec.h"

#define foreach_queue(queue)                                                        \
  for (queue->var = queue->first;  queue->var != NULL; queue->var = queue->var->next)


#define EC_QUEUE_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Queue_Free,) // memory Free
#define EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)       EC_CONCAT(TYPE, _Queue_Var_Free,)
#define EC_QUEUE_NEW_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Queue,)
#define EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Queue_Var,)
#define EC_QUEUE_COPY_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Queue_Copy,)

#define EC_QUEUE_FOREACH(TYPE)                      EC_CONCAT(Foreach_, TYPE,)
#define EC_QUEUE_DROP_FUNCTION_NAME(TYPE)           EC_CONCAT(Drop_, TYPE,)
#define EC_QUEUE_FREE_VAR_FUNCTION_NAME(TYPE)       EC_CONCAT(Free_, TYPE,_Queue_Var)
#define EC_QUEUE_FREE_QUEUE_FUNCTION_NAME(TYPE)     EC_CONCAT(Free_, TYPE, _Queue)
#define EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Enqueue,)
#define EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Dequeue,)
#define EC_QUEUE_FRONT_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Front,)


/* Structure macros */
// defined in ec_memory.h
#define EC_QUEUE_STRUCT(TYPE)                       EC_CONCAT(TYPE, Queue,)
#define EC_QUEUE_VAR_STRUCT(TYPE)                   EC_CONCAT(TYPE, QueueVar,)


#define EC_QUEUE(TYPE, VAR)                         \
typedef struct EC_QUEUE_VAR_STRUCT(TYPE){           \
    VAR;                                            \
    struct EC_QUEUE_VAR_STRUCT(TYPE)* next;         \
} EC_QUEUE_VAR_STRUCT(TYPE);                        \
                                                    \
                                                    \
typedef struct EC_QUEUE_STRUCT(TYPE){               \
    EC_QUEUE_VAR_STRUCT(TYPE)* first;               \
    EC_QUEUE_VAR_STRUCT(TYPE)* last;                \
    EC_QUEUE_VAR_STRUCT(TYPE)* var;                 \
    EC_MEMORY_REF                                   \
} EC_QUEUE_STRUCT(TYPE);


/* Function prototype macros */
#define EC_QUEUE_FREE_FUNCTION_PROTOTYPE(TYPE)                  \
void                                                            \
EC_QUEUE_FREE_FUNCTION_NAME(TYPE)                               \
(                                                               \
    void* var                                                   \
);


#define EC_QUEUE_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)              \
void                                                            \
EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)                           \
(                                                               \
    void* var                                                   \
);


#define EC_QUEUE_NEW_FUNCTION_PROTOTYPE(TYPE)                   \
EC_QUEUE_STRUCT(TYPE)*                                          \
EC_QUEUE_NEW_FUNCTION_NAME(TYPE)                                \
();



#define EC_QUEUE_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)               \
EC_QUEUE_VAR_STRUCT (TYPE)*                                     \
EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)                            \
();


#define EC_QUEUE_ENQUEUE_FUNCTION_PROTOTYPE(TYPE)               \
void                                                            \
EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)                            \
(                                                               \
    EC_QUEUE_STRUCT(TYPE)* queue,                               \
    EC_QUEUE_VAR_STRUCT(TYPE)* var                              \
);


#define EC_QUEUE_DEQUEUE_FUNCTION_PROTOTYPE(TYPE)           \
EC_QUEUE_VAR_STRUCT(TYPE)*                                  \
EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)* queue                            \
);


#define EC_QUEUE_COPY_FUNCTION_PROTOTYPE(TYPE)              \
EC_QUEUE_STRUCT(TYPE)*                                      \
EC_QUEUE_COPY_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)* queue                            \
);


#define EC_QUEUE_FUNCTION_PROTOTYPES(TYPE)                      \
    EC_QUEUE_FREE_FUNCTION_PROTOTYPE(TYPE)                      \
    EC_QUEUE_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)                  \
    EC_QUEUE_NEW_FUNCTION_PROTOTYPE(TYPE)                       \
    EC_QUEUE_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)                   \
    EC_QUEUE_ENQUEUE_FUNCTION_PROTOTYPE(TYPE)                   \
    EC_QUEUE_DEQUEUE_FUNCTION_PROTOTYPE(TYPE)                   \
    EC_QUEUE_COPY_FUNCTION_PROTOTYPE(TYPE)

/* Function macros */


#define EC_QUEUE_FREE_FUNCTION(TYPE)                            \
void                                                            \
EC_QUEUE_FREE_FUNCTION_NAME(TYPE)                               \
(                                                               \
    void* var                                                   \
)                                                               \
{                                                               \
    EC_QUEUE_STRUCT(TYPE)* p = (EC_QUEUE_STRUCT(TYPE)*) var;    \
    free (p);                                                   \
}


#define EC_QUEUE_VAR_FREE_FUNCTION(TYPE)                        \
void                                                            \
EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)                           \
(                                                               \
    void* var                                                   \
)                                                               \
{                                                               \
    TYPE* p = (TYPE*) var;                                      \
    free (p);                                                   \
}


#define EC_QUEUE_NEW_FUNCTION(TYPE)                                                                         \
EC_QUEUE_STRUCT(TYPE)*                                                                                      \
EC_QUEUE_NEW_FUNCTION_NAME(TYPE)                                                                            \
()                                                                                                          \
{                                                                                                           \
    EC_QUEUE_STRUCT(TYPE)* var = (EC_QUEUE_STRUCT(TYPE)*) malloc (sizeof (EC_QUEUE_STRUCT(TYPE)));          \
                                                                                                            \
    if (var == NULL)                                                                                        \
    {                                                                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                            \
        return NULL;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    var->first = NULL;                                                                                      \
    var->last = NULL;                                                                                       \
                                                                                                            \
    if (EC_MEMORY)                                                                                          \
    {                                                                                                       \
        ECMemory *ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                                    \
                                                                                                            \
        if (ec_memory_new == NULL)                                                                          \
        {                                                                                                   \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                        \
            return NULL;                                                                                    \
        }                                                                                                   \
                                                                                                            \
        ec_memory_new->type = EC_QUEUE_TYPE;                                                                \
        ec_memory_new->var = var;                                                                           \
        ec_memory_new->lock = EC_LOCK;                                                                      \
        ec_memory_new->Free_Func = EC_QUEUE_FREE_FUNCTION_NAME (TYPE);                                      \
        ec_memory_new->Free_Var_Func = EC_QUEUE_VAR_FREE_FUNCTION_NAME (TYPE);                              \
        ec_memory_new->next = NULL;                                                                         \
                                                                                                            \
        EC_Memory_Append (ec_memory_new);                                                                   \
                                                                                                            \
        var->ec_memory_ref = ec_memory_new;                                                                 \
        var->lock = EC_LOCK;                                                                                \
    }                                                                                                       \
                                                                                                            \
    return var;                                                                                             \
}


/* New Queue Variable Function */

#define EC_QUEUE_NEW_VAR_FUNCTION(TYPE)                                                                             \
EC_QUEUE_VAR_STRUCT(TYPE)*                                                                                          \
EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)                                                                                \
()                                                                                                                  \
{                                                                                                                   \
    EC_QUEUE_VAR_STRUCT(TYPE)* var = (EC_QUEUE_VAR_STRUCT(TYPE)*) malloc (sizeof (EC_QUEUE_VAR_STRUCT(TYPE)));      \
                                                                                                                    \
    if (var == NULL)                                                                                                \
    {                                                                                                               \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                                    \
        return NULL;                                                                                                \
    }                                                                                                               \
                                                                                                                    \
    if (EC_MEMORY)                                                                                                  \
    {                                                                                                               \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));                                           \
                                                                                                                    \
        if (ec_memory_new == NULL)                                                                                  \
        {                                                                                                           \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                                \
            return NULL;                                                                                            \
        }                                                                                                           \
                                                                                                                    \
        ec_memory_new->type = EC_QUEUE_VAR_TYPE;                                                                    \
        ec_memory_new->var = var;                                                                                   \
        ec_memory_new->lock = EC_NONE_LOCK;                                                                         \
        ec_memory_new->Free_Func = EC_QUEUE_VAR_FREE_FUNCTION_NAME (TYPE);                                          \
        ec_memory_new->next = NULL;                                                                                 \
                                                                                                                    \
        EC_Memory_Append (ec_memory_new);                                                                           \
    }                                                                                                               \
                                                                                                                    \
    return var;                                                                                                     \
}


/* Queue Functions */

#define EC_QUEUE_ENQUEUE_FUNCTION(TYPE)         \
void                                            \
EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)            \
(                                               \
    EC_QUEUE_STRUCT(TYPE)* queue,               \
    EC_QUEUE_VAR_STRUCT(TYPE)* var              \
)                                               \
{                                               \
    var->next = NULL;                           \
                                                \
    if (queue->first != NULL)                   \
    {                                           \
        queue->last->next = var;                \
        queue->last = var;                      \
    }                                           \
    else                                        /* no vars in queue */ \
    {                                           \
        queue->first = var;                     \
        queue->last = var;                      \
    }                                           \
}


#define EC_QUEUE_DEQUEUE_FUNCTION(TYPE)                     \
EC_QUEUE_VAR_STRUCT(TYPE)*                                  \
EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)* queue                            \
)                                                           \
{                                                           \
    EC_QUEUE_VAR_STRUCT(TYPE)* queued_var = NULL;           \
                                                            \
    if (queue->first != NULL)                               \
    {                                                       \
        queued_var = queue->first;                          \
        queue->first = queue->first->next;                  \
        if (queue->first == NULL) queue->last = NULL;       \
                                                            \
        return queued_var;                                  \
        /* should do something to free var after use */     \
    }                                                       \
    else                                                    \
    {                                                       \
        return NULL;                                        \
    }                                                       \
}


#define EC_QUEUE_FRONT_FUNCTION(TYPE)                       \
EC_QUEUE_VAR_STRUCT (TYPE)*                                 \
EC_QUEUE_FRONT_FUNCTION_NAME(TYPE)                          \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)* queue                            \
)                                                           \
{                                                           \
    return queue->first;                                    \
}


/* Queue Free Variable Function */

#define EC_QUEUE_FREE_VAR_FUNCTION(TYPE)                    \
void                                                        \
EC_QUEUE_FREE_VAR_FUNCTION_NAME(TYPE)                       \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)* queue,                           \
    EC_QUEUE_VAR_STRUCT(TYPE)* var                          \
)                                                           \
{                                                           \
    /*EC_QUEUE_DROP_FUNCTION_NAME(TYPE) (queue, var);*/     \
    free (var);                                             \
}


// Copy queue
#define EC_QUEUE_COPY_FUNCTION(TYPE)                                \
EC_QUEUE_STRUCT(TYPE)*                                              \
EC_QUEUE_COPY_FUNCTION_NAME(TYPE)                                   \
(                                                                   \
    EC_QUEUE_STRUCT(TYPE)* queue                                    \
)                                                                   \
{                                                                   \
    EC_QUEUE_STRUCT(TYPE)* queue_copy = (EC_QUEUE_STRUCT(TYPE)*)    \
        malloc (sizeof(EC_QUEUE_STRUCT(TYPE)));                     \
                                                                    \
    EC_QUEUE_VAR_STRUCT(TYPE)* var;                                 \
                                                                    \
    foreach_queue(queue)                                            \
    {                                                               \
        var = EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)();               \
        var = queue->var;                                           \
        EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)(queue_copy, var);      \
    }                                                               \
                                                                    \
    return queue_copy;                                              \
}


#define EC_QUEUE_FUNCTIONS(TYPE)        \
    EC_QUEUE_FREE_FUNCTION(TYPE)        \
    EC_QUEUE_VAR_FREE_FUNCTION(TYPE)    \
    EC_QUEUE_NEW_FUNCTION(TYPE)         \
    EC_QUEUE_NEW_VAR_FUNCTION(TYPE)     \
    EC_QUEUE_ENQUEUE_FUNCTION(TYPE)     \
    EC_QUEUE_DEQUEUE_FUNCTION(TYPE)     \
    EC_QUEUE_COPY_FUNCTION(TYPE)

#endif // EC_QUEUE_H
